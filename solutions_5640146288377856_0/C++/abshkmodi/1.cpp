#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector< PII > VPII;
typedef map<int,int> MII;
typedef set<int> SI;
typedef map<string, int> MSI;
typedef vector<bool> VB;
typedef long double LD;

#define pb push_back
#define mp make_pair
#define for_each(s,v) for(typeof((v).begin()) s=(v).begin(); s!=(v).end(); s++)
const double eps=1e-11;

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

template<class T> inline T lcm(T a,T b)//NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide(
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}

template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}

template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

 

int main(){
	
	int t;
	cin>>t;
	
	for(int o=1;o<=t;o++){
		
		int c,r,w,ans=0;

		cin>>r>>c>>w;

		if(w==1)
			ans=r*c;

		else if(w==c){
			ans=w;
		}

		else{
			
			int x=c/w;

			if(c%w==0)
				ans=x-1+w;
			
			else
				ans=x+w;
		}

		cout<<"Case #"<<o<<": "<<ans<<endl;
		
	}
	
	return 0;
} 

