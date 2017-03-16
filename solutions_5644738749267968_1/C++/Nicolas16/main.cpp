#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	int N;
	vector<double> v, w;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		v.resize(N);
		w.resize(N);
		
		for(int i = 0; i < N; i++)
		{
			scanf("%lf", &v[i]);
		}
		for(int i = 0; i < N; i++)
		{
			scanf("%lf", &w[i]);
		}
		
		sort(v.begin(), v.end());
		sort(w.begin(), w.end());
		
		int ou = 0;
		int rep2;
		bool fini = false;
		
		for(int i = 0; i < N && !fini; i++)
		{
			while(ou < N && w[ou] < v[i])
			{
				ou++;
			}
			if(ou >= N)
			{
				rep2 = N-i;
				fini = true;
			}
			else ou++;
		}
		if(!fini) rep2 = 0;
		
		ou = 0;
		int rep1 = 0;
		
		for(int i = 0; i < N; i++)
		{
			if(v[i] > w[ou])
			{
				rep1++;
				ou++;
			}
		}
		
		
		printf("%d %d\n", rep1, rep2);
	}


	return 0;
}
