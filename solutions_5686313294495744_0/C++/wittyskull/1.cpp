#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.1415926535897932
#define inf 10000000000000
#define first fi
#define second se
vector < string >v;
vector <string> vv;
int main()
{   
	int t,y=0;
	scanf("%d",&t);
	while(t--)
	{
		y++;
		int n,i,j,k;
		v.clear();
		vv.clear();
		scanf("%d",&n);
		string st1,st2;
		for(i=0;i<n;i++)
		{
			cin>>st1;
			cin>>st2;
			v.pb(st1);
			vv.pb(st2);
		}
		int ans=0,m=pow(2,n),c=0;
		for(i=0;i<m;i++)
		{
			c=0;
			for(j=0;j<n;j++)
			{

				if((i&(1<<j))!=0)
				{
					int flag=0;
					//first
					for(k=0;k<n;k++)
					{
						if((i&(1<<k))==0)
						{
							if(v[j]==v[k])
							{
								//cout<<v[j]<<v[k]<<endl;
								break;

							}
						}
					}
					if(k!=n)
					flag++;
					for(k=0;k<n;k++)
					{
						if((i&(1<<k))==0)
						{
							if(vv[j]==vv[k])
							{
								//cout<<vv[j]<<vv[k]<<endl;
								break;

							}
						}
					}
					if(k!=n)
					flag++;
					if(flag==2)
					c++;
				}

			}
			ans=max(ans,c);
		}
		printf("Case #%d: %d\n",y,ans);
	}
	return 0;
}