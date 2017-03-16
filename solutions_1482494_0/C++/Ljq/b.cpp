#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>


using namespace std;

const int MAXN = 1024;

struct sNode
{
	int a, b;
	int w;
};


int n;
vector <sNode> v;

void Work()
{
	cin >> n;
	sNode sn;
	v.clear();
	for (int i = 0; i < n; i ++)
	{
		cin >> sn.a >> sn.b;
		sn.w = 0;
		v.push_back(sn);
	}

	int score = 0, tot = 0;

	for (; score < 2 * n;)
	{
		int ls = score;

		for (int i = 0; i < v.size(); i ++)
			if (v[i].b <= score)
			{
				score += 2 - v[i].w;
				tot ++;
		//		cout << v[i].a << " " << v[i].b << endl;
				swap(v[i], v[v.size()-1]);
				i --;
				v.pop_back();
			}

		if (score > ls)
			continue;

		int d = -1, t = -1;
		for (int i = 0; i < v.size(); i ++)
			if (v[i].a <= score && v[i].w == 0)
				if (v[i].b > d)
				{
					d = v[i].b;
					t = i;
				}

		if (t >= 0)
		{
	//		cout << v[t].a << " " << v[t].b << " " << 1 << endl;
			v[t].w = 1;
			score ++;
			tot ++;
		}


		if (ls == score)
		{
			cout << "Too Bad" << endl;
			return;
		}
	}

	cout << tot << endl;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int k = 1; k <= T; k ++)
	{
		cout << "Case #" << k << ": ";
		Work();
	}

	return 0;
}