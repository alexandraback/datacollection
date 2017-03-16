#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

//min s1 then s2
string s1,s2;
ii getdigs(int i,int diff,bool esf) {
	diff--;
	int a=-1,b=-1;
	if (s1[i]!='?') a=s1[i]-'0';
	if (s2[i]!='?') b=s2[i]-'0';
	if (a==b && a==-1) {
		if (diff==0) return ii(0,0);
		if (diff==1) return esf?ii(1,0):ii(9,0);
		if (diff==-1) return esf?ii(0,1):ii(0,9);
	}

	if (a!=-1 && b!=-1) return ii(a,b);
	bool ss=(a==-1);
	if (ss) swap(a,b);
	b=a+diff;
	if (!esf) {
	if (diff==1) b=9;
	if (diff==0) b=a;
	if (diff==-1) b=0;
	}

	if (b==-1) b=9;
	if (b==10) b=0;
	if (ss) swap(a,b);
	return ii(a,b);
}

ll p3[20];
ll p10[20];

int main() {
	int T;
	cin >> T;

	p3[0]=1;
	p10[0]=1;
	for (int c=1;c<20;c++) p3[c]=p3[c-1]*3;
	for (int c=1;c<20;c++) p10[c]=p10[c-1]*10;

	for (int cas=1;cas<=T;cas++) {
		cin >> s1 >> s2;
		int n=s1.size();
		ll b1=LLONG_MAX,b2=0;
		for (ll c=0;c<p3[n];c++) {
			ll d=c;
			ll na=0,nb=0;
			//bool eqsofar=1;
			for (int i=n-1;i>=0;i--) {
				ii dg=getdigs(n-1-i,d/p3[i]%3,na==nb);
				//na*=10;nb*=10;
				na+=dg.x*p10[i];nb+=dg.y*p10[i];
			}

			if (abs(nb-na)<abs(b2-b1) || (abs(nb-na)==abs(b2-b1) && (na<b1 || (na==b1 && nb<b2)))) {
				b1=na;
				b2=nb;
			}
		}

		printf("Case #%d: %0*lld %0*lld\n",cas,n,b1,n,b2);
	}
}
