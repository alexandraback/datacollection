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
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
int ABS(int a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code bgins here */

void pre() {

}

inline void openfiles() {
    freopen("input.in","r",stdin);
    freopen ("output.txt", "w", stdout);
}

struct tribe {
    int di,ni,wi,ei,si,deltad,deltap,deltas;
};


struct attacks {
    int day;
    int west;
    int east;
    int strength;
};

bool operator<(attacks a, attacks b) {
    return a.day<b.day;
}

int main()
{
    pre();
    int t,tests=1,i,j;
    openfiles();
    S (t);
    while (t--) {
        int n,ans=0;
        int wall[1000] = {0};
        int newwall[1000] = {0};
        vector<attacks> a;
        cin >> n;
        F(i,0,n) {
            tribe t;
            cin >> t.di >> t.ni >> t.wi >> t.ei >> t.si >> t.deltad >> t.deltap >> t.deltas;
            F(j,0,t.ni) {
                attacks temp;
                temp.day = t.di + t.deltad*j;
                temp.west = t.wi + t.deltap*j;
                temp.east = t.ei + t.deltap*j;
                temp.strength = t.si + t.deltas*j;
                // cout << temp.day << " " << temp.west << " " << temp.east << " " << temp.strength << endl;
                a.pb(temp);
            }
        }
        sort(a.begin(),a.end());
        // F(i,0,a.size()) cout << a[i].day << " " << a[i].west << " " << a[i].east << " " << a[i].strength << endl;
        i = 0;
        while ( i < a.size() ) {
            int k= i;
            // F(j,0,30) cout << wall[j+500] << " "; cout << endl;
            while ( i < a.size() && (i==k || (a[i].day==a[i-1].day)) ) {
                bool breach = false;
                a[i].west = a[i].west*2;
                a[i].east = a[i].east*2;
                if ( a[i].west+500 < 0 || a[i].east+500 > 1000 ) cout << "bug!!!!" << endl;
                F(j,a[i].west,a[i].east+1) {
                    if ( wall[j+500] < a[i].strength ) {
                        breach = true;
                    }
                    newwall[j+500] = max(newwall[j+500],max(wall[j+500],a[i].strength));
                }
                if ( breach ) {ans++;}
                i++;
            }
            F(j,0,1000) wall[j]=max(wall[j],newwall[j]);
        }

        cout << "Case #" << tests << ": " << ans << endl;
        tests++;
    }
    return 0;
}
