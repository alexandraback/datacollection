#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int K,L,S;
char key[101], pat[101];
long long cnt,max_cnt;

bool check(char* s)
{
	for(int i = 0; i<L; i++)
		if(s[i]!=pat[i])return false;
	return true;
}

void dfs(int d)
{
	static char str[201]={'\0'};
	if(d==0)
		for(int i=0; i < 200; i++)
			str[i]='\0';
	if(d==S)
	{
		long long tmp=0;
		for(int i=0; i<S; i++)
			if(check(str+i))
				tmp++,cnt++;
		max_cnt=max(tmp,max_cnt);
	}
	else
	{
		for(int i = 0; i<K; i++)
		{
			str[d]=key[i];
			dfs(d+1);
		}
	}
}

double solve()
{
	scanf("%d%d%d",&K,&L,&S);
	scanf("%s%s",key,pat);
	max_cnt=cnt=0;
	dfs(0);
//	return (double)max_cnt-(double)cnt*pow((double)K,(double)-S);
	double ex=1.0;
	for(int i = 0; i < S; i++)
		ex/=(double)K;
	return (double)max_cnt-ex*(double)cnt;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i =1; i<=T; i++)
		printf("Case #%d: %f\n",i,solve());
	return 0;
}
