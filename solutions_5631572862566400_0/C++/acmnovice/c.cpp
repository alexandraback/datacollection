#include<iostream>
#include<cstdio>
using namespace std;
int tests,n,maxn,max1,max2,top,ans;
int a[1001],t[1001];
bool r[1001],used[1001];
int s[1001][1001];
int dfs(int k)
{
  int temp,maxd=0;
  //cout<<k<<endl;
  for (int i=1;i<=t[k];i++)
  if (r[s[k][i]]!=true)
  {
  	used[s[k][i]]=true;
  	temp=dfs(s[k][i]);
  	if (temp>maxd) maxd=temp;
  }
  return maxd+1;
}
void work(int k)
{
	int max1=0,max2=0,len=0,start,now,deep;
	//cout<<k<<endl;
  //for (int i=1;i<=n;i++) cout<<used[i]<<' ';cout<<endl;
	while (used[a[k]]==false)
	{
		used[k]=true;
		k=a[k];
	}
	used[k]=true;
	len=1;
	start=a[k];now=a[start];r[start]=true;
	while (now!=start) {len++;r[now]=true;now=a[now];}
	r[now]=true;
	//cout<<len<<endl;
	//if (len>2) {if (len>maxn) maxn=len;return;}
	//for (int i=1;i<=n;i++) cout<<r[i]<<' ';cout<<endl;
	len=1;
	now=start;
	deep=dfs(now);
	//cout<<now<<' '<<deep<<endl;
	if (deep>max1) {max2=max1;max1=deep;}
	else if (deep>max2) {max2=deep;}
	now=a[now];
	while (now!=start)
	{
		deep=dfs(now);
		//cout<<now<<' '<<deep<<endl;
		if (deep>max1) {max2=max1;max1=deep;}
		else if (deep>max2) {max2=deep;}
		now=a[now];
		len++;
	}
	//cout<<start<<' '<<max1<<' '<<max2<<endl;
	if (len==2) ans=ans+max1+max2;
	else if (len>maxn) maxn=len;
}	
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>tests;
	for (int test=1;test<=tests;test++)
	{
	cin>>n;
	ans=0;
	printf("Case #%d: ",test);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
		s[a[i]][t[a[i]]]=i;
	}
	for (int i=1;i<=n;i++) used[i]=false,r[i]=false;
	maxn=0;

	for (int i=1;i<=n;i++)
		if (!used[i]) work(i);
	if (maxn>ans) ans=maxn;
	cout<<ans<<endl;
	
	for (int i=1;i<=n;i++)
	{
	  for (int j=1;j<=t[i];j++)
	    s[i][j]=0;
	} 
	for (int i=1;i<=n;i++) t[i]=a[i]=0;
	
	}
	return 0;
}	
		
