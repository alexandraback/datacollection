#include <bits/stdc++.h>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

#define Fastcin() cin.tie(0),cerr.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define oo       1e9
#define ll       long long
#define sc(x)    scanf("%d",&x)
#define scl(x)   scanf("%lld",&x)
#define lop(i,n) for(int i=0;i<n;++i)
#define sz(x)    (int)x.size()
#define all(x)   x.begin(),x.end()
#define f        first
#define s        second
#define pi       acos(-1)

int T;
string s,t;
vector<string> v1,v2;

void go1(string str,int idx){
    if(idx==sz(str)){
        v1.push_back(str);
        return;
    }
    if(str[idx]!='?'){
        go1(str,idx+1);
        return;
    }
    for(int i=0;i<10;i++){
        str[idx]=(char('0'+i));
        go1(str,idx+1);
        str[idx]='?';
    }
    return;
}

void go2(string str,int idx){
    if(idx==sz(str)){
        v2.push_back(str);
        return;
    }
    if(str[idx]!='?'){
        go2(str,idx+1);
        return;
    }
    for(int i=0;i<10;i++){
        str[idx]=(char('0'+i));
        go2(str,idx+1);
        str[idx]='?';
    }
    return;
}

int dif;
int sc1,sc2;
string ans1,ans2;

int strTo(string str){
    int val=0;
    for(int i=0;i<sz(str);i++)
        val=val*10+(str[i]-'0');
    return val;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt1.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    sc(T);
    for(int C=1;C<=T;C++){
        cin>>s>>t;
        v1.clear();
        v2.clear();
        go1(s,0);
        go2(t,0);
        dif=oo;
       for(int i=0;i<sz(v1);i++)
           for(int j=0;j<sz(v2);j++){
               int tmp1=strTo(v1[i]);
               int tmp2=strTo(v2[j]);
               int tmp=abs(tmp1-tmp2);
               if(tmp<dif){
                   dif=tmp;
                   sc1=tmp1;
                   sc2=tmp2;
                   ans1=v1[i];
                   ans2=v2[j];
               }else if(tmp==dif){
                   if(tmp1<sc1){
                       dif=tmp;
                       sc1=tmp1;
                       sc2=tmp2;
                       ans1=v1[i];
                       ans2=v2[j];
                   }else if(tmp1==sc1&&tmp2<sc2){
                       dif=tmp;
                       sc1=tmp1;
                       sc2=tmp2;
                       ans1=v1[i];
                       ans2=v2[j];
                   }
               }
           }
       printf("Case #%d: ",C);
       cout<<ans1<<" "<<ans2<<endl;
    }
}
