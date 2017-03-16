#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define y0 qweasd
#define y1 qasdna
#define left leva
#define right prava
#define next sled
#define int long long
using namespace std;
const int N=3055;
const int inf=9e18;
string s,t;
int q;
int n;
int mx;
vector<pair<string,string> > v;
void check(){
    int ans=0;
    int e=1;
    for(int i=n-1;i>=0;--i){
        ans+=(s[i]-t[i])*e;
        e*=10;
    }
 //   cout<<abs(ans)<<' '<<s<<' '<<t<<endl;
    if(abs(ans)<mx){
        v.clear();
        mx=abs(ans);
        v.pb(mp(s,t));

    }else
    if(abs(ans)==mx){
        v.pb(mp(s,t));
    }
}
void f(int i,int q){
   // cout<<i<<' '<<q<<endl;
    if(i==n){
        check();
        return;
    }
    if(q==0){
        if(s[i]=='?'&&t[i]=='?'){
            s[i]=t[i]='0';
            f(i+1,0);
            s[i]='1';t[i]='0';
            f(i+1,1);
            s[i]='0';t[i]='1';
            f(i+1,2);
            s[i]=t[i]='?';
        }else
        if(s[i]=='?'){
            s[i]=t[i];
            f(i+1,q);
            s[i]='?';
            if(t[i]!='9'){
                s[i]=t[i]+1;
                f(i+1,1);
                s[i]='?';
            }
            if(t[i]!='0'){
                s[i]=t[i]-1;
                f(i+1,2);
                s[i]='?';
            }
        }
        else
        if(t[i]=='?'){
            t[i]=s[i];
            f(i+1,q);
            t[i]='?';
            if(s[i]!='9'){
                t[i]=s[i]+1;
                f(i+1,2);
                t[i]='?';
            }
            if(s[i]!='0'){
                t[i]=s[i]-1;
                f(i+1,1);
                t[i]='?';
            }
        }
        else {
            if(s[i]==t[i])f(i+1,0);

            if(s[i]>t[i])f(i+1,1);
            else f(i+1,2);
        }
         }else
         if(q==1){
         if(s[i]=='?'&&t[i]=='?'){
                    t[i]='9';
                    s[i]='0';
                    f(i+1,1);
                    t[i]='?';
                    s[i]='?';
            }else
            if(s[i]=='?')s[i]='0',f(i+1,1),s[i]='?';
            else
            if(t[i]=='?')t[i]='9',f(i+1,1),t[i]='?';
            else f(i+1,1);


         }else
         if(q==2){
            if(s[i]=='?'&&t[i]=='?'){
                    s[i]='9';
                    t[i]='0';
                    f(i+1,2);
                    s[i]='?';
                    t[i]='?';
            }else
            if(s[i]=='?')s[i]='9',f(i+1,2),s[i]='?';
            else
            if(t[i]=='?')t[i]='0',f(i+1,2),t[i]='?';
            else f(i+1,2);
         }
}
main(){
   // cin.tie(0);
   // ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
   int test;
   cin>>test;
   for(int z=1;z<=test;++z){
        v.clear();
     cin>>s>>t;
     n=s.size();
     q=0;
     mx=inf;
     f(0,0);
     sort(v.begin(),v.end());
     cout<<"Case #"<<z<<": ";
     cout<<v[0].x;
     cout<<' '<<v[0].y;


     cout<<endl;
   }



}

