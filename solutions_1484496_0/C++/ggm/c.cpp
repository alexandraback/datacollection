#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
const int LEN = 2000000;

using namespace std;
vector<int> number[LEN+5];
vector<int> input;

void print(int status) {
	int l=0;
	while(status)
	{
		if(status % 2 == 1)
		{	
			printf("%d",input[l]);
			if(status == 1) printf("\n");
			else printf(" ");
		}
		status >>= 1;
		l+=1;
	}
}

void solve(){
	for(int i=0;i<=LEN;i++)
	{
		if(number[i].size() <= 1) continue;
		int csize = number[i].size();
		for(int j=0;j<csize;j++)
		{
			for(int k=0;k<csize;k++)
			{
				if((number[i][j] & number[i][k]) == 0)
				{
					print(number[i][j]);
					print(number[i][k]);
					return;
				}
			}
		}		
	}
}
int main()
{
	int ncas;
	scanf("%d",&ncas);
	for(int t=1;t<=ncas;t++)
	{
		int n;
		scanf("%d", &n);
		for(int i=0;i<=LEN;i++)
			number[i].clear();
		input.resize(n);
		for(int i=0;i<n;i++)
			scanf("%d",&input[i]);

		printf("Case #%d:",t);
		for(int i=0;i<(1<<n);i++)
		{
			int status = i;
			int sum = 0;
			int k = 0;
			while(status)
			{
				if(status % 2 == 1) 
					sum += input[k];
				status >>= 1;
				k+=1;
			}
			number[sum].push_back(i);
		}
		puts("");
		solve();
	}
	return 0;
}
