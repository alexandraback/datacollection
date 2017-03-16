#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 100
#define MOD 1000000007
using namespace std;

pair<int, int> a[4];
int resp[MAX*10][3], best[MAX*10][3], cont;
map<pair<int, int>, int> dic[3];
set<pair<int, pair<int, int> > > q;

void solve(int k, pair<int, int> v[], int z){
    if(z == 0){
        int j, p, s;
        j = v[0].second == 1 ? v[0].first : (v[1].second == 1 ? v[1].first : v[2].first);
        p = v[0].second == 2 ? v[0].first : (v[1].second == 2 ? v[1].first : v[2].first);
        s = v[0].second == 3 ? v[0].first : (v[1].second == 3 ? v[1].first : v[2].first);
        if(!(dic[0][make_pair(j, p)]+1 > k || dic[1][make_pair(j, s)]+1 > k
           || dic[2][make_pair(p, s)]+1 > k) && q.find(make_pair(j, make_pair(p, s))) == q.end()){
            resp[cont][0] = j, resp[cont][1] = p, resp[cont][2] = s;
            cont++;
            dic[0][make_pair(j, p)]++;
            dic[1][make_pair(j, s)]++;
            dic[2][make_pair(p, s)]++;
            q.insert(make_pair(j, make_pair(p, s)));
           }
        return;
    }
    for(int i = 1; i <= a[z].first; i++){
        v[a[z].second-1].first = i;
        v[a[z].second-1].second = a[z].second;
        solve(k, v, z-1);
    }
    return;
}

void solve_2(int k, pair<int, int> v[], int z){
    if(z == 0){
        int j, p, s;
        j = v[0].second == 1 ? v[0].first : (v[1].second == 1 ? v[1].first : v[2].first);
        p = v[0].second == 2 ? v[0].first : (v[1].second == 2 ? v[1].first : v[2].first);
        s = v[0].second == 3 ? v[0].first : (v[1].second == 3 ? v[1].first : v[2].first);
        if(!(dic[0][make_pair(j, p)]+1 > k || dic[1][make_pair(j, s)]+1 > k
           || dic[2][make_pair(p, s)]+1 > k) && q.find(make_pair(j, make_pair(p, s))) == q.end()){
            resp[cont][0] = j, resp[cont][1] = p, resp[cont][2] = s;
            cont++;
        dic[0][make_pair(j, p)]++;
        dic[1][make_pair(j, s)]++;
        dic[2][make_pair(p, s)]++;
        q.insert(make_pair(j, make_pair(p, s)));
           }
        return;
    }
    int t[10];
    for(int j = 0; j < a[z].first; j++)
        t[j] = j+1;
    random_shuffle(t, t+a[z].first);
    for(int i = 0; i < a[z].first; i++){
        v[a[z].second-1].first = t[i];
        v[a[z].second-1].second = a[z].second;
        solve(k, v, z-1);
    }
    return;
}

void heuristic(int k){
    for(int i = 0; i < 10000; i++){
        int t[3];
        //cout << i << endl;
        for(int j = 0; j < 3; j++)
            t[j] = (rand()%a[j+1].first)+1;
        if(!(dic[0][make_pair(t[0], t[1])]+1 > k || dic[1][make_pair(t[0], t[2])]+1 > k
           || dic[2][make_pair(t[1], t[2])]+1 > k) && q.find(make_pair(t[0], make_pair(t[1], t[2]))) == q.end()){
            resp[cont][0] = t[0], resp[cont][1] = t[1], resp[cont][2] = t[2];
            cont++;
        dic[0][make_pair(t[0], t[1])]++;
        dic[1][make_pair(t[0], t[2])]++;
        dic[2][make_pair(t[1], t[2])]++;
        q.insert(make_pair(t[0], make_pair(t[1], t[2])));
           }
    }
//    cout << q.size() << endl;
}

int main(){
    int casos, n, k, mejor;
    cin >> casos;
    for(int i = 1; i <= casos; i++){
        cin >> a[1].first >> a[2].first >> a[3].first >> k;
        a[1].second = 1;
        a[2].second = 2;
        a[3].second = 3;
        printf("Case #%d:", i);
        pair<int, int> v[4];
        do{
            cont = 0;
            solve(k, v, 3);

            for(int j = 0; j < cont; j++){
                best[j][0] = resp[j][0];
                best[j][1] = resp[j][1];
                best[j][2] = resp[j][2];//*/
            }
            for(int j = 0; j < 3; j++)
                dic[j].clear();
            if(q.size() != cont){
                while(1);
            }
            q.clear();
            mejor = cont;
            for(int iter = 0; iter < 10; iter++){
                cont = 0;
                solve_2(k, v, 3);
//                printf(" %d\n", cont);
 /*           for(int j = 0; j < cont; j++)
                printf("%d %d %d\n", resp[j][0], resp[j][1], resp[j][2]);//*/
                for(int j = 0; j < 3; j++)
                    dic[j].clear();
                q.clear();
                if(cont > mejor){
                    for(int j = 0; j < cont; j++){
                        best[j][0] = resp[j][0];
                        best[j][1] = resp[j][1];
                        best[j][2] = resp[j][2];//*/
                    }
                    mejor = cont;
                    cout << "mejorro" << endl;
                }
            }
            for(int it = 0; it < 1000; it++){
                cont = 0;
                heuristic(k);
                //cout << cont << endl;
                if(cont > mejor){
                    for(int j = 0; j < cont; j++){
                        best[j][0] = resp[j][0];
                        best[j][1] = resp[j][1];
                        best[j][2] = resp[j][2];//*/
                    }
                    mejor = cont;
//                    cout << "mejorro" << endl;
                }
                for(int j = 0; j < 3; j++)
                    dic[j].clear();
                q.clear();
            }
            break;
        }while(next_permutation(a+1, a+4));
        printf(" %d\n", mejor);
            for(int j = 0; j < mejor; j++)
        printf("%d %d %d\n", best[j][0], best[j][1], best[j][2]);//*/

    }
	return 0;
}
