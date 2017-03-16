/* * * * * * * * * * * *
 * :Krishna (MRoy)     *
 * :JU                 *
 * :mkroy.cs@gmail.com *
 * * * * * * * * * * * */
#include <bits/stdc++.h>
//~ c
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <climits>
//~ c++
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <functional>

using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef vector<ll>        	vl;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define zero(a)             memset(a,0,sizeof a)
#define minus(a)            memset(a,-1,sizeof a)
#define setinf(a)           memset(a,126,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define I_O                 ios_base::sync_with_stdio(0); cin.tie(0)
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gcd(a,b)            __gcd(a,b)
//~ Input                   
#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define I3(a,b,c)           scanf("%d%d%d",&a,&b,&c)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define L3(a,b,c)           scanf("%lld%lld%lld",&a,&b,&c)
#define D(a)                scanf("%lf",&a)
#define sc                  scanf
//~ Output                  
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define TC(cs)              cout<<"Case "<<++cs<<":"
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
#define PR                  printf
#define CHK                 cout<<"MK"<<endl;

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/

#define MX 1000010

int main()
{
	I_O;
	freopen("1bA-small-attempt0.in","r",stdin);
	freopen("cj1ba.out","w",stdout);
	int ts,cs=0;
	string s,Ans;
	cin>>ts;
	while(ts--){
		cin>>s;
		map<char,int>mp;
		for(int i=0;i<(int)s.size();i++){
			mp[s[i]]++;
		}
		Ans="";
		while(mp['Z']){
			Ans+='0';
			mp['Z']--;
			mp['E']--;
			mp['R']--;
			mp['O']--;
		}
		while(mp['W']){
			Ans+='2';
			mp['W']--;
			mp['T']--;
			mp['O']--;
		}
		while(mp['U']){
			Ans+='4';
			mp['F']--;
			mp['O']--;
			mp['U']--;
			mp['R']--;
		}
		while(mp['G']){
			Ans+='8';
			mp['E']--;
			mp['I']--;
			mp['G']--;
			mp['H']--;
			mp['T']--;
		}
		while(mp['O']){
			Ans+='1';
			mp['O']--;
			mp['N']--;
			mp['E']--;
		}
		while(mp['X']){
			Ans+='6';
			mp['S']--;
			mp['I']--;
			mp['X']--;
		}
		while(mp['F']){
			Ans+='5';
			mp['F']--;
			mp['I']--;
			mp['V']--;
			mp['E']--;
		}
		while(mp['S']){
			mp['S']--;
			mp['E']--;
			mp['V']--;
			mp['E']--;
			mp['N']--;
			Ans+='7';
		}
		while(mp['N']){
			Ans+='9';
			mp['N']--;
			mp['I']--;
			mp['N']--;
			mp['E']--;
		}
		while(mp['T']){
			Ans+='3';
			mp['T']--;
			mp['H']--;
			mp['R']--;
			mp['E']--;
			mp['E']--;
		}
		sort(Ans.begin(),Ans.end());
		cout<<"Case #"<<++cs<<": "<<Ans<<endl;
	}
	return 0;
}
