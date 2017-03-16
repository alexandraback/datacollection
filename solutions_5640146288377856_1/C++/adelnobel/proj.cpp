/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ios>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <cassert>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int R, C, W;

int solveOld(){
    priority_queue<int> pq;
    for(int i = 0; i < R; i++){
        pq.push(C);
    }
    int total = 0;
    int last = -1;
    while(!pq.empty() && pq.top() >= W){
        int len = pq.top(); pq.pop();
        if(len >= W * 2){
            pq.push(len / 2);
            if(len & 1){
                pq.push(len / 2);
            }else{
                pq.push(len / 2 - 1);
            }
        }
        total++;
        last = len;
    }
    //assert(last != -1);
    if(last == W){
        total += W - 1;
    }else{
        //cout << "Shit" << endl;
        total += W;
    }
    return total;
}

int solveNew(){
    priority_queue<int> pq;
    for(int i = 0; i < R; i++){
        pq.push(C);
    }
    int total = 0;
    int last = -1;
    while(!pq.empty() && pq.top() >= W){
        int len = pq.top(); pq.pop();
        pq.push(len - W);
        total++;
        last = len;
    }
    //assert(last != -1);
    if(last == W){
        total += W - 1;
    }else{
        //cout << "Shit" << endl;
        total += W;
    }
    return total;
}

int main()
{
    /*freopen("in.in", "w", stdout);
    cout << 2000 << endl;
    for(int i = 1; i <= 2000; i++){
        cout << i << endl;
    }
    return 0;*/
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t;
    cin >> t;


    for(int T = 1; T <= t; T++){
        cin >> R >> C >> W;
        assert(solveNew() <= solveOld());
        //cout << C << " " << W << " " << solveOld() << " " << solveNew() << endl;
        /*if(!(solveNew() >= solveOld())){
            cout << solveNew() << endl;
            cout << C << " " << W << " ";
        }*/
        cout << "Case #" << T << ": " << solveNew() << endl;
    }

}
