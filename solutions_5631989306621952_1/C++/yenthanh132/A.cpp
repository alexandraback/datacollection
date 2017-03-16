#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin>>T;
    for(int tt=1; tt<=T; ++tt){
        string s;
        cin>>s;
        int n=sz(s);
        string v="";
        v+=s[0];
        for(int i=1; i<n; ++i){
            string v1=v+s[i];
            string v2=s[i]+v;
            if(v1>v2) v=v1;
            else v=v2;
        }
        printf("Case #%d: %s\n",tt,v.c_str());
    }
}

