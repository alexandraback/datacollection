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

int count(int n){
	int res=0;
	while(n>0){
		res+=n%2;
		n/=2;
	}
	return res;	
}

int tab [100][100];

int main(){
	freopen("CJ3.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int k,n,m; cin>>n>>m>>k;
		int p=n*m;
		int res=k;
		forn(i,1<<p){
			if(count(i)==k){
				int pos=0;
				forn(q,n)forn(w,m){
					tab[q][w]=(i/(1<<pos))%2;
					pos++;
				}
				int cont=0;
				forn(q,n)forn(w,m){
					if(tab[q][w]){
						if(q==0 || w==0 || q==n-1 || w==m-1)cont++;
						else if(tab[q+1][w]==0 || tab[q-1][w]==0 || tab[q][w+1]==0 || tab[q][w-1]==0) cont++;						
					}
				}
				/*if(cont<res){
					res=min(res,cont);
					forn(q,n){
						forn(w,m){
							cout<<tab[q][w];
						}
						cout<<endl;
					}
				cout<<cont<<endl<<endl;
				}*/
				res=min(res,cont);
			}			
		}		
		cout<<"Case #"<<1+caso<<": "<<res<<endl;
	}	
    return 0;
}
