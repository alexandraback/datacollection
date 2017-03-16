
#include"stdio.h"
#include"iostream"
#include"vector"
#include"string"
#include"string.h"
#include"algorithm"
#include"cmath"
#include"set"
#include"bitset"
#include"map"
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<ctime>
#include<queue>

using namespace std;
 
 
#define ABS(a) ((a<0)?(-a):a)
#define MAX(a,b) ((a<b)?(b):(a))
#define MIN(a,b) ((a>b)?(b):(a))
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define FOR_(i,n,a) for(int i=n;i>=a;--i) 
#define pb push_back
#define MP make_pair
 
#define TN5 100000 
#define TN6 1000000 
#define TN7 10000000 
#define TN8 100000000
#define TN9 1000000000 
#define TN10 10000000000 
 
typedef long long LL; 
typedef long double LD;
const long double eps=0.000000001;
const double pi=3.141592653589;
#define MAXN 500005

const LL mod=1000000007;
 

LL gcd(LL a,LL b)
{
	if(a>b)
		swap(a,b);

	while(a!=0&&b!=0)
	{
		b%=a;
		swap(a,b);
	}
	return a+b;
}
LL poww(LL v, LL p)
{
	 if (p == 0) return 1;

	 if (p & 1)
	 {
	  return (poww(v, p - 1) * v) % mod;
	 }
	 else
	 {
	  LL t = poww(v, p / 2);
	  return (t * t) % mod;
	 }
}
void calc_primes(int n,vector<bool> &primes)
{
	//vector<bool> primes;//<-or create as global;
	primes.resize(n,true);
	primes[1]=false;
	
	for(int i=2;i*i<n;++i)
	{
		if(!primes[i])continue;
		for(int j=i*i;j<n;j+=i)
		{
			primes[j]=false;
		}
	}
}
LL ext_gcd (LL a, LL b, LL & x, LL & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL x1, y1;
	LL d = ext_gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
bool vect_comp(pair<int,int> a,pair<int,int> b)
{
	return (a.first*b.second-a.second*b.first > 0);
}
bool get_bit(int &v,char &num)
{
	return ((v>>num)&1);
}
void set_bit(int &v,const char &num)
{
	v = v | (1<<num);
}
int count_bit(int v)
{
	int cnt = 0;
	while(v>0)
	{
		cnt+=v&1;
		v = v>>1;
	}
	return cnt;
}



LL n,q;
string s;
int arr[26];
int cif[10];
LL t;

void solve()
{
	cin>>s;
	FOR(i,0,26)
	{arr[i]=0;}
	FOR(i,0,10)
	{cif[i]=0;}
	FOR(i,0,s.size())
	{
		arr[s[i]-'A']++;		
	}
	{
		cif[0]=arr['Z'-'A'];
		arr['Z'-'A']-=cif[0];
		arr['E'-'A']-=cif[0];
		arr['R'-'A']-=cif[0];
		arr['O'-'A']-=cif[0];
	}
	{
		cif[6]=arr['X'-'A'];
		arr['S'-'A']-=cif[6];
		arr['I'-'A']-=cif[6];
		arr['X'-'A']-=cif[6];		
	}
	{
		cif[7]=arr['S'-'A'];
		arr['S'-'A']-=cif[7];
		arr['E'-'A']-=cif[7];
		arr['V'-'A']-=cif[7];	
		arr['E'-'A']-=cif[7];	
		arr['N'-'A']-=cif[7];	

	}
	{
		cif[5]=arr['V'-'A'];
		arr['F'-'A']-=cif[5];
		arr['I'-'A']-=cif[5];
		arr['V'-'A']-=cif[5];	
		arr['E'-'A']-=cif[5];
	}
	{
		cif[4]=arr['U'-'A'];
		arr['F'-'A']-=cif[4];
		arr['O'-'A']-=cif[4];
		arr['U'-'A']-=cif[4];	
		arr['R'-'A']-=cif[4];	
	}
	{
		cif[2]=arr['W'-'A'];
		arr['T'-'A']-=cif[2];
		arr['W'-'A']-=cif[2];
		arr['O'-'A']-=cif[2];
	}
	{
		cif[8]=arr['G'-'A'];
		arr['E'-'A']-=cif[8];
		arr['I'-'A']-=cif[8];
		arr['G'-'A']-=cif[8];	
		arr['H'-'A']-=cif[8];	
		arr['T'-'A']-=cif[8];	

	}
	{
		cif[9]=arr['I'-'A'];
		arr['N'-'A']-=cif[9];
		arr['I'-'A']-=cif[9];
		arr['N'-'A']-=cif[9];	
		arr['E'-'A']-=cif[9];
	}
	{
		cif[3]=arr['T'-'A'];
		arr['T'-'A']-=cif[3];
		arr['H'-'A']-=cif[3];
		arr['R'-'A']-=cif[3];	
		arr['E'-'A']-=cif[3];	
		arr['E'-'A']-=cif[3];
	}
	{
		cif[1]=arr['N'-'A'];
		arr['O'-'A']-=cif[1];
		arr['N'-'A']-=cif[1];
		arr['E'-'A']-=cif[1];	
	}
	FOR(i,0,10)
	{
		FOR(j,0,cif[i])
		{
			cout<<i;
		}
	}

}

int main()
{
	//#ifdef  _DEBUG
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
	//#endif
	#ifdef  _DEBUG
		LL startTime = clock();	
	#endif
		cin>>t;
		FOR(i,0,t)
		{
			cout<<"Case #"<<(i+1)<<": ";
			solve();
			cout<<"\n";
		}
		
		#ifdef  _DEBUG
		//printf("\n\n\t TIME: %.5lf", double((clock() - startTime)) / 1000.0f); /// CLOCKS_PER_SEC));
		#endif
	
	
	
	return 0;	

	  
		
	//return 0;  
  
}
