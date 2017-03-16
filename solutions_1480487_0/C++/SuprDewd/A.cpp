#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d", &n);

		int s = 0;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) scanf("%d", arr + i), s += arr[i];

		cout << "Case #" << t + 1 << ":";

		for (int i = 0; i < n; i++)
		{
			double cur = 100 * (1 - (n - 1) * static_cast<double>(arr[i]) / s);
			cout << " " << setprecision(6) << fixed << cur;
		}

		cout << endl;
	}

	return 0;
}