#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <typeinfo>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define CL(a,x)         memset(a,x,sizeof(a))
#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
#define asort(a,n)		sort(a,a+n)
#define vsort(v,n)		sort(v.begin(), v.begin()+n)
#define pb              push_back
#define X               first
#define Y               second
#define scan(i)			if (typeid(i)==typeid(int)) scanf("%d",&i);\
			else    if (typeid(i)==typeid(long long)) scanf("%lld",&i);\
			else    scanf("%s",&i);
#define print(i)		if (typeid(i)==typeid(int)) printf("%d",i);\
			else    if (typeid(i)==typeid(long long)) printf("%lld",i);\
			else    printf("%s",i);
#define nl		printf("\n");

bool isVow(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
typedef long long lint;
char S[1000*1000];
lint indOfMatch[1000*1000];
int n,L;

lint solve()
{
	int m=0,x=0;
	REP(i, L)
	{
		if (!isVow(S[i])) x++;
		else x=0;
		if (x>=n)
		{
			indOfMatch[m++] = i-n+1;
//			cout << i-n+1 << endl;
		}
	}

	lint res = 0;

	if (m>0)
	{

		REP(j, m-1)
		{
			lint i = indOfMatch[j];
			lint k = indOfMatch[j+1]+n-2;
			lint a = k-(i+n-1);
			//		cout << "+ " << 1 +i+a+(i*a) << endl;
			res += 1 +i+a+(i*a);
		}
		res += (1+indOfMatch[m-1])*(1+L-(indOfMatch[m-1]+n));
	}
	return res;
}

int main()
{
	int t; scan(t);
	REP(T,t)
	{
	scan(S);
	L = strlen(S);
	cin >> n;
	cout << "Case #"<<T+1<<": ";
	cout << solve();nl;
	}
	return 0;
}
