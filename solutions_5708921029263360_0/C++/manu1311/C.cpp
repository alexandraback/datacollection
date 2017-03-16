#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int count1[11][11],count2[11][11],count3[11][11],ans[1010][3];

int main()
{
	ios_base::sync_with_stdio(false);
	int t,ja,p,s,kk,c;
	cin>>t;
	for(int loop=1;loop<=t;loop++)
	{
		c=0;
		cin>>ja>>p>>s>>kk;
		for(int i=1;i<=s;i++)
			for(int j=1;j<=p;j++)
				for(int k=1;k<=ja;k++)
					count1[i][j]=count2[j][k]=count3[k][i]=0;
		for(int i=1;i<=s;i++)
			for(int j=1;j<=p;j++)
				for(int k=1;k<=ja;k++)
				{
					if(count1[i][j] == kk || count2[j][k] == kk || count3[k][i] == kk)
						continue;
					ans[c][0]=k;
					ans[c][1]=j;
					ans[c][2]=i;
					count1[i][j]++;
					count2[j][k]++;
					count3[k][i]++;
					c++;
				}
		cout<<"Case #"<<loop<<": "<<c<<"\n";
		for(int i=0;i<c;i++)
			cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
	}
	return 0;
}