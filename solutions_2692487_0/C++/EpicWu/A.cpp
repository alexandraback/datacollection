#include<iostream>
#include<algorithm>
using namespace std;


int ff[1000100],f[1000100],n,x;
const int INF = 1000099;
int data[101];

int dp()
{
	cin>>x>>n;
	for (int i=0;i<n;++i)
	{
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
	for (int i=0;i<=INF;++i) f[i]=n;
	f[x]=0;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<1000100;++j) ff[j]=min(n,f[j]+1);
		for (int j=1;j<1000100;++j)
		if (j>data[i])
		{
			int tmp = j+data[i];
			if (tmp>INF) tmp = INF;
			ff[tmp]=min(ff[tmp],f[j]);
		} else
		if (j>1)
		{
			int tmp = j;
			int cnt = 0;
			while (tmp<=data[i])
			{
				tmp+=tmp-1;
				cnt++;
			}
			tmp+=data[i];
			if (tmp>INF) tmp = INF;
			ff[tmp]=min(ff[tmp],f[j]+cnt);
		}
		for (int j=0;j<1000100;++j) f[j]=ff[j];
	}
	int ans = n;
	for (int j=1;j<=1000100;++j)
	ans = min(ans, f[j]);
	return ans;
}
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("Asmall.txt","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=T;++i)
		printf("Case #%d: %d\n",i,dp());
	return 0;
} 
