/*******************************************************************************
IF YOU ARE LOOKING THIS YOU ARE RIGHT WAY
*******************************************************************************/
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 100005
typedef pair<int,int> p;
typedef pair<int,p> pii;
#define fi first
#define se second
#define pb push_back
#define s(a) scanf("%d",&a);
#define mem(a) memset(a,0,sizeof(0))
vector<int> v;
void good(string s,int base)
{
	int len = s.length();
	long long t = 1;
	long long ans = 0;
	for(int i = len - 1 ; i >= 0 ; i--)
	{
		if(s[i] == '1')
		{
			ans += t;
		}
		t *= base;
	}
	printf("%lld",ans);
}

void solve(int i,int N)
{
	string s;
//	printf("for : %d  : ",i);
	while(i > 0)
	{
		s += i%2 + '0';
		i /= 2;
	}
	reverse(s.begin(),s.end());
//	cout << "HEY " << s << " : : ";
	s += "1";
	
	int len = s.length();
	int t = N - 2 * len;
	string temp = "";
	while(t--)
		temp += "0";
	string ans = s + temp + s;
	cout << ans << " ";
	for(int i = 2 ; i < 11 ; i++)
	{
		good(s,i);
		if(i!=10)
			printf(" ");	
	}
}

int main()
{
	int T;
	scanf("%d",&T);
//	T = 1;
	printf("Case #%d:\n",1);
	while(T--)
	{
		int N,J;
		int cnt = 0;
		int till;
		scanf("%d%d",&N,&J);
		if(N==16)
			till = 50;
		else
			till = 500;
		for(int i = 1 ; cnt!=J & i < MAX;i++,cnt++)
		{
			solve(i,N);
			printf("\n");
		}
	}
	return 0;
}
