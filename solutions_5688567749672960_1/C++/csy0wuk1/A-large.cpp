#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

ifstream input;
ofstream output;

typedef long long LL;

unordered_map<LL, LL> dist;
unordered_map<LL, bool> b;

int flip(LL x)
{
	LL ret = 0;
	while (x)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

int leading(LL x)
{
	while (x / 10) x /= 10;
	return x;
}

LL Nine (LL x)
{
	LL ret = 0;
	while (x / 10)
	{
		x /= 10;
		ret = ret * 10 + 9;
	}
	if (!ret) ret = 1;
	return ret;
}

bool vst(LL x)
{
	if (b.find(x) == b.end()) return false;
	return b[x];
}

void visit(LL x)
{
	b[x] = true;
}

void unvisit(LL x)
{
	b[x] = false;
}

int f, r;
LL Q[10000000];

void edge(LL x, LL y, LL len)
{
	if (x < y) return;
	LL newLen = dist[x] + len;
	if (dist.find(y)==dist.end() || newLen < dist[y])
	{
		dist[y] = newLen;
		if (!vst(y))
		{
			Q[++r] = y;
			visit(y);
		}
	}
}

LL SPFA(LL N)
{
	dist.clear();
	b.clear();
	dist[N] = 1;
	visit(N);
	f = 0, r = 0;
	Q[0] = N;
	while (f <= r)
	{
		LL x = Q[f++];
		unvisit(x);
		if (leading(x) == 1 && x > 1)
		{
			LL nine = Nine(x);
			edge(x, nine, x - nine);
		}
		if (x < 10) edge(x, 1, x - 1);
		else
		{
			LL digit = 1;
			bool flat = true;
			while (digit*10 < x)
			{
				digit *= 10;
				if (x % digit == 0) continue;
				flat = false;
				LL tmp = x / digit * digit + 1;
				edge(x, flip(tmp), x - tmp + 1);
			}
			if (x % 10 == 0)
			{
				edge(x, x - 1, 1);
			}
		}
	}
	return dist[1];
}

void singleCase(int case_num)
{
	LL N;
	input >> N;
	output << "Case #" << case_num << ": " << SPFA(N) << endl;
}

int main()
{
	input.open("A-large.in");
	output.open("A.out");
	dist.max_load_factor(0.3);
	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i + 1);

	return 0;
}