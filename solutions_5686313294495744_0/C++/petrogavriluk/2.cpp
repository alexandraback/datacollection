
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
string s1,s2;
int arr[26];
int cif[10];
LL t;
int cnt=0;
map<string,int> nums;
vector<pair<int,int>> posl;
vector<int> was1,was2;
int stepn=0;

int countfake()
{
	//was1=was2=was0;
	int res=0;
	stepn++;
	FOR(i,0,posl.size())
	{
		if(was1[posl[i].first]==stepn&&was2[posl[i].second]==stepn)
			res++;
		was1[posl[i].first]=was2[posl[i].second]=stepn;
	}
	return res;
}


void solve()
{
	cin>>n;
	nums.clear();
	posl.clear();
	cnt=0;
	FOR(i,0,n)
	{
		cin>>s1>>s2;
		if(nums.find(s1)==nums.end())
		{
			nums[s1]=cnt++;
		}
		if(nums.find(s2)==nums.end())
		{
			nums[s2]=cnt++;
		}
		posl.push_back(MP(nums[s1],nums[s2]));
	}
	was1.clear();
	was1.resize(cnt);
	was2.clear();
	was2.resize(cnt);
	//was0.clear();
	//was0.resize(cnt);
	int mx=0,now;
	sort(posl.begin(),posl.end());
	FOR(i,0,2<<posl.size())
	{
		now=countfake();
		random_shuffle(posl.begin(),posl.end());
		mx=max(mx,now);
		if(posl[0]!=MP(0,1))
		{
			int qqq=1;
		}
	}
	cout<<mx;
}

int main()
{
	//#ifdef  _DEBUG
    freopen("C-small-attempt3.in","r",stdin);
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
