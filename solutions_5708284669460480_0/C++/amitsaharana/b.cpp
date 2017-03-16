#include <bits/stdc++.h>
using namespace std;
#define ll long long

double  tot, res;
int mx;
int k,l,s;
string a,b;

string d;

void go(int x) {
    //cout<<x<<" "<<d<<" "<<k<<" "<<l<<" "<<s<<" "<<a<<" "<<b<<endl;
    if(x==s) {
        //cout<<d<<endl;
        tot++;
        int p = 0;
        int y;
        int cur = 0;
        while((y=d.find(b,p))!=string::npos) {
            res++;
            cur++;
            p = y+1;
        }
        mx = max(mx,cur);
        return;
    }
    for(int i=0; i<k; i++) {
        d[x] = a[i];
        go(x+1);
    }
}

int main(){
    int t;
    cin>>t;
    for(int z=1; z<=t; z++) {
        cout<<"Case #"<<z<<": ";
        cin>>k>>l>>s;
        cin>>a>>b;
        mx = 0;
        tot = 0.0;
        res = 0.0;
        d = "";
        for(int i=0; i<s; i++) d+=" ";
        go(0);
        //cout<<mx<<" "<<tot<<" "<<res<<endl;
        double ans = mx*tot-res;
        if(mx>0) {
            ans/=tot;
        }
        printf("%.9f\n",ans);
    }
}