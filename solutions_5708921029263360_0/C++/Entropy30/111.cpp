#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(x) x*x



using namespace std;


main()
{
    freopen("C-small-attempt6.in","r",stdin);
    freopen("C.out", "w", stdout);
    ios::sync_with_stdio(0);
    

    int T;
    cin >> T;

	
    for(int t = 0; t < T; t++)
    {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		vector<vector<int> > anss;
		
		for(int j = 0; j < J; j++)
			for(int p = 0; p < P; p++)
				for(int s = 0; s < S; s++)
				{
					vector<int> sample(3);
					sample[0] = j;
					sample[1] = p;
					sample[2] = s;
					anss.push_back(sample);
				}
		
		int best_ans = 0;
		int best_mask = 0;
		int jp[J][P];
		int js[J][S];
		int ps[P][S];
		
		for(int i = 1; i < (1 << anss.size()); i++)
		{
			if(__builtin_popcount(i) <= best_ans)
				continue;
			
			memset(jp, 0, sizeof(jp));
			memset(js, 0, sizeof(js));
			memset(ps, 0, sizeof(ps));
			int ans = 0;
			int fit = 1;
			for(int j = 1, k = 0; j < (1 << anss.size()); j *= 2, k++)
				if(j & i)
				{
					
					int j = anss[k][0];
					int p = anss[k][1];
					int s = anss[k][2];
					
					if((jp[j][p] < K) && (js[j][s] < K) && (ps[p][s] < K))
					{
						jp[j][p]++;
						js[j][s]++;
						ps[p][s]++;
						ans++;
					}
					else
					{
						fit = 0;
						break;
					}
				}
				
			if(fit == 1)
				if(ans > best_ans)
				{
					best_ans = ans;
					best_mask = i;
				}
		}
		
		cout << "Case #" << t + 1 << ": " << best_ans << endl;
		for(int j = 1, k = 0; j < (1 << anss.size()); j *= 2, k++)
			if(j & best_mask)
			{
				cout << anss[k][0] + 1 << " " << anss[k][1] + 1 << " " << anss[k][2] + 1 << endl;
			}
					
		
		
	}

    return 0;
}
