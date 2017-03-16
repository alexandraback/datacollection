#include<bits/stdc++.h>
#define f first
//#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int licz(string s){
    int odp=0;
    for(int i=0;i<s.size();i++){
        odp*=10;
        odp+=s[i]-'0';
    }
    return odp;
}
void gen(vector<int> &v, string s,int poz){
    if(poz==s.size()){
        v.pb(licz(s));
        return;
    }
    if(s[poz]=='?'){
        for(int i=0;i<=9;i++){
            s[poz]=i+'0';
            gen(v,s,poz+1);
        }
    }
    else gen(v,s,poz+1);
}
int siz;
void wypisz(int x){
    vector<int>v(siz);
    int i=siz-1;
    while(x){
        v[i]=x%10;
        x/=10; i--;
    }
    for(int i=0;i<v.size();i++)cout<<v[i];
}
void solve(vector<int>v1,vector<int>v2){
    int odp=1e9, cod=0,jam=0;
    for(int i=0;i<v1.size();i++)
        for(int j=0;j<v2.size();j++){
            if(abs(v1[i]-v2[j]) < odp){
                odp=abs(v1[i]-v2[j]);
                cod=v1[i]; jam=v2[j];
            }
            else if(abs(v1[i]-v2[j]) == odp && v1[i] < cod){
                odp=abs(v1[i]-v2[j]);
                cod=v1[i]; jam=v2[j];
            }
            else if(abs(v1[i]-v2[j]) == odp && v1[i] == cod && v2[j] < jam){
                odp=abs(v1[i]-v2[j]);
                cod=v1[i]; jam=v2[j];
            }
        }
    wypisz(cod); cout<<" "; wypisz(jam); cout<<"\n";
}
int main(){
    cout.sync_with_stdio(0);
    int t; cin>>t;
    for(int test=1;test<=t;test++){
        string s1,s2;
        cin>>s1>>s2;
        siz=s1.size();
        vector<int>v1,v2;
        gen(v1,s1,0); gen(v2,s2,0);

        cout<<"Case #"<<test<<": ";
        solve(v1,v2);
    }
    return 0;
}
