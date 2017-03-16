#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=1001000;
int n,st;
int a[101];
int d[101][maxx];

int f(int i,int x) {
    if (i>=n) return 0;
    if (x>a[n-1]+1) x=a[n-1]+1;
    if (d[i][x]==0) {
        //cerr<<"f("<<i<<","<<x<<"):"<<endl;
        int t;
        if (x>a[i]) {
            //cerr<<"A"<<endl;
            t=f(i+1,x+a[i]);
        }
        else {
            //cerr<<"B"<<endl;
            t=f(i+1,x)+1;
            //cerr<<"C"<<endl;
            if (x>1) {
                int t2=0, y=x;
                while(y<=a[i]) {
                    t2++;
                    y=y+y-1;
                }
                t2+=f(i+1,y+a[i]);
                if (t2<t) t=t2;
            }
        }
        d[i][x]=t+1;
        //cerr<<"f("<<i<<","<<x<<")="<<t<<endl;
        return t;
        
    } else return d[i][x]-1;
}

int main() {
    int TT;
    cin>>TT;
    for(int T=1;T<=TT;T++) {
        cin>>st>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        //for(int i=0;i<n;i++) cout<<a[i]<<' ';
        memset(d,0,sizeof d);
        cout<<"Case #"<<T<<": ";
        cout<<f(0,st)<<endl;
    }
    return 0;
}