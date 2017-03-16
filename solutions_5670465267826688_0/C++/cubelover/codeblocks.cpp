#include<cstdio>
#include<algorithm>

char a[111111];
int t[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2},{2,7,4,1,6,3,0,5},{3,2,5,4,7,6,1,0}
			,{4,5,6,7,0,1,2,3},{5,0,7,2,1,4,3,6},{6,3,0,5,2,7,4,1},{7,6,1,0,3,2,5,4}};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int i,j,n,m;
        scanf("%d%d%s",&n,&m,a);
		j=0;
		for(i=0;i<n;i++)j=t[j][a[i]-'h'];
		if(m%2&&j!=4)
		{
			printf("Case #%d: NO\n",tc);
			continue;
		}
		if(m%2==0&&m%4&&(j==0||j==4))
		{
			printf("Case #%d: NO\n",tc);
			continue;
		}
		if(m%4==0)
		{
			printf("Case #%d: NO\n",tc);
			continue;
		}
        for(i=n;i<100000&&i<n*m;i++)a[i]=a[i-n];
        j=0;
		for(i=0;i<100000&&i<n*m;i++)
		{
            j=t[j][a[i]-'h'];
            if(j==1)break;
		}
		if(j!=1)
		{
			printf("Case #%d: NO\n",tc);
			continue;
		}
		j=0;
		for(i++;i<100000&&i<n*m;i++)
		{
            j=t[j][a[i]-'h'];
            if(j==2)break;
		}
		if(j!=2)
		{
			printf("Case #%d: NO\n",tc);
			continue;
		}
		printf("Case #%d: YES\n",tc);
	}
}
