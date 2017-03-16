#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("codejam.inp","r",stdin)
#define OUTPUT freopen("codejam.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const ll linf=1e18;
const int MOD=1e9+7;
const int N=20;

string scr1,scr2;
bool canbelarger(char ch1,char ch2){
    if (ch1=='?') return ch2!='9';
    if (ch2=='?') return ch1!='0';
    return ch1>ch2;
}
void modified(char &ch1,char &ch2){
    ///make ch1>ch2 and minimize diff
    if (ch1=='?'&&ch2=='?'){
        ch1='1',ch2='0';
        return;
    }
    if (ch1=='?') ch1=ch2+1;
    if (ch2=='?') ch2=ch1-1;
}
bool comp(ll a,string sa1,string sa2,ll b,string sb1,string sb2){
    if (a!=b) return a<b;
    if (sa1==sb1) return sa2<sb2;
    return sa1<sb1;
}
void solve(){
    int n=scr1.length();
    ///for scr1 <= scr2
    ll ans=linf;
    string s1,s2;
    int mlen=0;
    while (mlen<n){
        if (scr1[mlen]!='?'&&scr2[mlen]!='?'&&scr1[mlen]!=scr2[mlen]) break;
        mlen++;
    }
    if (mlen==n){
        REP(i,0,n){
            if (scr1[i]=='?'&&scr2[i]=='?') scr1[i]=scr2[i]='0';
            if (scr1[i]=='?') scr1[i]=scr2[i];
            if (scr2[i]=='?') scr2[i]=scr1[i];
        }
        cout<<scr1<<" "<<scr2<<'\n';
        return;
    }
//    cout<<mlen<<'\n';
//    cout<<scr1<<" "<<scr2<<'\n';
    REP(i,0,mlen+1){
        ///make scr1 >scr2
        if (canbelarger(scr1[i],scr2[i])){
            string tmp1=scr1,tmp2=scr2;
            modified(tmp1[i],tmp2[i]);
            REP(j,i+1,n) {
                if (tmp1[j]=='?') tmp1[j]='0';
                if (tmp2[j]=='?') tmp2[j]='9';
            }
            ll v1=0,v2=0;
            REP(j,0,n) v1=10*v1+tmp1[j]-'0';
            REP(j,0,n) v2=10*v2+tmp2[j]-'0';
            if (comp(abs(v1-v2),tmp1,tmp2,ans,s1,s2)){
                ans=abs(v1-v2);
                s1=tmp1;s2=tmp2;
            }
        }
        if (canbelarger(scr2[i],scr1[i])){
            string tmp1=scr1,tmp2=scr2;
            modified(tmp2[i],tmp1[i]);
            REP(j,i+1,n) {
                if (tmp1[j]=='?') tmp1[j]='9';
                if (tmp2[j]=='?') tmp2[j]='0';
            }
            ll v1=0,v2=0;
            REP(j,0,n) v1=10*v1+tmp1[j]-'0';
            REP(j,0,n) v2=10*v2+tmp2[j]-'0';
            if (comp(abs(v1-v2),tmp1,tmp2,ans,s1,s2)){
                ans=abs(v1-v2);
                s1=tmp1;s2=tmp2;
            }
        }
        ///make prefix the same
        if (scr1[i]=='?'&&scr2[i]=='?') scr1[i]=scr2[i]='0';
        if (scr1[i]=='?') scr1[i]=scr2[i];
        if (scr2[i]=='?') scr2[i]=scr1[i];
    }
    cout<<s1<<" "<<s2<<'\n';
}
int main(){
    freopen("input.inp","r",stdin);
    OUTPUT;
    int test;
    cin>>test;
    FOR(te,1,test){
        cin>>scr1>>scr2;
        printf("Case #%d: ",te);
        solve();
    }
}
