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
		long long e;
		cin>>e>>n;
		if(n>0){
		//	a.push_back('N');
		REP(i,n){
			a.push_back('S');
			a.push_back('N');
		}
		}
		if(n<0){
	//		a.push_back('S');
		REP(i,(abs(n))){
			a.push_back('N');
			a.push_back('S');
		}
		}
		if(e>0){
//			a.push_back('E');
		REP(i,e){
			a.push_back('W');
			a.push_back('E');
		}}
		if(e<0){
	//		a.push_back('W');
		REP(i,abs(e)){
			a.push_back('E');
			a.push_back('W');
		}
		}
		cout<<a<<endl;
	}
	return 0;
}
