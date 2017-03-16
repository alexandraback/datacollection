#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> P2;
typedef pair<ll, ll> P2l;

#define INF 1000000

ll dpc[20][15][15], dpt[20][15][15];

int main()
{
	int debug = 0;
	if(debug){
		//freopen("out_1.txt", "r", stdin);
		//srand((int)time(NULL));
		return 0;
	}
	
	freopen("B-large.in", "r", stdin);//
	freopen("out-B-pp.txt", "w", stdout);
	ll infz=1000000000000000000;

	int T; cin>>T;
	forn(i,T) {
		string s1,s2; cin>>s1>>s2;
		int N = s1.size();
		
		forn(j, N+1) forn(z1, 10) forn(z2, 10) 
		{
			if(j) {dpc[j][z1][z2]=infz;dpt[j][z1][z2]=infz;}
			else {dpc[j][z1][z2]=0;dpt[j][z1][z2]=0;}
		}
		for(int j=1;j<=N;j++) {
			forn(km1, 10) forn(km2,10){
				ll k1,k2;
				if(s1[j-1]=='?') k1=km1; else k1=s1[j-1]-'0';
				if(s2[j-1]=='?') k2=km2; else k2=s2[j-1]-'0';

				ll tmp[10][10];
				forn(z1,10) forn(z2,10) tmp[z1][z2]=infz;
				forn(z1,10) forn(z2,10) 
					if(dpc[j-1][z1][z2]<infz && dpt[j-1][z1][z2]<infz) 
						tmp[z1][z2]=abs(dpc[j-1][z1][z2]*10+k1-dpt[j-1][z1][z2]*10-k2);
				ll mval=tmp[0][0], ti=0, tj=0;
				forn(z1,10) {forn(z2,10) 
					if(mval>tmp[z1][z2]) {mval=tmp[z1][z2];ti=z1;tj=z2;}
					else if(mval==tmp[z1][z2]){
						if(ti<z1) {ti=z1;tj=z2;}
						else if(ti==z1 && tj<z2) {ti=z1;tj=z2;}
					}
				}
				dpc[j][k1][k2]=dpc[j-1][ti][tj]*10+k1;
				dpt[j][k1][k2]=dpt[j-1][ti][tj]*10+k2;
			}
		}

		ll tmp[10][10];
		forn(z1,10) forn(z2,10) tmp[z1][z2]=infz;
		forn(z1,10) forn(z2,10) {
			if(dpc[N][z1][z2]<infz && dpt[N][z1][z2]<infz) 
				tmp[z1][z2]=abs(dpc[N][z1][z2]-dpt[N][z1][z2]);
		}
		ll mval=infz, ti=0, tj=0;
		forn(z1,10) forn(z2,10) 
			if(mval>tmp[z1][z2]) {mval=tmp[z1][z2];ti=z1;tj=z2;}
			else if(mval==tmp[z1][z2]){
				if(ti<z1) {ti=z1;tj=z2;}
				else if(ti==z1 && tj<z2) {ti=z1;tj=z2;}
			}

		stack<int> si;
		ll a1=dpc[N][ti][tj], a2=dpt[N][ti][tj];
		cout<<"Case #"<<i+1<<": ";
		forn(i,N) {si.push(a1%10); a1/=10;}
		while(si.size()) {cout<<si.top();si.pop();}
		cout<<" ";
		forn(i,N) {si.push(a2%10); a2/=10;}
		while(si.size()) {cout<<si.top();si.pop();}
		cout<<endl;
	}

	return 0;
}
