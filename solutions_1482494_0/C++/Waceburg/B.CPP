#include<stdio.h>
#include<memory.h>
typedef struct
{
	int a,b;
}LV;
LV lv[1001];
int v[1001][2];
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int t,c,n,i,k,s,score,step;
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		memset(v,0,sizeof(v));
		k=score=step=0;
		printf("Case #%d: ",c);
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d%d",&lv[i].a,&lv[i].b);
		while(k<n)
		{
			s=0;
			for(i=0;i<n;i++)
			{
				if(!v[i][1]&&lv[i].b<=score)
				{
					s=1;
					v[i][1]=1;
					if(!v[i][0]) score+=2;
					else score++;
					step++;
					k++;
					break;
				}
			}
			if(s) continue;
			for(i=0;i<n;i++)
			{
				if(!v[i][1]&&!v[i][0]&&lv[i].a<=score)
				{
					v[i][0]=1;
					s=1;
					score++;
					step++;
					break;
				}
			}
			if(!s) break;
		}
		if(k<n) printf("Too Bad\n");
		else printf("%d\n",step);
	}
	return 0;
}