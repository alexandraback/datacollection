#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <time.h>
#include <memory>
using namespace std;

typedef long long LL;
typedef long long uLL;
typedef unsigned int uint;
#define FOR(i, b, e) for(int i=(b); i<int(e); ++i)
#define dFOR(i, b, e) for(int i=(b); i>int(e); --i)
#define FORV(i, b, e) for(i=(b); i<(e); ++i)
#define dFORV(i, b, e) for(i=(b); i>int(e); --i)
#define GET(a) cin >> a
#define GET2(a, b) cin >> a >> b
#define GET3(a, b, c) cin >> a >> b >> c
#define GET4(a, b, c, d) cin >> a >> b >> c >> d
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PB(a) push_back(a)
#define SIZE(a) a.size()
#define PEEK(a) cout << " >> " #a " = " << a << endl
#define peek(a) _peek(#a, a)
template <typename T> void _peek(char name[], T &obj, size_t max_count=50){
    const size_t ipl = 10;
    cout << " >> " << name << " = ["; size_t _count = 0;
    for(typename T::iterator it=obj.begin(); it!=obj.end(); ++it){
        if(_count && _count%ipl == 0) cout << "      [";
        cout << *it; ++_count;
        if(_count%ipl == 0 || _count >= max_count || it == obj.end()-1) cout << " ]\n";
        else cout << ", ";
        if(_count >= max_count) break;
    }
}
template <typename T> ostream &operator << (ostream &cout, pair<T, T> &x){
    cout << "(" << x.first << "," << x.second << ")";
    return cout;
}
template <typename T> inline T GCD(T a, T b){
    if(b==0) return a;
    a %= b; while(a){ swap(a, b); a %= b; }; return b;
}
template <typename T> inline T LCM(T a, T b){
    if(a == 0 || b == 0) return -1;
    a /= GCD(a, b); T lcm = a * b;
    if(lcm < 0 || lcm/a != b ) return -1;
    return lcm;
}
//===========================================================
int T, test_case;
int N;
vector<vector<int> > E;

void read(){
    GET(N);
    E.assign(N, vector<int>());

    FOR(i, 0, N){
        int k; GET(k);
        FOR(j, 0, k){
            int base; GET(base);
            E[i].push_back(base-1);
        }
    }
}

void solve(){
    FOR(i, 0, N){
        vector<bool> visited(N, false);
        queue<int> que;
        que.push(i); visited[i] = true;
        while(!que.empty()){
            int src = que.front(); que.pop();
            FOR(j, 0, E[src].size()){
                int des = E[src][j];
                if( visited[des] ){
                    cout << "Yes\n";
                    return;
                }
                visited[des] = true;
                que.push( des );
            }
        }
    }

    cout << "No\n";
}

int main()
{
    freopen("z:\\output.txt", "w", stdout);

    //freopen("z:\\input.txt", "r", stdin);
    freopen("z:\\A-small-attempt0.in", "r", stdin);
    //freopen("z:\\A-large.in", "r", stdin);


    GET(T);
    FORV(test_case, 1, T+1)
    {
	    //scanf("% % % % %", &, &, &, &, &);
        read();
        cout << "Case #" << test_case << ": ";
        solve();
    }

    return 0;
}

