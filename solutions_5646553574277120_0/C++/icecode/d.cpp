#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Returns true if there is a subset of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */
 
     return subset[sum][n];
}

int main()
{
	int t,c,d,v,i,j,n,k,ans;
	cin >> t;
	for(i=1;i<=t;i++)
	{
		ans=0;
		int dp[35];
		cin >> c >> d >> v;
		for(j=0;j<d;j++){
			cin >> dp[j];	
		}
		for(k=1;k<=v;k++) {
			if(isSubsetSum(dp,j,k) == true)	continue;
			else {
				dp[j]=k;
				j++;
				ans++;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	printf("");
	return 0;
}
