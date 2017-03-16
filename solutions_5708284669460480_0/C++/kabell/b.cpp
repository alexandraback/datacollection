/*
 * This is my code,
 * my code is amazing...
 */
//Template v2.0
//iostream is too mainstream
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iomanip>
//clibraries
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
//defines
#define ll long long
#define lld long double
#define pll pair<ll,ll>
#define pld pair<lld,lld>
#define vll vector<ll>
#define vvll vector<vll>
#define INF 1000000000000000047
const char en='\n';
#define debug(x){cerr<<x<<en;}
#define prime 47
#define lprime 1000000000000000009
#define lldmin LDBL_MIN
#define MP make_pair
#define PB push_back
using namespace std;

int poceti=0, pocetc=0,maxi=0;
string x,K;

void r(string s,int len){
    //cout<<s<<" "<<K<<" "<<len<<endl;
    if(s.length()>=len){
        //cout<<s<<" "<<x<<en;
        int ppp=0;
        for(int i=0; i<=len-x.length(); i++){
            int ok=1;
            for(int j=0; j<x.length(); j++)
                if(s[i+j]!=x[j])
                    ok=0;
            if(ok)
                ppp++;

        }
        poceti+=ppp;
        maxi=max(maxi,ppp);
        
        pocetc++;
    }
    else{
        for(int i=0; i<K.length(); i++){
            string ss=s;
            ss.append(1,K[i]);
            r(ss,len);
        }

    }

}



int main(){
	ios::sync_with_stdio(false);

        int T;
        cin>>T;
        for(int t=1; t<=T; t++){
            poceti = 0;
            pocetc=0;
            maxi = 0;

            int znakov,ds,dch;
            cin>>znakov>>ds>>dch;
            string znaky,slovo,xx="";
            cin>>znaky>>slovo;
            x=slovo;
            K=znaky;
            r(xx,dch);
            int san = maxi*pocetc-poceti;
         //   cout<<maxi<<" "<<pocetc<<" "<<poceti<<endl;
            cout<<"Case #"<<t<<": "<<setprecision(10)<<fixed<<(double)san/pocetc<<en;

        }

}
