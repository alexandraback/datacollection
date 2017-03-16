///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

int containsMul(vector<int> & v,int d){
	int res = 0;
	forn(i,v.size()) if(v[i] % d == 0) res++;
	return res;
}

int main(){
freopen("CsmallInput.txt","r",stdin);
freopen("CsmallOutput.txt","w",stdout);
	int T;cin>>T;
	cout<<"Case #1:"<<endl;
	int R,N,M,K; cin>>R>>N>>M>>K;
	forn(tc,R){
		///el set de productos actual.
		vector<int> p(K); forn(i,K) cin>>p[i];
		
		if(containsMul(p,125)) cout<<"555"<<endl;///V
		else if(containsMul(p,25)){
			///tengo dos 5.
			if(containsMul(p,3)) cout<<"553"<<endl;///V
			else if(containsMul(p,4)) cout<<"554"<<endl;///V
			else if(containsMul(p,2)) cout<<"552"<<endl;///V
			else cout<<"555"<<endl;///F
		}
		else if(containsMul(p,27)) cout<<"333"<<endl;///V
		else if(containsMul(p,9)){
			if(containsMul(p,5)) cout<<"335"<<endl;///V
			else if(containsMul(p,4)) cout<<"334"<<endl;///V
			else if(containsMul(p,2)) cout<<"332"<<endl;///V
			else cout<<"333"<<endl;///F
		}
		///Tengo un 3 y un solo 5, con alta prob.
		else if(containsMul(p,5)){///Tengo un solo 5.
			if(containsMul(p,3)){///Tengo un solo 3.
				if(containsMul(p,4)) cout<<"534"<<endl;///V
				else if(containsMul(p,2)) cout<<"532"<<endl;///V
				else cout<<"532"<<endl;///F
			}
			///Tengo un 5 y ningun 3.
			else if(containsMul(p,16)) cout<<"544"<<endl;///V
			else if(containsMul(p,8)) cout<<"542"<<endl;///V
			else if(containsMul(p,4)) cout<<"522"<<endl;///V
			else if(containsMul(p,2)) cout<<"522"<<endl;
			else cout<<"522"<<endl;
		}
		///No tengo ningun 5.
		else if(containsMul(p,3)){
			///Tengo un solo 3.
			if(containsMul(p,16)) cout<<"344"<<endl;
			else if(containsMul(p,8)) cout<<"342"<<endl;
			else if(containsMul(p,4)) cout<<"322"<<endl;
			else if(containsMul(p,2)) cout<<"322"<<endl;
			else cout<<"322"<<endl;
		}
		///No tengo ni 5 ni 3.
		else{
			if(containsMul(p,64)) cout<<"444"<<endl;
			else if(containsMul(p,32)) cout<<"442"<<endl;
			else if(containsMul(p,16)) cout<<"444"<<endl;
			else if(containsMul(p,8)) cout<<"422"<<endl;
			else if(containsMul(p,4)) cout<<"222"<<endl;
			else cout<<"222"<<endl;
		}
	}
    return 0;
}
