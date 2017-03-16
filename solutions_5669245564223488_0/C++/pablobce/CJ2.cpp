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

string s[100];
int v[100];
const int MOD= 1000000007;

int main(){
	freopen("CJ2.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int n; cin>>n;
		forn(i,n)cin>>s[i];
		forn(i,n)v[i]=i;
		int res=0;
		do{
			string c="";
			forn(i,n)c+=s[v[i]];
			set<char> mem;
			mem.insert(c[0]);
			bool flag=true;
			forsn(i,1,c.length()){
				if(c[i]!=c[i-1]){
					if(mem.find(c[i])!=mem.end()){
						flag=false;
						break;						
					}else mem.insert(c[i]);
				}
			}
			if(flag){
				res++;
				res%=MOD;
			}
		}while(next_permutation(v,v+n));
		cout<<"Case #"<<1+caso<<": "<<res<<endl;
	}	
    return 0;
}
