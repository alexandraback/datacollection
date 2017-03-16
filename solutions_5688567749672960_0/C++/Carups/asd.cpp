#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <vector> 
#include <sstream> 
#include <string> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <queue>
using namespace std; 
#pragma comment(linker, "/STACK:256000000") 
#define mp make_pair 
#define pb push_back 
#define all(C) (C).begin(), (C).end() 
#define sz(C) (int)(C).size() 
#define PRIME 1103 
#define PRIME1 31415 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef pair<int, int> pii; 
typedef vector<int> vi; 
typedef vector<vector<int> > vvi; 
//------------------------------------------------------------ 
const int N = 1000010;
priority_queue<pii> qq;
int n;
int mas[N];

int solve()
{
	scanf("%d", &n);
	return mas[n];
	
}
int main()
{
   // ios_base::sync_with_stdio(false);cin.tie(0);
	
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	for(int i = 0; i < N; ++i)
		mas[i] = 1e9;
	mas[1] = 1;
	for(int i = 1; i < N - 2; ++i)
	{
		mas[i + 1] = min(mas[i + 1], mas[i] + 1);
		int k = 0;
		int t = i;
		while(t)
		{
			k *= 10;
			k += t % 10;
			t /= 10;
		}
		if (k >= N)
			continue;
		mas[k] = min(mas[k], mas[i] + 1);
	}
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("Case #%d: %d\n", i + 1, solve());
	}
	
}