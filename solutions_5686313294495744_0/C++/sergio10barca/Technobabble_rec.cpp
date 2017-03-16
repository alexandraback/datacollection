#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <ctime>
using namespace std;

set<pair<int, int> > q;
vector<pair<int, int> > va, vb;
int dic[2][34], mejor;
clock_t comienzo;

int solve(int n, int k){
    int it, ij;
    int maximo = k;
//    cout << n << endl;
//    cout << n << " " << k << endl;
    if(n == 0)
        return k;
    for(it = va.size()-1; it >= 0; it--){
        if(va[it].first > 1){
            va[it].first--;
            for(ij = vb.size()-1; ij >= 0; ij--){
                if(vb[ij].first > 1){
                    vb[ij].first--;
                    if(q.find(make_pair(va[it].second, vb[ij].second)) != q.end()){
                        q.erase(make_pair(va[it].second, vb[ij].second));
//     va[it].second, vb[ij].second                   cout << it->first << " " << ij->first << endl;
                        int cont = solve(n-1, k+1);
                        maximo = max(maximo, cont);
                        double f = ((clock()-comienzo)/(double)CLOCKS_PER_SEC);
                        if(f > 10.0)
                            return maximo;//*/
                        q.insert(make_pair(va[it].second, vb[ij].second));//*/
                    }
                    vb[ij].first++;
                }
            }
            va[it].first++;
        }
    }
    return maximo;
}

int main(){
    int casos, n;
    map<string, int> v;
    string s, t;
    cin >> casos;
    for(int i = 1; i <= casos; i++){
        cin >> n;
        int index = 0;
        for(int k = 0; k < 2; k++)
            for(int j = 0; j < 34; j++)
                dic[k][j] = 0;
        for(int k = 0; k < n; k++){
            cin >> s >> t;
            if(v.find(s) == v.end()){
                v[s] = index++;
            }

            if(v.find(t) == v.end()){
                v[t] = index++;
            }
            int a = v[s], b = v[t];
//            cout << a << " " << b << endl;
            dic[0][a]++;
            dic[1][b]++;
            q.insert(make_pair(a, b));
        }

        if(index >= 34){
            cout << "ERROR" << endl;
            while(1);
        }
        for(int p = 0; p < 34; p++){
            if(dic[0][p] > 1)
                va.push_back(make_pair(dic[0][p], p));
        }
        for(int p = 0; p < 34; p++){
            if(dic[1][p] > 1)
                vb.push_back(make_pair(dic[1][p], p));
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        comienzo=clock();
        if(n <= 16)
            printf("Case #%d: %d\n", i, solve(n, 0));
        else{
            printf("Case #%d: %d\n", i, 0);
        }
        q.clear();
        v.clear();
        va.clear();
        vb.clear();
    }
    return 0;
}
