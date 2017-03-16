#include<cstdio>
#define LL long long
LL T;
char IN[15];
LL subnum(char *S,LL idx)
{
	LL ans=0;
	for(;S[idx];idx++)
	{
		ans*=10;
		ans+=S[idx]-'0';
		S[idx]='0';
	}
	return ans;
}
bool reverse(char *S,LL N)
{
	bool ans=false;
	for(LL i=0;i<N/2;i++)
	{
		if(S[i]!=S[N-1-i])ans=true;
		char c=S[i];
		S[i]=S[N-1-i];
		S[N-1-i]=c;
	}
	return ans;
}
void removezero(char *S)
{
	LL i=0,j;while(S[i]=='0')i++;
	for(j=0;S[j+i];j++)S[j]=S[j+i];
	S[j]=0;
}
LL solve(char *S)
{
	removezero(S);
	//printf("%s",S);
	LL N=-1;while(S[++N]);
	if(N==0)return 0;
	if(N==1)return S[0]-'0';
	if(S[N-1]=='0')
	{
		int i=N-1;
		S[i]--;
		while(S[i]<'0')
		{
			S[i]+=10;
			i--;
			S[i]--;
		}
		return 1+solve(S);
	}
	LL ans=0;
	LL tmp=subnum(S,N/2);
	//printf(" %lld",tmp);
	ans+=tmp-1;
	S[N-1]='1';
	if(reverse(S,N))ans++;
	tmp=subnum(S,N/2);
	//printf(" %lld",tmp);
	ans+=tmp+1;
	for(LL i=0;i<N-1;i++)
	{
		S[i]='9';
	}
	S[N-1]=0;
	//printf(" %lld\n",ans);
	return ans+solve(S);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%lld",&T);
	LL kase=1;
	while(T--)
	{
		scanf("%s",IN);
		printf("Case #%lld: %lld\n",kase++,solve(IN));
	}
	return 0;
} 
