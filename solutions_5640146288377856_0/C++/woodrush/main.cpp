#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vstr;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int,int> mii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

//container util
#define RANGE(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
/******* All Required define Pre-Processors and typedef Constants *******/
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back




template<class T> inline void READARR(T& arr, uint64 N) {
    FOR(i,0,N){
        cin >> arr[i];
    }
}
template<class T> inline void READVEC(vector<T>& vec, uint64 N) {
    FOR(i,0,N){
        T a;
        cin >> a;
        vec.push_back(a);
    }
}

int main(int argc, char *args[]) {
    freopen("/Users/Hikaru/Downloads/A-small-attempt1.in","rt",stdin);
        freopen("/Users/Hikaru/Desktop/A-small.out","wt",stdout);
    
    int f[11][11];
    for(int r=1; r<=10; r++){
        for(int w=1; w <= r; w++){
            if(w == 1){
                f[r][w] = r;
            } else if(w == r){
                f[r][w] = w;
            } else if(w <= r/2){
                f[r][w] = 1 + f[r-w][w];
            } else {
                f[r][w] = w + 1;
            }
        }
    }
    int T;
    cin >> T;
    FOR(caseNum,1,T+1){
        int R,C,W;
        cin >> R >> C >> W;
        int ans = f[C][W];
        printf("Case #%d: %d\n", caseNum, ans);
    }
}
