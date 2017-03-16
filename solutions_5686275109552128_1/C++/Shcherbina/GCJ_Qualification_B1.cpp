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
	int i,D,answer,write=INF;
	cin >> D;
	int a[D];
	for (i=0; i<D; i++)
	{
		cin >> a[i];
	}
	for (int lvl=1; lvl<=1000; lvl++)
	{
		answer=lvl;
		for (i=0; i<D; i++)
		{
			answer+=(a[i]/lvl+(a[i]%lvl==0 ? 0:1)-1);
		}
		write=min(answer,write);
	}
	cout << write << "\n";
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
