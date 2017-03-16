/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in","r",stdin);
    // freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

int main() {
    input();

    int t, kase = 1; cin >> t;
    while ( t-- ) {

        char ch[26] = {0};

        int K, L, S;
        cin >> K >> L >> S;
        string keys; cin >> keys;
        F(i,0,keys.size()) {
            ch[ keys[i]-'A' ]++;
        }
        bool poss = 1;
        string str; cin >> str;
        F(i,0,str.size()) {
            if ( ch[ str[i]-'A' ] == 0 ) {
                poss = 0;
            }
        }

        if ( !poss || str.size() > S ) {
            printf("Case #%d: 0.00000000\n", kase++);
            continue;
        }

        int common = 0;
        for ( int i = 1; i < str.size(); ++i ) {
            bool ok = 1;
            for ( int j = 0; i+j < str.size(); ++j ) {
                if ( str[j] != str[i+j] ) {
                    ok = 0; break;
                }
            }
            if ( ok ) {
                common = str.size() - i;
                break;
            }
        }
        int left = str.size() - common;
        int lst = S - str.size();
        int max = 1 + (lst/left);
        assert ( lst >= 0 );

        double pr = 1.0;
        F(i,0,str.size()) {
            pr *= ((double)ch[str[i]-'A']/(double)(keys.size()));
        }
        pr *= lst+1;

        double ans = (double)max - pr;
        printf("Case #%d: %.8lf\n", kase++, ans);

    }

    return 0;
}