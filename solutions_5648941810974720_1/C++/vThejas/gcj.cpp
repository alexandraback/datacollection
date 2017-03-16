#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define ld double
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define SLL set<LL>
#define SpLL set<pLL>

LL t,n[15],l[30];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    cin>>t;
    rep(loop,1,t){
        rep(i,0,9) n[i]=0;
        rep(i,0,25) l[i]=0;
        cin>>s;
        rep(i,0,s.size()-1){
            l[s[i]-'A']++;
            if(s[i]=='Z') n[0]++;
            if(s[i]=='W') n[2]++;
            if(s[i]=='G') n[8]++;
            if(s[i]=='X') n[6]++;
            if(s[i]=='U') n[4]++;
        }
        n[1]=l['O'-'A']-n[0]-n[2]-n[4];
        n[3]=l['R'-'A']-n[4]-n[0];
        n[5]=l['f'-'a']-n[4];
        n[7]=l['v'-'a']-n[5];
        n[9]=l['i'-'a']-n[5]-n[6]-n[8];
        cout<<"Case #"<<loop<<": ";
        rep(i,0,9) rep(j,1,n[i]) cout<<i;
        cout<<endl;
    }
}
