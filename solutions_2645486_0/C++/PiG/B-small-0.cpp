#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

typedef struct act
{
	ULL val;
	int pos;
}Act;

ULL data[10010];
vector<Act> stack;
ULL E, R;
int N;
ULL ans;

bool comp(Act a, Act b)
{
	return (a.val < b.val) || (a.val == b.val && a.pos < b.pos);
}

void solve(int l, int r, ULL Emax)
{
	if (l > r)
		return;
	if (l == r)
	{
		ans += data[l] * min(E, Emax - R);
		return;
	}
	int i;
	for (i = stack.size() - 1; i >= 0; --i)
		if (stack[i].pos >= l && stack[i].pos <= r)
			break;
	int u = stack[i].pos;
	if (i == stack.size() - 1)
		stack.pop_back();
	ULL curE = min(E, Emax - R * (r - u + 1));
	ans += curE * data[u];
	solve(l, u - 1, Emax - R * (r - u) - curE);
	solve(u + 1, r, R * (r - u + 1));
}

int main()
{
	ifstream Input("file.in");
	ofstream Output("file.out");
	int T;
	Input >> T;
	int kase = 0;
	while ((++kase) <= T)
	{
		stack.clear();
		ans = 0;
		Input >> E >> R >> N;
		int i;
		for (i = 0; i < N; ++i)
		{
			Input >> data[i];
			Act temp;
			temp.pos = i;
			temp.val = data[i];
			stack.push_back(temp);
		}
		sort(stack.begin(), stack.end(), comp);
		solve(0, N - 1, E + N * R);
		Output << "Case #" << kase << ": " << ans << endl;
	}
	return 0;
}

