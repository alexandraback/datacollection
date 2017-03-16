#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 15

int t;
int bff[MAX], n;

void print_mask(int mask)
{
	for(int i=n-1; i>=0; --i)
	{
		if(mask & (1 << i)) putchar('1');
		else putchar('0');
	}
}

bool cmp(int a, int b) { return (__builtin_popcount(a) > __builtin_popcount(b)); }

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &bff[i]), bff[i]--;
		}
		
		int sol = 1;
		vector<int> vmask;
		for(int mask = 1; mask < (1 << n); ++mask)
		{
			vmask.pb(mask);
		}
		sort(vmask.begin(), vmask.end(), cmp);

		for(int j=0; j<(int)vmask.size(); ++j)
		{
			int mask = vmask[j];
			
			//print_mask(mask); puts("");
				
			bool can = 1;
			bool can2 = 0;
				
			vector<int> v;
			for(int i=0; can && i<n; ++i)
			{
				if((mask & (1 << i)) && !(mask & (1 << bff[i]))) can = 0;
				if(mask & (1 << i)) v.pb(i);
			}
			
			if(!can) continue;

			do
			{
				bool lcan = 1;
				int nv = v.size();
				for(int i=0; lcan && i<nv; ++i)
				{
					int next = (i+1)%nv;
					int last = (i-1);
					if(last < 0) last = nv-1;

					if((v[last] != bff[v[i]]) && (v[next] != bff[v[i]])) lcan = 0;
				}
				
				if(lcan)
				{
					can2 = 1;
					sol = v.size();
					break;
				}

			}while(next_permutation(v.begin(), v.end()));

			if(can2 == 1) break;
		}

		printf("Case #%d: %d\n", tc, sol);
	}

	return 0;
}
