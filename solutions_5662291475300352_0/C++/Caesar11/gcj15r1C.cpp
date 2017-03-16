#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cassert>
#define eps 1e-8
using namespace std;

int dlcmp(double x) {return x<-eps?-1:x>eps;}

struct Node
{
	int pos;
	double speed;

	Node(int a,double b):pos(a),speed(b){}

};

vector<Node>vec;

int main()
{
	int t, ys = 0;

	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("dataC.out","w",stdout);
	scanf("%d",&t);

	while (t--)
	{
		int n;
		scanf("%d",&n);
		vec.clear();
		for (int i=0;i<n;++i)
		{
			int d,h,m;
			scanf("%d%d%d",&d,&h,&m);
			while (h--)
			{
				vec.push_back(Node(d,360.0/m));
				m++;
			}
		}

		n = vec.size();
		assert(n<=2);


		int ans = 0;
		if (n == 2)
		{
			Node a = vec[0], b = vec[1];
			if (a.pos > b.pos) swap(a, b);

			if (dlcmp(a.speed-b.speed) == 0)
			{
				ans = 0;
			}
			else if (dlcmp(a.speed-b.speed) < 0)
			{
				double time1 = (360.0 - a.pos) / a.speed;
				double time2 = (360.0 - b.pos + a.pos) / (b.speed - a.speed);
				if (dlcmp(time1 - time2) < 0) ans = 0;
				else ans = 1;
			}
			else
			{
				double time1 = (360.0 - b.pos) / b.speed;
				double time2 = (b.pos - a.pos) / a.speed;
				double time3 = time2 + 360.0 / (a.speed - b.speed);

				if (dlcmp(time1 - time3) < 0) ans = 0;
				else ans = 1;
			}
		}

		printf("Case #%d: %d\n",++ys,ans);
	}

	return 0;
}

