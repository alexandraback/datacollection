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

int V;
bool check(vector <bool> coll)
{
	int i,S=0;
	for (i=1; i<=V; i++)
	{
		if (coll[i])
		{
			if (i<=S+1)
			{
				S+=i;
			}
			else
			{
				return false;
			}
		}
	}
	return S>=V;
}
bool answer;
void Go(vector <bool> coll, int left)
{
	if (answer) return;
	if (left==0)
	{
		if (check(coll)) answer = true;
		return;
	}
	for (int i=1; i<=V; i++)
	{
		if (!coll[i]) 
		{
			coll[i]=true;
			Go(coll,left-1);
			coll[i]=false;
		}
	}
}
void Solve(int q)
{
	answer = false;
	int C,D,i,x;
	cin >> C >> D >> V;
	vector <bool> coll(V+1,false);
	for (i=0; i<D; i++)
	{
		cin >> x;
		coll[x]=true;
	}
	if (check(coll))
	{
		cout << "Case #" << q+1 << ": "<< 0 << "\n";
		return;
	}
	for (i=1; i<=5; i++)
	{
		Go(coll,i);
		if (answer)
		{
			cout << "Case #" << q+1 << ": "<< i << "\n";
			return;
		}
	}
}
int main()
{
	int q,t;
	cin >> t;
	for (q=0; q<t; q++)
		Solve(q);
	return 0;
}
