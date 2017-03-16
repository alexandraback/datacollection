#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
#define ll unsigned long long
#define VI vector<ll>
#define VS vector<string>
#define PI pair<int,int>
#define MP make_pair
#define PB push_back
        VI a;
        VI ta;
        VI b;
        VI tb;

map<PI,ll> m;

ll compute(int x, int y) {

    //cout<<" ! "<<x<<","<<y<<"  ---- "<<a.size()<<","<<b.size()<<endl;

    if (x>=a.size()) return 0;
    if (y>=b.size()) return 0;
    PI p = MP(x,y);
    if (m.find(p)!=m.end()) return m[p];
    ll ret=0;
    ll val = compute(x+1,y);
    if (val> ret) ret=val;
    val = compute(x,y+1);
    if (val> ret) ret = val;
    

    ll sum1 = 0;
    ll sum2 = 0;
    for (int i=x;i<a.size();i++) if (ta[i]==ta[x]) {
        sum1+=a[i];
        sum2 = 0;
        for (int j=y;j<b.size();j++) if (tb[j]==ta[x]) {
            sum2+=b[j];
            val = min(sum1,sum2) + compute(i+1,j+1);
            if (val>ret) ret=val;
        }
    }
    sum1 = 0;
    sum2 = 0;
     for (int j=y;j<b.size();j++) if (tb[j]==tb[y]) {
        sum1+=b[j];
        sum2 = 0;
        for (int i=x;i<a.size();i++) if (ta[i]==tb[y]) {
            sum2+=a[i];
            val = min(sum1,sum2) + compute(i+1,j+1);
            if (val>ret) ret=val;
        }
    }
    



  /* for (int i=x;i<a.size();i++) if (ta[i]==tb[y]) {
        sum1+=a[i];
        sum2 = 0;
        for (int j=y;j<b.size();j++) if (tb[j]==tb[y]) {
            sum2+=b[j];
            val = min(sum1,sum2) + compute(i+1,j+1);
            if (val>ret) ret=val;
        }
    }
*/

  //  cout<<" - "<<x<<","<<y<<"= "<<ret<<endl;
    m[p]=ret;
    return ret;
}


int main() {
    int T; cin>>T;
    for (int t=0;t<T;t++) {
        a.clear();
        b.clear();
        ta.clear();
        tb.clear();
        m.clear();
        cout<<"Case #"<<t+1<<": ";
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++) {
            ll tx,x;
            cin>>x>>tx;
                a.PB(x);
                ta.PB(tx);
        }
        for (int i=0;i<m;i++) {
            ll tx,x;
            cin>>x>>tx;
                b.PB(x);
                tb.PB(tx);
        }
        cout<<compute(0,0)<<endl;
    }

}
