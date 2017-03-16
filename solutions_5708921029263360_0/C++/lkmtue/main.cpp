#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int t,n,a,b,c,k,c1[4][4],c2[4][4],c3[4][4];
vector<int> com;

void display(int x) {
    //cout<<x<<endl;
    cout<<x/100+1;x%=100;
    cout<<' '<<x/10+1<<' '<<x%10+1<<endl;
}

bool solve(int mask) {
    reset(c1,0);reset(c2,0);reset(c3,0);
    For(i,0,com.size()) if((1<<i)&mask) {
        int tmp = com[i];
        int aa=tmp/100;tmp%=100;
        int bb=tmp/10,cc=tmp%10;
        c1[aa][bb]++;
        c2[bb][cc]++;
        c3[cc][aa]++;
        if(c1[aa][bb]>k||c2[bb][cc]>k||c3[cc][aa]>k) return false;
    }
    return true;
}

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    For(cas,1,1+t) {
        cout<<"Case #"<<cas<<": ";
        cin>>a>>b>>c>>k;
        com.clear();
        For(i,0,a) For(j,0,b) For(kk,0,c) com.pb(i*100+j*10+kk);
        if(k>=c) {
            cout<<com.size()<<endl;
            For(i,0,com.size()) display(com[i]);
            continue;
        }
        //cout<<com.size()<<endl;
        int ans=0,am=0;
        For(mask,1,1<<(com.size())) if(solve(mask)) {
            int tmp = __builtin_popcount(mask);
            if(tmp>ans) {
                ans=tmp;
                am=mask;
            }
        }
        cout<<ans<<endl;
        For(i,0,com.size()) if((1<<i)&am) {
            display(com[i]);
        }
    }
}
