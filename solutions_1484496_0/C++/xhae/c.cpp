#include <cstdio>

int data[20];
int n;

int ansRoute[2][20];
int ansN[2];
bool found;

void backtr(int ind, int sum)
{
	if(found) return;

	if(sum==0)
	{
		found=true;
		return;
	}

	if(ind==n) return;
	
	backtr(ind+1, sum);
	if(found) return;
	
	ansRoute[0][ansN[0]++]=ind;
	backtr(ind+1, sum+data[ind]);
	if(found) return;
	ansN[0]--;

	ansRoute[1][ansN[1]++]=ind;
	backtr(ind+1, sum-data[ind]);
	if(found) return;
	ansN[1]--;

	return;
}	

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%d", data+i);

		ansN[0] = ansN[1] = 0;
		found = false;
		for(int i=0;i<n;i++) 
		{
			ansN[0] = 1;
			ansN[1] = 0;
			ansRoute[0][0] = i;
			backtr(i+1, data[i]);
			if(found) break;
		}

		printf("Case #%d:", caseN);
		if(found==false) printf(" Impossible\n");
		else
		{
			printf("\n");
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<ansN[i];j++)
				{
					if(j) printf(" ");
					printf("%d", data[ansRoute[i][j]]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
