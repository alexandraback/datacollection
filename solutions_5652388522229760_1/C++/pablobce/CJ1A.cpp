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
#define all(n) n.begin(),n.end()

const tint INF=2000000000;


int main(){
	int T;
	cin>>T;
	int n;
	forn(caso,T){
		cin>>n;
		if(n==0)cout<<"Case #"<<caso+1<<": INSOMNIA"<<endl;
		else{
			bool d[10];
			int N=n;
			forn(i,10)d[i]=false;
			int cont=0;
			while(cont<10){
				int aux=N;
				while(aux>0){
					if(!d[aux%10]){
						d[aux%10]=true;
						cont++;
					}
					aux/=10;
				}
				N+=n;
			}
			N-=n;
			cout<<"Case #"<<caso+1<<": "<<N<<endl;		
		}
	}
    return 0;
}
