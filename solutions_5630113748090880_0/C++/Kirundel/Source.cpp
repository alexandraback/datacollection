#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <ctime>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int>a(2501);
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		a.clear();
		a.resize(2501);
		for (int j = 0; j < l*(2*l-1); j++)
		{
			int k;
			cin >> k;
			a[k]++;
		}
		vector<int>result;
		for (int j = 1; j < a.size(); j++)
		{
			if (a[j] % 2 != 0) { result.push_back(j); }
		}
		cout << "Case #"<<i+1<<": " ;
		for (int j = 0; j < result.size(); j++)
		{
			cout << result[j] << " ";
		}
		cout << endl;
	}
	return 0;
}