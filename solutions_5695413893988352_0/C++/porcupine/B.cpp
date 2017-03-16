
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

int chartoint(char c){
    return (int)c-48;
}

bool megfelel(int x, string s){
    for(int i=s.sz()-1;i>=0;--i){
        if(s[i]!='?'){
            if(x%10!=chartoint(s[i])) return false;
        }
        x/=10;
    }

    return true;
}

int absz(int x){
    if(x<0) return -x;
    else return x;
}

void kiir(int hossz, int szam){
    vector<int> asd;
    FOR(i,hossz){
        asd.pb(szam%10);
        szam/=10;
    }

    for(int i=asd.sz()-1;i>=0;--i) cout<<asd[i];
}

main(){
    int t;
    cin>>t;
    FOR(i,t){
        string a,b;
        cin>>a;
        cin>>b;
        
        pair<int,int> ans=mp(10000,9999999);
        int hossz=a.sz();

        if(a.sz()==1){
            FOR(i,10) FOR(j,10){
                if(megfelel(i,a) and megfelel(j,b)){
                    if(absz(i-j) < absz(ans.x-ans.y)) ans=mp(i,j);
                    if(absz(i-j) == absz(ans.x-ans.y) and ans>mp(i,j)) ans=mp(i,j);
                }
            }
        }

        if(a.sz()==2){
            FOR(i,100) FOR(j,100){
                if(megfelel(i,a) and megfelel(j,b)){
                    if(absz(i-j) < absz(ans.x-ans.y)) ans=mp(i,j);
                    if(absz(i-j) == absz(ans.x-ans.y) and ans>mp(i,j)) ans=mp(i,j);
                }
            }
        }

        if(a.sz()==3){
            FOR(i,1000) FOR(j,1000){
                if(megfelel(i,a) and megfelel(j,b)){
                    if(absz(i-j) < absz(ans.x-ans.y)) ans=mp(i,j);
                    if(absz(i-j) == absz(ans.x-ans.y) and ans>mp(i,j)) ans=mp(i,j);
                }
            }
        }

        cout<<"Case #"<<i+1<<": ";
        kiir(hossz,ans.x);
        cout<<" ";
        kiir(hossz,ans.y);
        cout<<endl;
    }

    return 0;
}
