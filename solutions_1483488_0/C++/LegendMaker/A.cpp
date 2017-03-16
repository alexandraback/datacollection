#include<cstdio>
#include<vector>
#define maxn 110
using namespace std;
char s[maxn];
vector<int>p;
bool OK(int k)
{
	int i;
	for(i=0;i<p.size();i++)
	{
		if(p[i]==k)
			return false;
	}
	return true;
}
int main()
{
	int c,x,y,i,j,k,ans,len,temp,ca=1;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&c);
	while(c--)
	{
		ans=0;
		scanf("%d%d",&x,&y);
		for(i=x;i<=y;i++)
		{
			len=sprintf(s,"%d",i);
			p.clear();
			for(j=1;j<len;j++)
			{
				temp=0;
				for(k=j;k<len;k++)
					temp=temp*10+s[k]-'0';
				for(k=0;k<j;k++)
					temp=temp*10+s[k]-'0';
				if(temp<=y&&temp>i&&OK(temp))
				{
					ans++;
					p.push_back(temp);
				}
			}
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}