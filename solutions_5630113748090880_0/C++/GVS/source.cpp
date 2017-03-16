
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
int u[3500];

int main()
{
	freopen("B-small-attempt0.in" , "r" , stdin);
	freopen("B-small-attempt0.out" , "w" , stdout);
	
	int testcnt , t;
	cin>>testcnt;
	for (t = 1; t <= testcnt; t++)
	{
		cin>>n;
		for (i = 1; i <= 2500; i++)
			u[i] = 0;
		for (i = 0; i < 2 * n - 1; i++)
		{
			for (j = 0 ;j < n; j++)
			{
				int x;
				cin>>x;
				u[x]++;
			}
		}
		
		cout<<"Case #"<<t<<":";
		
		for (i = 1; i <= 2500; i++)
			if (u[i] & 1)
				cout<<" "<<i;
		cout<<endl;
		
	}
	return 0;
}