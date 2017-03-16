#include <iostream>
using namespace std;

int n,m;
int at[5],bt[111];
long long al[5],bl[111];
long long ans;

void work(long long s0,int x,int y) {
    //cerr<<"work "<<s0<<' '<<x<<' '<<y<<endl;
    if (y>=n) {
        if (s0>ans) ans=s0;
        return;
    }
    long long s=0;
    for(int i=x;i<=m;i++) {
        work(s0+s,i,y+1);
        if (bt[i]==at[y]) s+=bl[i];
        if (s>=al[y]) {
            long long t=bl[i];
            bl[i]=s-al[y];
            work(al[y]+s0,i,y+1);
            bl[i]=t;
            break;
        }
    }
}

int main() {
    int TT;
    cin>>TT;
    for(int T=1;T<=TT;T++) {
        ans=0;
        cin>>n>>m;
        at[1]=at[2]=at[3]=0;
        al[1]=al[2]=al[3]=0;
        for(int i=0;i<n;i++) cin>>al[i]>>at[i];
        for(int i=0;i<m;i++) cin>>bl[i]>>bt[i];
        bl[m]=bt[m]=0;
        long long s0=0;
        for(int i=0;i<=m;i++) {
            work(s0,i,1);
            if (bt[i]==at[0]) s0+=bl[i];
            if (s0>=al[0]) {
                bl[i]=s0-al[0];
                s0=al[0];
                work(s0,i,1);
                break;
            }
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
    return 0;
}