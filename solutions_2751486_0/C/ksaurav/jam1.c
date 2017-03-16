#include <stdio.h>
#include <string.h>

int check (char*a,int n)
{
	int i;
	// check if next n is consonant
	for(i=0;i<n;i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
		return 1;

	}
	return 0;
}

int main()
{
	int t,n,i,start,end,len; char s[1000005]; long long int ans;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		ans=0;
		scanf("%s%d",s,&n);
		len=strlen(s);
		for(start=0;start<=len-n;start++)
		{
			end=start;
			while(check(s+end,n)&&end<=len-n) end++;
			if(end<=len-n) ans=ans+(len-end-n+1);

		}
		printf("Case #%d: %lld\n",i,ans);

	}
	return 0;
}