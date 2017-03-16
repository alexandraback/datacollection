#include <vector>
#include <cmath>
#include <ctype.h>
#include <cassert>
#include <ctime>
#include <climits>
#include <limits>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <utility>
#include <deque>
#include <stdlib.h>
#include <functional>
//#define C11
//#include <windows.h>

#ifdef C11
    #include <unordered_map>
    #include <unordered_set>
    #include <tuple>
#endif // C11

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define fabs(x) ((x>0) ? (x) : -1*(x))
#define show(a,n) cout <<#a<<": "; for (int iii=0;iii<n;iii++) cout <<a[iii]<<" "; cout<<"\n";
#define show2(a,n,m) cout <<#a<<":\n"; for (int iii=0;iii<n;iii++) { for(int jjj=0;jjj<m;jjj++) cout <<a[iii][jjj]<<" "; cout <<"\n";}
#define name(x) cout <<#x<<" \n";
#define print(x) cout <<#x"="<<x<<"\n";
#define letters char alp[30]={qwertyuiopasdfghjklzxcvbnm},sogl[30]={qwrtpsdfghjklzxcvbnm},gl[30]={eyuioa};
#define SetBit(value,place) (value|(1<<place))
#define ClearBit(value,place) (value&(~(1<<place)))
#define InverseBit(value,place) (value^(1<<place))
#define StartClock time_t inittime=clock();
#define GetClock fprintf(stderr,"Time: %f\n",1.0*(clock()-inittime)/CLOCKS_PER_SEC);

typedef std::pair<int,int> pii;
typedef std::vector <int>::iterator iti;
typedef std::multiset <int>::iterator itm;
typedef std::set <int>::iterator itset;
typedef std::string::iterator its;
typedef std::pair<long long,long long> pll;
typedef std::vector <std::vector <int> > graph;
typedef unsigned long long ull;
typedef unsigned int ui;

using namespace std;

const int INF=INT_MAX;
const long long LINF=LLONG_MAX;
const unsigned long long ULINF=ULLONG_MAX;
const double EPS=0.000001;
const int mod=1000000007;

#define LOCAL

#ifdef LOCAL
    #include <fstream>
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#else
    #include <iostream>
#endif // LOCAL

string transform(long long n)
{
	string s="";
	while (n>0)
	{
		s+=n%10+48;
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

long long trans(string s)
{
	long long step=1,num=0;
	for (int i=s.length()-1;i>=0;i--)
	{
		num+=step*(s[i]-48);
		step*=10;
	}
	return num;
}

long long opp(long long n)
{
	string t=transform(n);
	reverse(t.begin(),t.end());
	while (t[0]=='0')
	{
		t.erase(0,1);
	}
	return trans(t);
}

long long solve(long long n)
{
	vector <long long> dp(10000000,LINF);
	dp[0]=0;
	for (int i=0;i<n;i++)
	{
		dp[i+1]=min(dp[i]+1,dp[i+1]);
		long long o=opp(i);
		dp[o]=min(dp[i]+1,dp[o]);
	}
	return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >>t;
    for (int kk=1;kk<=t;kk++)
    {
		long long n;
		cin >>n;
		long long ans=solve(n);
		cout <<"Case #"<<kk<<": "<<ans<<"\n";
	}
    return 0;
}
