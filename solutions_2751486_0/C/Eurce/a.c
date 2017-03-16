char s[101];
int t,n,sl,sum;

main()
{
	int i,j,k,l;
	scanf("%*d");
	while(~scanf("%s%d",s,&n))
	{
		sl=strlen(s);
		for(i=0;i<sl;i++)
		{
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') s[i]=1;
			else s[i]=2;
		}
		sum=0;
		for(i=0;i<=sl-n;i++)
		{
			for(j=i+n-1;j<sl;j++)
			{
				for(k=i,l=0;k<=j;k++)
				{
					if(s[k]==2)
					{
						l++;
						if(l==n) break;
					}
					else l=0;
				}
				if(k<=j) sum++;
			}
		}
		printf("Case #%d: %d\n",++t,sum);
	}
}
