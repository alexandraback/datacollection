#include "stdafx.h"
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
int a[3000]; int b[3000];
int visited[3000];

int order2[3000];
int order1[3000];

bool cmp2(const int ith, const int jth){
    return b[ith] < b[jth];
}

bool cmp1(const int ith, const int jth){
    if ((a[ith] < a[jth]) || (a[ith] == a[jth] && b[ith] < b[jth]))
        return true;
    else
        return false;
}

int solve(){
    FOR(i, 0, N) order2[i] = order1[i] = i;
   
    sort(order1, order1+N, cmp1);
    
    sort(order2, order2+N, cmp2);

    memset(visited, 0, sizeof(visited));
    
    int ans = 0;
    int stars = 0;
    
    int idx1=0, idx2=0;
    while(1){
        while(idx2 < N && b[ order2[idx2] ] <= stars){
            if(visited[ order2[idx2] ] == 0){
                ans++;
                stars += 2;
                visited[ order2[idx2] ] = 2;
            }
            else if(visited[ order2[idx2] ] == 1){
                ans++;
                stars += 1;
                visited[ order2[idx2] ] = 2;
            }
            idx2++;
        }

        if(idx2 == N) return ans;

        for(idx1 = N-1; idx1>=idx2; --idx1){
            if(visited[ order2[idx1] ] == 0 && a[ order2[idx1] ] <= stars)
                break;
        }

        if(idx1>=idx2){
            ans++;
            stars += 1;
            visited[ order2[idx1] ] = 1;
        }
        else
            return -1;
    }
}

int main()
{
    //freopen("z:\\input.txt", "r", stdin);
    freopen("z:\\output.txt", "w", stdout);
    //freopen("z:\\B-small-attempt2.in", "r", stdin);
    freopen("z:\\B-large.in", "r", stdin);

    GET(T);
    FORV(test_case, 1, T+1)
    {
        GET(N);
        FOR(i, 0, N) GET2(a[i], b[i]);

        int ans = solve();
        if(ans != -1)
            cout << "Case #" << test_case << ": " << ans <<endl;
        else
            cout << "Case #" << test_case << ": Too Bad\n";
    }

    return 0;
}

