#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>

using namespace std;


#define LL 				"%I64d"
#define sz(a) 			int((a).size())
#define pb 				push_back
#define mp 				make_pair
#define F				first
#define S				second
#define all(c) 			(c).begin(),(c).end()
#define tr(c,i) 		for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x) 	((c).find(x) != (c).end())
#define cpresent(c,x) 	(find(all(c),x) != (c).end()) 
#define INF				(int(1e9))
#define INFL			(int(1e18))
#define EPS				1e-12
const int inf = 100010;
const int MOD = 1000000007;
const double pi=acos(-1.0);


#define iabs(x)  ((x) > 0 ? (x) : -(x))

#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )

#define rep(i,a)	for(i=0;i<a;i++)
#define FOR(i,a,b)	for(i=a;i<b;i++)

long long gcd(long long a,long long b) {return (b==0?a:gcd(b,a%b));}
long long lcm(long long a,long long b) {return (a*(b/gcd(a,b)));}
//int fx[]={0,0,1,-1};
//int fy[]={-1,1,0,0};

//long arr[1010];
//int ti[1010];

long long reverse(long long num) {
	long long temp =0;
	while(num>0) {
		int rem = num%10;
		temp*=10;
		
		temp+=rem;
		num/=10;
	}
	
	return temp;
	
}
long fun(long long n ) {
	if(n<=20) {
			return n;
	}
	 {
		int cnt=0;
		int ls = n%10;
		if(ls) {
			cnt+=ls-1;
			n-=(ls-1);
		}
		else {
			cnt+=9;
			n-=9;
			
		}
		int tt = reverse(n);
		if(tt<n) {
//			cout<<tt<<"\t";
			return cnt+fun(tt)+1;
		}
		else {
//			cout<<n-1<<"\t";
			return cnt+fun(n-1)+1;
		}
		
	}
	
} 
int main() {
	ios_base::sync_with_stdio(0);
	long long i=0,j;
	long long n,t,T;
	long long y;
//	int ans=0;
	int flg;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>T;
	long cnt=0;
//	long long t;
	FOR(t,1,T+1) {
		
		cin>>n;
		
		cnt = fun(n);
		cout<<"Case #"<<t<<": "<<cnt<<endl;
	}
	
	
	
	
	
	
	
	
	
	return 0;
}	
