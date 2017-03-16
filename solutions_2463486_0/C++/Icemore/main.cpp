#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define forv(i, a) for(int i=0; i<(int)a.size(); i++)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define VI vector< int >
#define VS vector< string >
#define PII pair< int,int >
#define PDD pair< double,double >
#define PIS pair< int, string >
#define PLL pair<long long, long long>
#define sqr(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define pi 3.1415926535897932384626433832795
#define PI pi
#define iinf 1000000000
#define linf 1000000000000000000LL
#define sinf 10000
#define eps 1e-9
#define lng long long
#define ulng unsigned long long
#define X first
#define Y second
using namespace std;
#define prev asdprev
#define exit(a) { if (a) cerr<<"oops "<<a<<endl; exit(a); }

bool palindrome(lng num)
{
	lng rev=0;
	lng tmp=num;

	while(tmp)
	{
		rev=rev*10+tmp%10;
		tmp/=10;
	}

	while(num)
	{
		if(num%10!=rev%10) return false;

		num/=10;
		rev/=10;
	}

	return true;
}

void brut()
{
	for(lng i=1; i<=100000000; ++i)
	{
		if(palindrome(i) &&
			palindrome(i*i))
			cout<<i*i<<", ";
	}
}

lng a[]={1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004};

int get(lng b)
{
	return upper_bound(a, a+48, b) - a;
}

int solve()
{
	lng b, e;
	cin>>b>>e;

	return get(e)-get(b-1);
}

#define taska "casting"
int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
	//freopen(taska".in", "r", stdin);freopen(taska".out", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int T;
	cin>>T;

	forn(tc, T)
	{
		cout<<"Case #"<<tc+1<<": "<<solve()<<endl;
	}
	
	return 0;
}

