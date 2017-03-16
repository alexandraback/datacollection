#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int cn=1;cn<=t;cn++)
	{
		int n;
		scanf("%d", &n);
		
		vector<double> naomis, kens;
		double tmp;
		for(int i=0;i<n;i++)
		{
			scanf("%lf", &tmp);
			naomis.push_back(tmp);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf", &tmp);
			kens.push_back(tmp);
		}
		
		sort(naomis.begin(), naomis.end());
		sort(kens.begin(), kens.end());
		
		int war_points = 0;
		{
			int j=0;
			for(int i=0;i<n;i++)
			{
				while(j<n && kens[j]<naomis[i]) j++;
				if(j==n)
				{
					war_points = n-i;
					break;
				}			
				j++;
			}
		}
		
		int dwar_points = 0;
		{
			int j=0;
			for(int i=0;i<n;i++)
			{
				while(i-j>=0 && naomis[i] < kens[i-j]) j++;
			}
			dwar_points = n-j;
		}
		
		printf("Case #%d: %d %d\n", cn, dwar_points, war_points);
	}
}
