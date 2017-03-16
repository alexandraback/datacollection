#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

double d[100][100];

double f(int t,int l,int r);

double f_(int t,int l,int r) {
    if (l>r) return f(t,r,l);
    if ((l==0)&&(r==0)) return 1.0;
    if (l==0) return f(t,l,r-1)*0.5;
    // l>0, r>0
    if ((l==t)&&(r==t)) return 1.0;
    if (r==t) return f(t,l-1,t)+f(t,l,t-1)*0.5;
    return 0.5*(f(t,l-1,r)+f(t,l,r-1));
}

double f(int t,int l,int r) {
    cerr<<"f("<<t<<','<<l<<','<<r<<"):"<<endl;
    double x;
    if (d[l][r]>-0.1) x= d[l][r];
    else {
        x=f_(t,l,r);
        d[l][r]=x;
    }
    cerr<<"f("<<t<<','<<l<<','<<r<<")="<<x<<endl;
    return x;
}

double work_(int N, int x, int y) {
    if (N==0) return 0.0;
    if ((x==0)&&(y==0)) return 1.0;
    if (x<0) x=-x;
    for(int i=0;i<100;i++)for(int j=0;j<100;j++) d[i][j]=-1;
    int s=1,t=2;
    while(s+t+t+1<=N) {
        s=s+t+t+1;
        t+=2;
    }
    int z=N-s;
    cerr<<"s="<<s<<" z="<<z<<endl;
    int ao=t;
    int ai=ao-2;
    if (x+y<=ai) return 1.0;
    if (x+y>ao) return 0.0;
    if (y+1+t<=z) return 1.0;
    if (y+1>z) return 0.0;
    double ans=0.0;
    for(int i=0;i<=t;i++)
        if ((z-i>=y+1)&&(z-i<=t)) ans+=f(t,i,z-i);
    return ans;
}

double work(int t,int l,int r) {
    cerr<<"work("<<t<<','<<l<<','<<r<<"):"<<endl;
    double x=work_(t,l,r);
    cerr<<"work("<<t<<','<<l<<','<<r<<")="<<x<<endl;
    return x;
}

int main() {
    int TT;
    cin>>TT;
    for(int T=1;T<=TT;T++) {
        int n,x,y;
        cin>>n>>x>>y;
        cout<<"Case #"<<T<<": ";
        cout<<work(n,x,y)<<endl;
    }
    return 0;
}