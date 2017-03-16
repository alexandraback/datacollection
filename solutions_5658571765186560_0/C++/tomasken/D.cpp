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


int main(){
    int X, R, C, T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> X >> R >> C;

        if(X == 1){
            printf("Case #%d: GABRIEL\n", t + 1);
        } else if(X == 2){
            if((R*C) % 2 == 0){
                printf("Case #%d: GABRIEL\n", t + 1);
            } else {
                printf("Case #%d: RICHARD\n", t + 1);
            }
        } else if(X == 3){
            //if((R*C) < 3){
                //printf("Case #%d: RICHARD\n", t + 1);
            //} 
            if((R % 3 == 0 && C >= 2) || (R >= 2 && C % 3 == 0)){
                printf("Case #%d: GABRIEL\n", t + 1);
            } else {
                printf("Case #%d: RICHARD\n", t + 1);
            }

            //else if((R % 3 == 0 || C % 3 == 0) && (R % 2 == 0 || C % 2 == 0)){
                //printf("Case #%d: GABRIEL\n", t + 1);
            //} else if((R % 3 == 2 || C % 3 == 2) && (R % 3 == 0 || C % 3 == 0)){
                //printf("Case #%d: GABRIEL\n", t + 1);
            //} else {
                //printf("Case #%d: RICHARD\n", t + 1);
            //}
        } else if(X == 4){
            if((R*C) >= 12 && (R*C) % 4 == 0){
                printf("Case #%d: GABRIEL\n", t + 1);
            } else {
                printf("Case #%d: RICHARD\n", t + 1);
            }
        }
    }
}
