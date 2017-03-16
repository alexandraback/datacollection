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
	int test,k,l,s;
	string a,b;
	double ans ;
	bool flag;
	cin >> test ;
	fr(te,0,test)
	{
		cin >> k >> l >> s ;
		cin >> a >> b ;
		
		double arr[26]; flag = true ;
		fr(i,0,26)
			arr[i] = 0 ;
		fr(i,0,a.length())
			arr[(int)(a[i])-65]++;
		
		fr(i,0,b.length())
		{
			if(arr[(int)(b[i])-65] == 0)
			{
				flag = false;
				break;
			}
		}
		if(!flag)
		{
			ans = 0.0 ;
			cout << fixed << "Case #" << te+1 << ": " << ans  <<  endl;
			continue;	
		}

		//precomputation of T array
		int t[b.length()+1];
		t[0] = -1 ; t[1] = 0 ;
		fr(i,2,b.length()+1) 
		{
			if( b[ t[i-1] ] == b[i-1] ) //if the letter at i is suffice to some substring
				t[i] = t[i-1] + 1 ;
			else
				t[i] = 0 ;
		}
		//cout << t[b.length()] <<  endl ;

		double p = 1.0 ;
		double q = 1.0 ;

		fr(i,0,t[b.length()])
			p = p*(arr[(int)(b[i])-65]/k);

		fr(i,t[b.length()],b.length() - t[b.length()])
			q = q*(arr[(int)(b[i])-65]/k);

		//cout << fixed << "p -> " << p << "  q --> " << q << endl ;

		double divide = (b.length() - t[b.length()]);
		if(t[b.length()] > divide)
			divide = t[b.length()];
		//cout << divide << endl ;

		double N = s/divide;
		//cout << fixed << "N " << N << endl ;

		ans = N ;

		fr(i,1,N+1)
		{
			ans -= i*p*q*p*pow((p*q + p*q*p)/2,i-1);
			if(ans < 0)
				ans = 0.0 ;
		} 


		if(flag)
			cout << fixed << "Case #" << te+1 << ": " << ans  <<  endl;
	}
	return 0 ;
}