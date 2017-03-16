#include <stdio.h>
#include <memory.h>
#include <algorithm>

const int PROB_NUM=3;

bool chk[26];
char arr[100][101];
int sta[100];

void process()
{
	bool f;
	char p;
	int n,c=0,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",arr[i]);
	for(i=0;i<n;i++)
		sta[i]=i;
	do
	{
		f=0;
		memset(chk,0,sizeof(chk));
		p=arr[sta[0]][0];
		for(i=0;i<n;i++)
		{
			for(j=0;arr[sta[i]][j];j++)
			{
				if(chk[arr[sta[i]][j]-'a'])
				{
					f=1;
					break;
				}
				if(arr[sta[i]][j]!=p)
				{
					chk[p-'a']=1;
					p=arr[sta[i]][j];
				}
			}
			if(f)
				break;
		}
		if(f||chk[p-'a'])
			continue;
		c++;
	}
	while(std::next_permutation(sta,sta+n));
	printf("%d\n",c);
}

int main()
{
	char in[10]="0.in";
	char out[10]="0.out";
	in[0]=PROB_NUM+'0';
	out[0]=PROB_NUM+'0';
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}