#include <iostream>
#include <fstream>

using namespace std;

ifstream in("c.in");
ofstream out("c.out");

int main()
{
    int t;
    in>>t;
    for(int i=1;i<=t;++i){
        int n;
        in>>n;
        int a[n],b[n];
        for(int j=0;j<n;++j){in>>a[j];--a[j];}
        bool p[n];
        for(int j=0;j<n;++j){p[j]=j==a[a[j]];}
        int pv[n];
        for(int j=0;j<n;++j)pv[j]=0;
        int mc=0;
        for(int j=0;j<n;++j){
            bool v[n];
            for(int k=0;k<n;++k)v[k]=0;
            int next=j;
            int c=0;
            while(!v[next]){
                v[next]=1;
                next=a[next];
                ++c;
            }
            if(next==j&&c>mc)mc=c;
            if(p[next]&&c-1>pv[next])pv[next]=c-1;
        }
        int l=0;
        for(int j=0;j<n;++j){
            if(p[j]){
                //cout<<i<<" "<<j<<" "<<pv[j]<<endl;
                l+=pv[j];
            }
        }
        if(mc>l)l=mc;
        out<<"Case #"<<i<<": "<<l<<endl;
    }
    return 0;
}
