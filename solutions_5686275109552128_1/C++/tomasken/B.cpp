#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

int pan[10100];

int next(int mx){
    for(int i = mx-1; i > 0; i--){
        if(pan[i]) return i;
    }
    // if(mx > 1){
    //     return mx/2 + mx%2;
    // }
    return 0;
}

int main(){
    int T;
    int D;
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> D;
        vi pan(D);
        int mx = 0;
        for(int i = 0; i < D; ++i){
            cin >> pan[i];
            mx = max(mx, pan[i]);
            //cout << pan[i] << endl;
        }
        int mntime = mx;
        int time;

        for(int i = 1; i <= mx; ++i){
            time = 0;
            for(int j = 0; j < size(pan); ++j){
                if(pan[j] % i == 0){
                    time += (pan[j] / i) - 1;
                    //printf("%d %d\n", pan[j], i);
                } else if(pan[j] > i){
                    time += pan[j] / i;
                }
            }
            //cout << time << endl;
            //printf("%d %d\n", i, time);
            mntime = min(mntime, time + i);
        }
        printf("Case #%d: %d\n", t+1, mntime);

        //mx = 0;
        //int time = 0, mntime;
        //memset(pan, 0, sizeof pan);
        //for(int i = 0; i < D; ++i){
            //cin >> p;
            //pan[p]++;
            //mx = max(mx, p);
        //}
        //mntime = mx;
        ////for(int i = 0; i <= mx; ++i){
            ////cout << pan[i] << endl;
        ////}

        //for(int i = mx; i > 0; i--){
            //if(i == 1){
                //time++;
                //break;
            //}
            //if(!pan[i]) continue;
            ////printf("i: %d\nnext(i): %d\n", i, next(i));
            //mntime = min(time + i, mntime);
            //time += pan[i];
            //pan[i/2 + i%2] += pan[i];
            //pan[i/2] += pan[i];

            ////if(pan[i] + max(next(i), i/2 + i%2) <= i - next(i)){
                ////time += pan[i];
                ////pan[i/2 + i%2] += pan[i];
                ////pan[i/2] += pan[i];
            ////} else {
                ////time += i;
                ////break;
            ////}
        //}
    }
}
