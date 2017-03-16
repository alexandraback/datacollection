#include<cstdio>
#include<algorithm>

char s[1111111];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int i,n,max=0,tot=0;
        scanf("%d%s",&n,s);
        for(i=0;i<=n;i++)if(s[i]>'0')
		{
            max=std::max(max,i-tot);
            tot+=s[i]-'0';
		}
		printf("Case #%d: %d\n",tc,max);
	}
}
