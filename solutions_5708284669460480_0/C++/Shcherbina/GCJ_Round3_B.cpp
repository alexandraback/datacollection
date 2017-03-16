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

string keyboard,target;
int K,L,S;
double move;
int find(string s)
{
	int num = 0,i,j;
	bool flag;
	for (i=0; i<S-L+1; i++)
	{
		flag = true;
		for (j=i; j<i+L; j++)
		{
			if (s[j]!=target[j-i])
			{
				flag = false;
				break;
			}
		}
		if (flag) num++;
	}
	return num;
}
double answer;
int Max;
void Go(double p, string current)
{
	if (current.size() == S)
	{
		answer = answer + find(current)*p;
		Max = max(Max,find(current));
		return;
	}
	for (int i=0; i<K; i++)
	{
		current.pb(keyboard[i]);
		Go(p*move,current);
		current.erase(--(current.end()));
	}
}
void Solve(int q)
{
	answer = 0;
	Max = 0;
	cin >> K >> L >> S;
	move = 1.0/K;
	cin >> keyboard;
	cin >> target;
	Go(1.0,"");
	cout.precision(12);
	cout << "Case #" << q+1 << ": " << fixed << Max - answer << "\n";
}
int main()
{
	int q,t;
	cin >> t;
	for (q=0; q<t; q++)	
		Solve(q);
	return 0;
}
