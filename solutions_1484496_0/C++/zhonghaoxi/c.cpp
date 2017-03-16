#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<map>

using namespace std;

#ifdef unix
#define BIG "%lld"
#else
#define BIG "%I64d"
#endif

long long z[600];

struct sb
{
	priority_queue<long long> heap;
	int way;
	sb()
	{
		while (heap.size())
			heap.pop();
		way=0;
	}
};

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int y=1;y<=t;y++)
	{
		printf("Case #%d:\n",y);
		int n;
		scanf("%d",&n);
		for (int a=1;a<=n;a++)
			scanf(BIG,&z[a]);
		map<long long,sb> ma,other;
		ma[0].way=1;
		bool find=false;
		for (int a=1;a<=n;a++)
		{
			other=ma;
			for (map<long long,sb>::iterator b=other.begin();b!=other.end();b++)
			{
				ma[b->first+z[a]].way+=b->second.way;
				if (ma[b->first+z[a]].way>=2)
				{
					while (ma[b->first+z[a]].heap.size())
					{
						printf(BIG " ",ma[b->first+z[a]].heap.top());
						ma[b->first+z[a]].heap.pop();
					}
					printf("\n");
					while (b->second.heap.size())
					{
						printf(BIG " ",b->second.heap.top());
						b->second.heap.pop();
					}
					printf(BIG "\n",z[a]);
					find=true;
					break;
				}
				priority_queue<long long> orz=b->second.heap;
				while (orz.size())
				{
					ma[b->first+z[a]].heap.push(orz.top());
					orz.pop();
				}
				ma[b->first+z[a]].heap.push(z[a]);
			}
			if (find) break;
		}
	}

	return 0;
}
