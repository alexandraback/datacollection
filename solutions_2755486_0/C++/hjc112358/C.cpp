#include <stdio.h>
#include <queue>

using namespace std;

#define MM 676060
int T,N;

struct nomadic
{
	int d;
	int n;
	int w,e;
	int s;
	int d_d;
	int d_p;
	int d_s;
};
bool operator < (struct nomadic a, struct nomadic b)
{
	return a.d > b.d;
}
typedef struct nomadic s_nomadic;

struct defense
{
	int height;
	int w,e;
};
bool operator < (struct defense a, struct defense b)
{
	return a.height > b.height;
}
typedef struct defense s_defense;

int gw[MM*4+10];

inline int GetHeight(double n)
{
	int t = n*2;
	return gw[MM+t];
}

inline void SetHeight(double n, int h)
{
	int t = n*2;
	gw[t+MM] = h;
}

int main(int argc, char *argv[])
{
	int i,k;
	double j;
	int count;
	int day;
	bool flag;
	priority_queue<s_nomadic> pq;
	priority_queue<s_defense> pq_d;
	s_nomadic sn;
	s_defense sd;
	scanf("%d\n", &T);
	for (i=0;i<T;i++)
	{
		printf("Case #%d: ", i+1);
		memset(gw, 0, sizeof(int)*(MM*4+10));
		while(!pq.empty()) pq.pop();
		scanf("%d\n", &N);
		for (k=0;k<N;k++)
		{
			scanf("%d %d %d %d %d %d %d %d \n", &sn.d, &sn.n, &sn.w, &sn.e, &sn.s, &sn.d_d, &sn.d_p, &sn.d_s);
			pq.push(sn);
		}
		count = 0;
		while(!pq.empty())
		{
			day = pq.top().d;
			while (!pq.empty() && pq.top().d==day)
			{
				sn = pq.top();
				pq.pop();
				day = sn.d;
				// check attack
				flag = false;
				for (j=sn.w;j<=sn.e;j+=0.5)
				{
					if (sn.s>GetHeight(j))
					{
						flag = true;
						j = sn.e;
					}
				}
				if (flag)
				{
					count++;
					sd.height = sn.s;
					sd.w = sn.w;
					sd.e = sn.e;
					pq_d.push(sd);
				}
				sn.n--;
				if (sn.n)
				{
					sn.d += sn.d_d;
					sn.s += sn.d_s;
					sn.w += sn.d_p;
					sn.e += sn.d_p;
					pq.push(sn);
				}
			}
			// add gw height
			while (!pq_d.empty())
			{
				sd = pq_d.top();
				pq_d.pop();
				for (j=sd.w;j<=sd.e;j+=0.5)
				{
					if (GetHeight(j)<sd.height)
						SetHeight(j, sd.height);
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}