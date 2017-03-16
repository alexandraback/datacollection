#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int cnt[100000];

void f() 
{
	int n;
	cin >> n;
	for (int i = 0; i < 10000; ++i )
		cnt[i] = 0;
	for (int i = 0; i < 2*n-1; ++i ) {
		for (int j = 0; j < n; ++j ) 
		{
			int m;
			cin >> m;
			++cnt[m];
		}
	}
	for (int i = 0; i < 10000; ++i )
		if (cnt[i]&1)
			cout << " " << i;
	cout << endl;
}

int main() 
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int n_test;
	cin >> n_test;
	for (int i_test = 0; i_test < n_test; ++i_test) 
	{
		cout << "Case #" << i_test+1 << ":";
		f();
	}
}