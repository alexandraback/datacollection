
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:160777216")
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstring>

#define VI vector<int>
#define PII pair<int,int>
#define MP make_pair
#define INF 1000000000000000000LL
#define eps 1e-9

#define ll long long
#define f0(i,n) for (i = 0; i < n; i++)

using namespace std;

int i , j , n, m , k;

int main()
{
	freopen("A-large.in" , "r" , stdin);
	freopen("A-large.out" , "w" , stdout);
	
	int testcnt , t;
	cin>>testcnt;
	for (t = 1; t <= testcnt; t++)
	{
		string s;
		string ans;
		cin>>s;
		for (i = 0; i < s.size(); i++)
		{
			string tmp1 = ans;
			string tmp2 = ans;
			tmp1 = tmp1 + s[i];
			tmp2 = s[i] + tmp2;
			ans = max(tmp1 , tmp2);
		}
		

		cout<<"Case #"<<t<<": ";
		cout<<ans<<endl;
	}
	return 0;
}