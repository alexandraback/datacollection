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
#define RAYA cout<<"-----------------"<<endl;
#define DBG(x) cout<<#x<<":"<<(x)<<endl;
#define all(v) v.begin(),v.end()


typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

const int MAXN=10240;

int num[MAXN];



int main(){
	freopen("CJ3.out","w",stdout);
	int T;
	cin>>T;
	int r,n,m,k;
	cin>>r>>n>>m>>k;
	cout<<"Case #1:"<<endl;
	int p[7];
	forn(i,r){
		int c3=0;
		int c5=0;
		int c2=0;
		forn(j,k)cin>>p[j];
		forn(j,k)if(p[j]%5==0)c5=1;
		forn(j,k)if(p[j]%25==0)c5=2;
		forn(j,k)if(p[j]%125==0)c5=3;
		forn(j,k)if(p[j]%3==0)c3=1;
		forn(j,k)if(p[j]%9==0)c3=2;
		forn(j,k)if(p[j]%27==0)c3=3;
		forn(j,k)if(p[j]%4==2)c2=1;
		forn(j,c2)cout<<2;
		forn(j,c3)cout<<3;
		forn(j,c5)cout<<5;
		forn(j,3-c2-c3-c5)cout<<4;
		cout<<endl;		
	}
    return 0;
}
