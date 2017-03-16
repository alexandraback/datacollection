#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct clan{
	int left, right, strength, day;
	const bool operator<(const clan &other) const
	{
		return day > other.day;
	}
	clan(){}
	clan(int l, int r, int s, int d):left(l), right(r), strength(s), day(d){}
};

map<int,int> heightAt;
map<int, vector<clan> > attacks;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		heightAt.clear();
		attacks.clear();
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int d,n,w,e,s,dd,dp,ds;
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			w*=2;e*=2;dp*=2;
			for (int j = 0; j < n; j++)
			{
				attacks[j*dd+d].push_back(clan(j*dp + w, j*dp + e, j*ds+s,j*dd+d));
			}
		}
		int counter = 0;
		int lastDay = -1;
		for (map<int, vector<clan> >::iterator ii = attacks.begin(); ii != attacks.end(); ii++)
		{
			for (int i = 0; i < ii->second.size(); i++)
			{
				clan c = ii->second[i];
				//printf("day %d, attack from %d to %d with strength %d, counter currently %d\n", c.day, c.left, c.right, c.strength, counter);
				for (int i = c.left; i <= c.right; i++)
				{
					if (heightAt[i] < c.strength)
					{
						counter++;
						break;
					}
				}
				//printf("counter now %d\n", counter);
			}
			for (int i = 0; i < ii->second.size(); i++)
			{
				clan c = ii->second[i];
				for (int i = c.left; i <= c.right; i++)
				{
					if (heightAt[i] < c.strength)
					{
						heightAt[i] = c.strength;
					}
				}
			}
		}
		printf("Case #%d: %d\n", t+1, counter);
	}
}