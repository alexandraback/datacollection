#if 1
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <cstring>
#include <ctime>
#include <unordered_map>

using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back

typedef pair<int, int> pii ;
typedef long long LL;
typedef long double LD;
typedef vector<int> vi;

const LL inf = 1e9;
const LD eps = 1e-9;


LL badSolve(int a, int b, int k)
{
	LL cnt = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((i & j) < k)
				cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int q = 0; q < T; q++)
	{
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		cout << "Case #" << q + 1 << ": ";
		cout << badSolve(a, b, k) << endl;
	}

    return 0;
}
#endif