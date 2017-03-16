#include <stdio.h>
#include <string.h>
#include <stdlib.h>

inline int isConsonant(char c)
{
	return ! (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c==0);
}

int main()
{
	unsigned int T=0,L,n;
	unsigned long cnt;
	char buf[1000001];
	unsigned int cons[1000001];
	int c,i,j,s,l,pos;

	scanf("%d",&T);
	for(c=1;c<=T;c++)
	{
		scanf("%s %d",buf,&n);

		cnt=0;
		L=0;
		i=0;
		s=i;
		l=0;
		memset(cons,0,sizeof(cons));

		while(1)
		{

			if(isConsonant(buf[i]))
			{
				l++;
			}else
			{
				for(j=s;j<s+l;j++)
				{
					cons[j]=s+l-j;
				}
				l=0;
				s=i+1;
			}


			if(buf[i]==0)
			{
				L=i;
				break;
			}
			i++;
		}


		cnt=0;
		pos=-1;

		for(i=0;i<L;i++)
		{
			if(pos<i)
			{
				for(j=i;j<L;j++)
				{
					if(cons[j]>=n)
					{
						pos=j;
						break;
					}
				}
				if(j==L) break;
			}
			cnt+=L-(pos+n)+1;
		}


		printf("Case #%d: %lu\n",c,cnt);
	}
}

