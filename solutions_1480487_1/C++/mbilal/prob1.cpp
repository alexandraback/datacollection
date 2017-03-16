#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	double equationMatrix[212][212];
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++){
		int n, judge;
		scanf("%d",&n);
		vector<int> score;
		for(int i=0; i<n; i++){
			scanf("%d", &judge);
			score.push_back(judge);
		}
		
		int sum = 0;
		for(int i=0; i<n; i++)
			sum += score[i];
		for(int i=0; i<n-1; i++){
			for(int j=0; j<n+1; j++){
				equationMatrix[i][j] = 0;
				if(i == j)
					equationMatrix[i][j] = 1;
				else if(j == i+1)
					equationMatrix[i][j] = -1;
			}
			double a = score[i];
			double b = score[i+1];
			
			equationMatrix[i][n] = (b-a)/(double)sum;
		}
		
		for(int i=0; i<n+1; i++)
			equationMatrix[n-1][i] = 1;
			
		int nVar = n;
		for (int i = 0; i < nVar; i++)
		{
			//If the element is zero, make it non zero by row operation
			if (equationMatrix[i][i] == 0)
			{
			int j;
			for (j = i+1; j < nVar; j++)
			{
            if (equationMatrix[j][ i] != 0)
            {
                for (int k = i; k < nVar + 1; k++)
                    equationMatrix[i][k] += equationMatrix[j][k];
                break;
            }
        }
    }

    //make the diagonal element as 1
    for (int k = nVar; k >= i; k--)
        equationMatrix[i][k] /= equationMatrix[i][i];

    //use row operation to make upper matrix
    for (int j = i+1; j < nVar; j++)
    {
        for (int k = nVar; k >= i; k--)
            equationMatrix[j][k] -= equationMatrix[i][k]*equationMatrix[j][i];
    }
}

//It is to make diagonal matrix
for (int i = nVar-1; i > 0; i--)
{
    for(int j=i-1; j>=0; j--)
    {
        equationMatrix[j][nVar] -= equationMatrix[j][i] * equationMatrix[i][nVar];
        equationMatrix[j][i] = 0;
    }
}

		double ans[212];
		double negsum = 0, negvals = 0;
	for(int j=0; j < nVar; j++){
    ans[j] = equationMatrix[j][nVar];
		if(ans[j]<0){
			negsum += ans[j];
			negvals++;
			
		}
	}
	
	if(negsum != 0){
			negvals = n - negvals;
	negsum = negsum/negvals;
	for(int i=0; i<n; i++)
		if(ans[i] < 0) ans[i] = 0;
		else ans[i] += negsum;
	}

	printf("Case #%d: ", tc);
	for(int i=0; i<n; i++)
		printf("%0.6f ", ans[i]*100);
	cout<<endl;	
			
	}
	return 0;
}