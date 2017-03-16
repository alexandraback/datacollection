#include<cstdio>
#include<queue>
using namespace std;

struct tribe {
	int n, w, e, s, dd, dp, ds;
	int nexta;
};

priority_queue<tribe> q;

bool operator < (tribe a, tribe b)
{
	return a.nexta > b.nexta;
}
const int M = 401;
int mur[M];
int nmur[M];

int main()
{
int t;
scanf("%d", &t);
for (int tt=1; tt<=t; tt++)
{
	
	int N, i, j;
	scanf("%d", &N);
	for (int i=0; i<N; i++)
	{
		tribe t;
		scanf("%d%d%d%d%d%d%d%d", &t.nexta, &t.n, &t.w, &t.e,
								  &t.s, &t.dd, &t.dp, &t.ds);
		t.e+=200;
		t.w+=200;
		q.push(t);
	}
	int wyn = 0;
	for (i=0; i<M; i++)
		mur[i] = nmur[i] = 0;
	
	int day=-1;
	while(!q.empty())
	{
		tribe t = q.top();
		q.pop();
		if(day != t.nexta)
		{
			day = t.nexta;
			for (i=0; i<M; i++)
				mur[i] = nmur[i];
		}
		
		//attack
		bool goodat = 0;
		for (i=t.w; i<t.e; i++)
		{
			if(t.s > mur[i])
			{
				goodat = 1;
			}
			if(t.s > nmur[i])
			{
				nmur[i] = t.s;
			}
		}
		if(goodat) wyn++;
		
		t.n--;
		if(!t.n) continue;
		t.nexta += t.dd;
		t.e += t.dp;
		t.w += t.dp;
		t.s += t.ds;
		q.push(t);
	}
	printf("Case #%d: ", tt);
	printf("%d\n", wyn);
	
	
	
	
	
			
}
return 0;
}
