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
string x;
int N, L;
string vowel;

long long ans;

void preprocess()
{
	vowel = "aeiou";
}

bool input()
{
	cin >> x;
	cin >> N;
	return true;
}

bool isconsonant(char x)
{
	return (find(vowel.begin(), vowel.end(), x) == vowel.end());
}

void solve()
{
	ans = 0;
	
	int i, j;
	i = 0, j = 0;
	x.push_back('a');
	L = x.length();
	int cur = 0;
	while(j < L)
	{
		if(cur < N)
		{
			if(isconsonant(x[j]))
				cur++;
			else 
				cur = 0;
			j++;
		}
		else 
		{
			ans += L-j;
			i++;
			if(j - i < N)
				cur--;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		printf("Case #%d: ", testNum);
		solve();
	}
}
