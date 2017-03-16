#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct Attack
{
	int w, e, s;
};
// Day, attack


int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		map<int, int> wall;
		map<int, vector<Attack>> attacks;
		
		int N;
		scanf("%d", &N);
		for(int j=0;j<N;j++)
		{
			int d,n,w,e,s, delta_d, delta_p, delta_s;
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
			
			while(n--)
			{
				Attack att;
				att.w = w;
				att.e = e;
				att.s = s;
				attacks[d].push_back(att);
				
				d+= delta_d;
				w+= delta_p;
				e+= delta_p;
				s+= delta_s;
			}
		}
		
		int sol=0;
		for(auto it1 = attacks.begin(); it1!=attacks.end(); it1++)
		{
			//printf("Day %d\n", it1->first);
			for(Attack a : it1->second)
			{
				bool success = false;
				//printf("Attack [%d-%d] S=%d\n", a.w, a.e, a.s);
				for(int x = a.w; x<a.e; x++)
				{
					if(wall[x]<a.s)
					{
						success = true;
						break;
					}
				}
				if(success) sol++;
			}
			
			for(Attack a : it1->second)
			{
				bool success = false;
				//printf("Attack [%d-%d] S=%d\n", a.w, a.e, a.s);
				for(int x = a.w; x<a.e; x++)
				{
					wall[x] = max(wall[x], a.s);
				}
			}
		}
		
		printf("Case #%d: %d\n", i, sol);
	}
}
