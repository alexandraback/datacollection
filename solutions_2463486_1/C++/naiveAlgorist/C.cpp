/*
 	C++ Template
	Pradeep George Mathias
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define DREP(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())

int totalCases, testNum;
vector <long long> fsqr;

bool isPalen(long long val)
{
	vector <int> digs;
	while(val > 0)
	{
		digs.push_back(val % 10);
		val /= 10;
	}
	for(int i = 0, j = digs.size()-1; i < j; i++, j--)
		if(digs[i] != digs[j])
			return false;
	return true;
}

void preprocess()
{
	for(int i = 1; i <= 10000000; i++)
		if(isPalen(i) && isPalen(i * 1ll * i))
			fsqr.push_back(i* 1ll * i);
}

long long A, B;
bool input()
{
	sl(A);
	sl(B);
	return true;
}

void solve()
{
	printf("Case #%d: %d\n", testNum, INDEX(fsqr, B+1) - INDEX(fsqr, A));
}

int main()
{
	preprocess();
	cerr << "preprocessing dones\n";
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
