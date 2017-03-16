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

void Solve(LL q)
{
	LL i,x,C,D,V;
	cin >> C >> D >> V;
	vector <LL> coll;
	for (i=0; i<D; i++)
	{
		cin >> x;
		coll.pb(x);
	}
	sort(coll.begin(),coll.end());
	LL S=0,answer = 0;;
	for (i=0; i<D; i++)
	{
		if (coll[i]<=S+1)
		{
			S += coll[i] * C;
		}
		else
		{
			S += (S+1) * C;
			i--;
			answer++;
		}
		if (S>=V) break;
	}
	while (S<V)
	{
		answer++;
		S += (S+1)*C;
	}
	cout << "Case #" << q+1 << ": "<< answer << "\n";
}
int main()
{
	LL q,t;
	cin >> t;
	for (q=0; q<t; q++)
		Solve(q);
	return 0;
}
