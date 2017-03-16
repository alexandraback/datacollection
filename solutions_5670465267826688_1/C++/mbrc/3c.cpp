#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int M[5][5];
int A[MAXN];
int pref[MAXN];
int suf[MAXN];

int mult(int a,int b) {
	assert(a!=0);
	assert(b!=0);
	return (abs(a)/a)*(abs(b)/b)*M[abs(a)][abs(b)];
}

int prefdiv(int b,int a) { // x*a = b
	REP(i,-4,4) {
		if (mult(i,a) == b) {
			return i;
		}
	}
}

int sufdiv(int b,int a) { // a*x = b
	REP(i,-4,4) {
		if (mult(a,i)==b) {
			return i;
		}
	}
}

int expo(int a,ll ex) {
	assert(a!=0);
	if (a==1) return 1;
	if (a==-1) { return (ex%2 == 0)?1:-1; }
	int sgnv = expo(abs(a)/a,ex);
	a = abs(a);
	ex = ex%4;
	if (ex==0) return 1;
	if (ex==1) return a*sgnv;
	if (ex==2) return -1;
	return -a*sgnv;
}

bool solve() {
	ll n,k; cin>>n>>k;
	string s;
	cin>>s; s = " "+s; 
	pref[0]=1;
	REP(i,1,n) {
		if (s[i]=='i') {
			A[i]=2;
		} else if (s[i]=='j') {
			A[i]=3;
		} else { A[i]=4; }
		pref[i] = mult(pref[i-1],A[i]);
		//cout<<i<<" "<<pref[i]<<endl;
	}
	suf[n+1]=1;
	DREP(i,n,1) {
		suf[i] = mult(A[i],suf[i+1]);
		//cout<<i<<" : "<<suf[i]<<endl;
	}
	if (expo(pref[n],k)!=-1) { return false; }
	// stops at same node
	int dv=4;
	if ((pref[n]==1) or (pref[n]==-1)) { dv=2; }
	bool ok2=false,ok4=false;
	REPE(l,0,dv) {
		REPE(r,0,dv) {
			if (k < l+r+2) { continue; }
			//cout<<l<<" "<<r<<endl;
			REP(i,0,n) {
				if (mult(expo(pref[n],l),pref[i])==2) {
					ok2=true;
				}
			}
			DREP(j,n+1,1) {
				if (mult(suf[j],expo(pref[n],r))==4) {
					ok4=true;
				}
			}
		}
	}
	if (ok2 and ok4) return true;
	REPE(l,0,dv) {
		REPE(r,0,dv) {
			if (k < l+r+1) { continue; }
			if ((k - l-r-1)%4 != 0) { continue; }
			int early=-1;
			REP(i,0,n) {
				if (mult(expo(pref[n],l),pref[i])==2) {
					early=i; break;
				}
			}
			if (early<0) continue;
			DREP(i,n+1,1) {
				if ((mult(suf[i],expo(pref[n],r))==4) and (early < i)) {
					return true;
				}
			}
		}
	}
	return false;
}


int main() {
	M[0][0] = 0; M[0][1]=0; M[0][2]=0; M[0][3]=0; M[0][4]=0;
	M[1][0] = 0; M[1][1]=1; M[1][2]=2; M[1][3]=3; M[1][4]=4;
	M[2][0] = 0; M[2][1]=2 ; M[2][2]= -1; M[2][3]=4; M[2][4]=-3;
	M[3][0] = 0; M[3][1]=3; M[3][2]=-4; M[3][3]=-1; M[3][4]=2;
	M[4][0] = 0; M[4][1]=4; M[4][2]=3; M[4][3]=-2; M[4][4]=-1;
	ios::sync_with_stdio(false);
	int t; cin>>t;
	REP(i,1,t) { bool ans = solve();
		cout<<"Case #"<<i<<": "<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}
