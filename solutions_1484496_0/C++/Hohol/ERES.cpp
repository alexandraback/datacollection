#pragma comment(linker,"/STACK:300000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4800)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <deque>
#include <bitset>
#include <numeric>
#include <ctime>
#include <queue>

using namespace std;

#define show(x) cout << #x << " = " << (x) << endl;
#define fori(i,n) for(int i = 0; i < (n); i++)
#define forab(i,a,b) for(int i = (a); i <= (b); i++)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()
const double pi = 3.1415926535897932384626433832795;
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; };
template<class T> T sqr(const T &x) { return x * x; }
typedef pair<int,int> ii;
typedef long long ll;
///////////////////////////////////////

int n;
vector<int> a(n);
int t[10000000];

void print(int x)
{
	while(t[x] != -1)
	{
		cout << x-t[x] << ' ';
		x = t[x];
	}
}

void solve()
{	
	cin >> n;
	a.resize(n);
	fori(i,n)
		cin >> a[i];
	memset(t,-1,sizeof(t));
	fori(i,n)
		for(int j = 20*100000; j >= 0; j--)
			if(j == 0 || t[j] != -1)
			{
				if(t[j+a[i]] == -1)
					t[j+a[i]] = j;
				else
				{
					print(j+a[i]);
					cout << endl;
					cout << a[i] << ' ';
					print(j);
					return;
				}
			}
	cout << "Impossible";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int testCnt;
	cin >> testCnt;
	for(int testNo = 1; testNo <= testCnt; testNo++)
	{
		cout << "Case #" << testNo << ':' << endl;
		solve();
		cout << endl;
	}
}