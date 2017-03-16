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




int main(){
	freopen("CJ3.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int R, C, M; 
		cin>>R>>C>>M;
		cout<<"Case #"<<caso+1<<":"<<endl;
		int E=R*C-M;
		vector<char> ans;
		bool flag=true;
		if(R==1 || C==1){
			forn(i,E) ans.pb('.');
			forn(i,M) ans.pb('*');
		}else if(E==1){
			ans.pb('.');
			forn(i,M) ans.pb('*');
		}else if(R==2 || C==2){
			if(E%2==1 || E==2){
				cout<<"Impossible"<<endl;	
				flag=false;	
			}else{
				if(R==2){
					forn(i,E/2) ans.pb('.');
					forn(i,M/2) ans.pb('*');
					forn(i,E/2) ans.pb('.');
					forn(i,M/2) ans.pb('*');				
				}else if (C==2){
					forn(i,E) ans.pb('.');
					forn(i,M) ans.pb('*');	
				}
			}
		}else if(E==2 || E==3 || E==5 || E==7){
			cout<<"Impossible"<<endl;	
			flag=false;
		}else if(E<2*C){
			if(E%2==0){
				forn(i,E/2) ans.pb('.');
				forn(i,C-E/2) ans.pb('*');
				forn(i,E/2) ans.pb('.');
				forn(i,C-E/2) ans.pb('*');
				forn(i,R-2)forn(j,C) ans.pb('*');				
			}else{
				E-=3;
				forn(i,E/2) ans.pb('.');
				forn(i,C-E/2) ans.pb('*');
				forn(i,E/2) ans.pb('.');
				forn(i,C-E/2) ans.pb('*');
				forn(i,3) ans.pb('.');
				forn(i,C-3) ans.pb('*');
				forn(i,R-3)forn(j,C) ans.pb('*');	
			}
		}else{
			if(E%C!=1){
				forn(i,E) ans.pb('.');
				forn(i,M) ans.pb('*');
			}
			if(E==2*C+1){
				forn(i,C-1) ans.pb('.');
				ans.pb('*');
				forn(i,C-1) ans.pb('.');
				ans.pb('*');
				forn(i,3) ans.pb('.');
				forn(i,C-3) ans.pb('*');
				forn(i,R-3)forn(j,C) ans.pb('*');
			}else if (E%C==1){
				forn(i,E/C-1)forn(j,C)ans.pb('.');
				forn(i,C-1) ans.pb('.');
				ans.pb('*');
				forn(i,2) ans.pb('.');
				forn(i,M-1) ans.pb('*');				
			}
		}
		if(flag){
			ans[0]='c';
			forn(i,R){
				forn(j,C) cout<<ans[i*C+j];
				cout<<endl;
			}
		}
	}	
    return 0;
}
