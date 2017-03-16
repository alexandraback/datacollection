#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;


int main()
{
	int test,r,c,w;
	ull ans ;
	cin >> test ;
	fr(t,0,test)
	{
		cin >> r >> c  >> w ;
		if((c/w)*w == c )
			ans = r*(c/w) + w - 1 ;
		else
			ans = w + r*(c/w);
		cout << "Case #" << t+1 << ": " << ans  <<  endl;
	}
	return 0 ;
}