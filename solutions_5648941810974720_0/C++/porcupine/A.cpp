#include <bits/stdc++.h>

#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)
#define REP(i,s,n) for(int i=s;i<n;++i)
#define x first
#define y second
#define Point pair<int,int> 
#define mp make_pair
#define pb push_back
#define sz size

using namespace std;

vector<int> ans;
map<char,int> m;

void kivon(int hanyszor, string s){
    FOR(i,s.sz()){
        char c=s[i];
        m[c]-=hanyszor;
    }
}

void solve(string s){
    m.clear();
    ans.clear();
    FOR(i,s.sz()) m[s[i]]++;
    
    int Z = m['Z'];
    FOR(i,Z) ans.pb(0); 
    kivon(Z,"ZERO");
    
    int W = m['W'];
    FOR(i,W) ans.pb(2); 
    kivon(W,"TWO");
    
    int U = m['U'];
    FOR(i,U) ans.pb(4);
    kivon(U,"FOUR"); 
    
    int X = m['X'];
    FOR(i,X) ans.pb(6); 
    kivon(X,"SIX");
    
    int G = m['G'];
    FOR(i,G) ans.pb(8);
    kivon(G,"EIGHT");

    int O = m['O'];
    FOR(i,O) ans.pb(1);
    kivon(O,"ONE");

    int T = m['T'];
    FOR(i,T) ans.pb(3);
    kivon(T,"THREE");

    int F = m['F'];
    FOR(i,F) ans.pb(5);
    kivon(F,"FIVE");

    int S = m['S'];
    FOR(i,S) ans.pb(7); 
    kivon(S,"SEVEN");

    int I = m['I'];
    FOR(i,I) ans.pb(9);    
    kivon(I,"NINE");

    sort(ans.begin(),ans.end());
}

main(){
    int t;
    cin>>t;
    FOR(i,t){
        string s;
        cin>>s;
        solve(s);
        cout<<"Case #"<<i+1<<": ";
        FOR(j,ans.sz())cout<<ans[j];
        cout<<endl;
    }

    return 0;
}
