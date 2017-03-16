//#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <ctime>
 
#define MAXN 100000
#define INF 1000000000
#define pi 3.1415926535
#define LL long long
#define U unsigned
#define mp make_pair
#define pb push_back
#define eps 0.000000001
#define pii pair <int,int>
#define X first
#define Y second
#define MOD 1000000007
#define MOD2 1000000009
 
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

void Solve()
{
	int i,n,temp,cu=0,answer=0;
	string s;
	cin >> n;
	cin >> s;
	for (i=0; i<n+1; i++)
	{
		if (i>cu)
		{
			cu++;
			answer++;
		}
		temp=s[i]-'0';
		cu+=temp;
	}
	cout << answer << "\n";
}
int main()
{
	int q,t;
	cin >> t;
	for (q=0; q<t; q++)
	{
		cout << "Case #" << q+1 << ": ";
		Solve();
	}
	return 0;
}
