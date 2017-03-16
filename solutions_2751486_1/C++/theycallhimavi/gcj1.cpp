// author : theycallhimavi
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <ctype.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <utility>
using namespace std;

struct ele {
	long long a,b,c,d;
};
bool comp(ele a, ele b) { return a.a<b.a; }

#define MAX(x,y) ((x)<(y) ? (y) : (x))
#define MIN(x,y) ((x)<(y) ? (x) : (y))
#define SWAP(x,y) do { a+=b; b=a-b; a=a-b; } while( 0 )
#define mod1 1000000007ll
#define mod2 10000007ll
#define inf 998877665544332211ll
#define infi 987654321
#define REP(i,n) for(i=0;i<n;i++)
#define REPI(i,j,n) for(i=j;i<n;i++)
#define PER(i,n) for(i=n-1;i>=0;i--)
#define sort(v) sort(v.begin(), v.end())
#define sortR(v) sort(v.rbegin(), v.rend())
#define sortE(v) sort(v.begin(), v.end(), comp)
#define sortRE(v) sort(v.rbegin(), v.rend(), comp)
typedef vector<long long> vi;
typedef pair<long long, long long> ii;
typedef vector<vector<long long> > vvi;
typedef long long ll;

long long power(long long x,long long y,long long m)
{
	long long temp;
	if( y == 0)
		return 1;
	temp = power(x,y/2,m)%m;
	if (y%2 == 0)
		return ((temp % m)*(temp% m))%m;
	else
		return (((((x)*(temp))%m)*(temp))%m)%m;
}
bool match(char a){
	if(a=='a' || a=='e' ||a=='i'||a=='o'||a=='u')
		return 0;
	return 1;
}
int main()
{
	long long n,m;
	long long i,j,k;
	int test,x;
	cin>>test;
	for(x = 1;x<=test;x++){
		cout<<"Case #"<<x<<": ";
		long long ans=0;
		string a;
		cin>>a>>n;
		int len = a.size();
		int coun = 0;
		int id=-1;
		int flag = 0;
		vector<int> v(len,-1);
		REP(i,n){
			if(match(a[i])) coun++;
		}
		int prev = -1;
		int fi = -1;
	//	cout<<"fi "<<fi<<" id "<<id<<endl;
		if(coun==n){
		ans = (len-n+1);
		prev = 0;
		fi=0;
		}
	//	cout<<ans<<endl;
		
//		cout<<"coun"<<coun;
		REPI(i,n, len){
			if(match(a[i])){
				coun++;
			}
			if(match(a[i-n])) coun--;
			if(coun == n){
				prev = fi;
				fi = i-n+1;
				ans += (long long)(fi-prev)*(len-i);
//				cout<<a.substr(fi,i-n)<<endl;
			}	
//			cout<<i<<" "<<coun<<" "<<prev<<endl;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
