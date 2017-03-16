#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000][1000];
map<ll,ll>mm;
map<ll,ll>::iterator it;
vector<ll>v;
int main()
{
	ll t,n,i,j;
	cin>>t;
	FILE * pFile;
	ll c=0;
	pFile = fopen ("output.txt","w");
	while(t--)
	{
		c++;
		v.clear();
		mm.clear();
		cin>>n;
		for(i=0;i<2*n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}
		for(j=0;j<n;j++)
		{
			for(i=0;i<2*n-1;i++)
			{
				mm[arr[i][j]]++;
			}
			
		}
		for(it=mm.begin();it!=mm.end();it++)
		{
			if((it->second)&1)
			v.push_back(it->first);
		}
		fprintf (pFile, "Case #%lld: ",c);
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i++)
		{
			fprintf (pFile, "%lld ",v[i]);
		}
		fprintf (pFile, "\n");
	}
}
