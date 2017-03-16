# include <stdio.h>
# include <string.h>
typedef long long ll;
char str[1000001];
ll a[1000001],b[1000001];
int check(char c)
{
	if (c == 'a'||c == 'e'||c == 'i'||c=='o'||c=='u')
		return 1;
	return 0;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i,j,k,p,n;
	scanf("%d",&t);
	for (p=1;p<=t;++p)
	{
		ll num = 0,cnt=0;
		scanf("%s%d",str,&n);
		int len = strlen(str);
		memset(a,0,sizeof(a));
		for (i=0;i<len;++i)
		{
			if (check(str[i]))
				a[i] = 0;
			else if (i == 0 && !check(str[i]))
				a[i] = 1;
			else
				a[i] = a[i-1]+1;
			if (a[i]>=n)
				b[cnt++] = i+1;		
		}
		for (i=0;i<cnt;++i)
		{
			if (i != cnt-1)
				num += (b[i+1]-b[i])*(b[i]-n+1);
			if (i == cnt-1)
				num += (len-b[i]+1)*(b[i]-n+1);
		}
		printf("Case #%d: %I64d\n",p,num);
	}
	return 0;
}