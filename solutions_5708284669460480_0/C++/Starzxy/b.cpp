#include<cstdio>
#include<cstring>

using namespace std;

int TT;
int n,m,N;
int len,Ans;
int next[110];
char str[110];
char alph[110];
char Str[110];
int Alph[110];

inline void calc_next()
{
    next[0]=-1;
    int j=-1;
 
    for(int i=1;i<len;i++)
    {
        while(j!=-1&&str[i]!=str[j+1])
            j=next[j];
 
        if(str[j+1]==str[i])
            next[i]=++j;
        else
            next[i]=j;
    }
}

inline int check()
{
	int temp=0,pos=-1;
	for(int i=1;i<=N;i++)
	{
		while(pos!=-1&&str[pos+1]!=Str[i])pos=next[pos];
		if(Str[i]==str[pos+1])pos++;
		if(pos==len-1)
		{
			pos=next[pos];
			temp++;
		}
		//printf("%c %d ",Str[i],temp);
	}
	//printf("\n");
	return temp;
}
inline void dfs(int x)
{
	if(x==N+1)
	{
		Ans+=check();
		//printf("%d\n",Ans);
		return;
	}
	for(int i=0;i<strlen(alph);i++)
	{
		Str[x]=alph[i];
		dfs(x+1);
	}
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++)
	{
		Ans=0;
		scanf("%d%d%d",&n,&m,&N);
		scanf("%s",alph);
		scanf("%s",str);
		len=strlen(str);
		calc_next();
		//printf("%d %d %d\n",N,len,next[len-1]);
		double ans=(int)(N-len)/(len-next[len-1]-1)+1;
		int len1=strlen(alph);
		memset(Alph,0,sizeof(Alph));
		for(int i=0;i<strlen(alph);i++)
			Alph[alph[i]]++;
		bool flag=true;
		for(int i=0;i<len;i++)
			if(!Alph[str[i]])
				{
					flag=false;
					break;
				}
		if(!flag)
		{
			printf("Case #%d: 0.0000000\n",T);
			continue;
		}
		dfs(1);
		double temp=Ans;
		//printf("%lf\n",temp);
		for(int i=1;i<=N;i++)
			temp=(double)temp/n;
		printf("Case #%d: %.8lf\n",T,(double)ans-temp);
	}
	return 0;
}
