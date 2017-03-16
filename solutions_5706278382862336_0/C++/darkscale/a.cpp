#include<bits/stdc++.h>

using namespace std;
#define CLR(a,val) memset(a, val, sizeof(a))
#define SZ(V) (LL)V.size()
#define ALL(V) V.begin(),V.end()
#define RALL(V) V.rbegin(),V.rend()
#define FORN(i, n) for(LL i = 0; i < n; i++)
#define FORAB(i, a, b) for(LL i = a; i <= b; i++)
#define MOD 1000000007LL
#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long LL;
typedef pair<LL,LL> pll;


int main()
{
	LL test;
	cin >> test;
	FORAB(t,1,test){
		LL p,q,_p;
		char c;
		cin >> q >> c >> p;
		
		LL g=__gcd(q,p);
		q/=g;
		p/=g;
		bool flag=true;
		if(q>p){
			flag=false;
		}
		else{
			_p=p;
			while(p%2==0) p/=2;
			if(p!=1) flag=false;
		}
		printf("Case #%lld: ",t );
		if(flag){
			p=_p;
			LL ct=0;
			while(p>q) p/=2,ct++;
			cout << ct;
		}
		else cout << "impossible";
		cout << endl;
	}
}