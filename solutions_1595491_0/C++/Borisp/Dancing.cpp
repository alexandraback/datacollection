#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int n, surprising, p;
		cin >> n >> surprising >> p;
		int cnt = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.rbegin(), v.rend());
		int idx = 0;
		while(idx < n && v[idx] > (p - 1) * 3)
		{
			cnt++;
			idx++;
		}
		while(idx < n && surprising > 0 && v[idx] > max(0, (p - 2)) * 3  + 1)
		{
			cnt++;
			idx++;
			surprising--;
		}
		cout << cnt << endl;
	}
	return 0;
}
