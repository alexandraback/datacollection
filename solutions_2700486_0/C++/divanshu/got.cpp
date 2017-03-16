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
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl

vector<int> v;
vector<double> powhalf;
vector<double> cumm;

void pre() {
    int i = 1;
    int total = 1;
    while ( total < 20000005 ) {
        v.pb(total);
        i += 4;
        total += i;
    }
    i = 0;
    double start = 0.5;
    while ( i < 100005 ) {
        powhalf.pb(start);
        if(i>0) cumm.pb(cumm[i-1]+start);
    else cumm.pb(start);
        start = start * 0.5;
        ++i;
    }
}

int abs(int n) {
    if ( n < 0 ) return -n;
    return n;
}

 int main()
{
    pre();
    int t,i;
    int test=1;
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;
    while (t--) {
        double p;
        int n,x,y;
        cin >> n >> x >> y;
        vector<int>::iterator it = upper_bound(v.begin(),v.end(),n);
        int left = n-(*(it-1));
        int row = it-v.begin();
    // cout << row <<  " " <<  left << endl;
        if ( abs(x)+y < (row*2) ) {
            p = 1.0;
        } else if ( abs(x)+y >= ((row+1)*2) ) {
        p = 0.0;
    } else {
            if ( left < y ) {
                p = 0.0;
            } else if ( left > y+(row*2-1)+1 ) {
                p = 1.0;
            } else {
        int mand = (left>((row*2-1)+1)?left-(row*2-1)-1:0);
        //cout << "mand: "<<mand << endl;
                int idx = y-mand,end;
                if ( mand > 0 ) end = (row*2-1)-mand;
        else end = left-1;
                p = cumm[end]-(idx>0?cumm[idx-1]:0);
            }
        }
        printf("Case #%d: %.9lf\n",test,p);
        test++;
    }
    return 0;
}