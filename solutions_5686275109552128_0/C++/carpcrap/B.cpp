#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int count[2000];
	int ll[2000];

	// preprocess
	// [original][maxChildEat]
	int need[1001][1001];
	for(int i=1; i<=1000; i++)
	{
		for(int j=0; j<=1000; j++)
			need[j][i] = j-1;
		for(int j=0; j<=i; j++) need[j][i] = 0;
		for(int j=i+1; j<=1000; j++)
			for(int k = 1; k<=j/2+1; k++)
				if(need[k][i] + need[j-k][i] +1< need[j][i])
					need[j][i] = need[k][i] + need[j-k][i] +1;
				
	}
	

	for(int t=1; t<=T; t++)
	{
		int D;
		cin >> D;
		for(int i=0; i<2000; i++) count[i] = 0;
		int P;
		int minn = 0;
		for(int i=0; i<D; i++)
		{
			cin >> P;
			count[P]++;
			ll[i] = P;
			minn = (P>minn)?P:minn;
		}

/*
		int special = 0;
		for(int i=minn;i>=1; i--)
		{
			if(count[i]==0) continue;
			if(i+special < minn) minn = i+special;
			special += count[i];
			count[i/2] += count[i];
			count[i/2 + i%2] += count[i];
		}
*/

		int ret = 0;
		for(int i=2; i<minn; i++)
		{
			int special = 0;
			for(int j=0; j<D; j++)
			{
				special += need[ll[j]][i];
			}
			if( i + special < minn) minn = i+special;
		}
		printf("CASE #%d: %d\n", t, minn);
	}
}
