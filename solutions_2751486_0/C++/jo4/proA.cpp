#include <cstdio>
#include <cstring>

char in[1000001];

bool is(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main()
{
	int T,n,i,j,k,L,R,len,count;
	long long int ans;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%s %d",in,&n);
		ans=0;
		len=strlen(in);
		for(L=0;L<len;L++)
		{
			count=0;
			for(R=L;R<len;R++)
			{
				count++;
				if(is(in[R]))
					count=0;
				if(count>=n)
				{
					ans+=len-R;
					break;
				}
			}	
		}
		printf("Case #%d: %lld\n",i,ans);
	}
	//scanf(" ");
	return 0;
}
