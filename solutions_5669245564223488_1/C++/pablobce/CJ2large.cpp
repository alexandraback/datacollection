#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

#define forsn(i,s, n) for(int i=(int)s; i<(int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define fore(i,n) forn(i,n.size())
#define fori(i, n) for(typeof n.begin() i=n.begin(); i!=n.end();i++)
#define RAYA cout<<"-----------------"<<endl;
#define dbg(x) cout<<#x<<":"<<(x)<<endl;

typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define f first
#define s second

const tint INF=2000000000;

const int MOD= 1000000007;

int loop[100];
int ini[100];
int fin[100];
int in[100];
int us[100];
map<int,int>g;

void f(int n){
	us[n]=1;
	if(g.find(n)==g.end()) return;
	f(g[n]);	
	return;
}

tint fac(tint q){
	tint res=1;
	forsn(i,1,q+1){
		res*=i;
		res%=MOD;
	}
	return res;
}

int main(){
	freopen("CJ2large.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		forn(i,100){
			loop[i]=0;
			ini[i]=0;
			fin[i]=0;
			in[i]=0;
			us[i]=0;
		}
		g.clear();
		int n; cin>>n;
		string s;
		bool flag=true;
		forn(i,n){
			cin>>s;
			set<char> mem;
			mem.insert(s[0]);
			bool ban=true;
			forsn(i,1,s.length()){
				if(s[i]!=s[i-1]){
					if(mem.find(s[i])!=mem.end()){
						ban=false;
						break;						
					}else mem.insert(s[i]);
				}
			}	
			if(mem.size()==1) loop[s[0]-'a']++;
			else{
				ini[s[0]-'a']++;
				fin[s[s.size()-1]-'a']++;
				g[s[0]-'a']=s[s.size()-1]-'a';
				fori(i,mem) if(*i!=s[0] && *i!=s[s.size()-1]) in[*i-'a']++;				
			}
			if(!ban)flag=false;
		}
		forn(i,1+'z'-'a'){
			if(in[i]>1 || fin[i]>1 || ini[i]>1) flag=false;
			if(ini[i]+fin[i]+loop[i]>0 && in[i]>0) flag=false;			
		}
		int cc=0;
		if(flag){
			forn(i,1+'z'-'a'){
				if(ini[i]==1 && fin[i]==0) cc++;
				else if(ini[i]==0 && fin[i]==0 && loop[i]>0) cc++;
			}
			forn(i,1+'z'-'a')	if(ini[i]==1 && fin[i]==0)f(i);	
			forn(i,1+'z'-'a')	if(fin[i]>0 && us[i]==0)flag=false;	
		}
		cout<<"Case #"<<1+caso<<": ";
		if(flag){
			tint res=fac(cc);
			forn(i,1+'z'-'a'){
				res*=fac(loop[i]);
				res%=MOD;
			}
			cout<<res<<endl;
		}else cout<<0<<endl;
	}	
    return 0;
}
