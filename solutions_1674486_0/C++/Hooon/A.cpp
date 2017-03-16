#include <stdio.h>
void input();
void process();
void output(int t);

int n, d[1010][1010],l[1010];
int check[1010],ch[1010],check2[1010],ans;

int main()
{
	int i,t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(i=1; i<=t; i++)
	{
		input();
		process();
		output(i);
	}
	fclose(stdin);
	fclose(stdout);
}

void input()
{
	int i,j,c;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		check[i]=0;
		ch[i]=0;
	}
	for(i=1; i<=n; i++)
	{
		scanf("%d",&l[i]);
		for(j=1; j<=l[i]; j++)
		{
			scanf("%d",&c);
			d[i][j]=c;
			ch[c]++;
		}
	}
	for(i=1; i<=n; i++)
	{
		if(ch[i]==0)check[i]=1;
	}
}

void process()
{
	int i,cnt=0, j,s;
	for(s=1; s<=n; s++)
	{
		if(check[s]==0)continue;
		for(i=1; i<=n; i++)
		{
			ch[i]=0;
			check2[i]=0;
		}
		ch[s]=1;
		for(;;)
		{
			cnt=0;
			for(i=1; i<=n; i++)
			{
				if(ch[i]!=0 && check2[i]==0)
				{
					cnt=1;
					check2[i]=1;
					for(j=1; j<=l[i]; j++)
					{
						ch[d[i][j]]++;
						if(ch[d[i][j]]==2)
						{
							ans=1;
							return;
						}
					}
				}
				
			}
			if(cnt==0)break;
		}
	}
	ans=0;
}

void output(int t)
{
	printf("Case #%d: ",t);
	if(ans)printf("Yes\n");
	else printf("No\n");
}
