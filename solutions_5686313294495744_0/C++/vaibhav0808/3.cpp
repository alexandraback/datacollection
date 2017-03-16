#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("input.txt","r+",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	
	for(int tst=1;tst<=t;tst++)
	{
		printf("Case #%d: ",tst);
		int n;
		scanf("%d",&n);
		
		char x[n][25],y[n][25];
		map <pair<int,int> ,int > m;
		for(int i=0;i<n;i++)
		{
			cin >> x[i] >> y[i];
		}
		
		
		int ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			m.clear();
			   vector <int> f(n),r(n);
			   f.clear();
			   r.clear();
			   for(int j=0;j<n;j++)
			   {
			   	  if( i& (1<<j) )
			   	   f.push_back(j);
			   	  else r.push_back(j);
			   }
			   int count=0;
			   for(int j=0;j<f.size();j++)
			   {
			         for(int k=0;k<r.size();k++)
					 {
					 	for(int l=0;l<r.size();l++)
					 	{
					 		  if(strcmp(x[r[k]],x[f[j]])==0 && strcmp(y[r[l]],y[f[j]])==0 && r[k]!=r[l] && !m[make_pair(r[k],r[l])])
					 		  {
					 		     count++;
				
					 		     m[make_pair(r[k],r[l])]=1;
								 goto abc;	
							  }
						}
					 }
					 
					 goto ab;
					 abc:
						;
			   }
			  ans=max(ans,count);
			  ab:
			  ;
			  	//	cout << endl;
		}
		
		//cout << endl;
		cout << ans << endl;
		//		cout << endl;
	}
	return 0;
}
