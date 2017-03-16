#include<bits/stdc++.h>
using namespace std;

 
bool isSubsetSum(int set[], int n, int sum)
{
    
    bool subset[sum+1][n+1];
 
    
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
    
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
         return subset[sum][n];
}

int main()
{
	int t,c,d,v,i,j;
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	cin>>t;
	int freq[100],a[100];
	
	for(int g=1;g<=t;g++)
	{
		printf("Case #%d: ",g);
		cin>>c>>d>>v;
		memset(freq,0,sizeof(freq));
		for(i=0;i<d;i++)
		{
		scanf("%d",&a[i]);
		
	}
		int c=i;
		int count=0;
		for(i=1;i<=v;i++)
		{
		
		int m=0;
		if (isSubsetSum(a, d, i) != true)
		{
			
				a[c++];
				count++;
			
			
			
		}
		
	}
	cout<<count<<endl;
	}
	
	
return 0;
}
