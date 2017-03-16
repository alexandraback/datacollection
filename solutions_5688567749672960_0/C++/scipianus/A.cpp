#include <iostream>
#include <cassert>
#include <fstream>
#include <queue>
using namespace std;
int T, n, best[1000100], nr[10], nrcif, curr;
queue <int> Q;
bool bagat[1000100];

void Baga(int x)
{
	int now = 0;
	while(x)
	{
		now = now * 10 + x % 10;
		x /= 10;
	}
	if(now <= 1000000 && best[now] > curr + 1)
	{
		best[now] = curr + 1;
		if(!bagat[now])
		{
			bagat[now] = true;
			Q.push(now);
		}
	}
}

int main()
{
	int i, now;
	ifstream fin("A.in");
	ofstream fout("A.out");
	fin >> T;
	for(i = 1; i <= 1000000; ++i)
		best[i] = 1000000000;
	best[1] = 1;
	bagat[1] = true;
	Q.push(1);
	while(!Q.empty())
	{
		now = Q.front();
		Q.pop();
		if(now + 1 <= 1000000 && best[now + 1] > best[now] + 1)
		{
			best[now + 1] = best[now] + 1;
			if(!bagat[now + 1])
			{
				bagat[now + 1] = true;
				Q.push(now + 1);
			}
		}
		curr = best[now];
		bagat[now] = false;
		Baga(now);
	}
	for(int t = 1; t <= T; ++t)
	{
		fin >> n;
		assert(1 <= n && n <= 1000000);
		fout << "Case #" << t << ": " << best[n] << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
