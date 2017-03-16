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
