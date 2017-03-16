#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n, s, p;
int h1, h2, v, good, surp;


int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	scanf("%d", &t);

	for(int x=1; x<=t; x++)
	{
		scanf("%d%d%d", &n, &s, &p);

		h1 = 3*p - 2; 
		h2 = h1 - 2;
		
		if(p < 2) h1 = h2 = p;

		good = 0, surp = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &v);
			if(v >= h1) good++;
			else
				if(v >= h2) surp++;
		}

		printf("Case #%d: %d\n", x, good + min(s, surp));
	}
	
	return 0;
}