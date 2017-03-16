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
	freopen("CJ3b.out","w",stdout);
	int T;
	cin>>T;
	int r,n,m,k;
	cin>>r>>n>>m>>k;
	cout<<"Case #1:"<<endl;
	int p[12];
	forn(i,r){
		int c[9];
		forn(j,9)c[j]=3;
		forn(j,k)cin>>p[j];
		forn(j,k){
			while(p[j]%5==0){
				c[5]++;
				p[j]/=5;
			}
			while(p[j]%2==0){
				c[2]++;
				p[j]/=2;
			}
			while(p[j]%7==0){
				c[7]++;
				p[j]/=7;
			}
			while(p[j]%3==0){
				c[3]++;
				p[j]/=3;
			}
		}
		c[5]/=6;
		c[7]/=6;
		c[3]/=6;
		c[6]=c[3]-(c[3]/2);
		c[3]=c[3]/2;
		c[2]/=6;
		c[2]-=c[6];
		int fac2=c[2];
		c[2]=0;
		c[4]=0;
		c[8]=0;
		forn(j,k)if(p[j]%4==2)c[2]=1;
		forn(j,k)if(p[j]%8==4)c[4]=1;
		fac2-=c[2];
		fac2-=c[4];
		int num=n;
		forn(j,c[5]){cout<<5;num--;}
		forn(j,c[3]){cout<<3;num--;}
		forn(j,c[6]){cout<<6;num--;}
		forn(j,c[7]){cout<<7;num--;}
		if(num>0)forn(j,c[2]){cout<<2;num--;}
		if(num>0)forn(j,c[4]){cout<<4;num--;}
		forn(j,num/3)cout<<2;
		forn(j,num/3)cout<<4;
		forn(j,num - (num/3)- (num/3))cout<<8;
		cout<<endl;
		//no time to work out fac2

		
	}
    return 0;
}
