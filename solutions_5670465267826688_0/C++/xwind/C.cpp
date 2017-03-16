#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#define REP(it,end) for (int it = 1; it <= (end); it++)
#define FOR(it,begin,end) for (int it = (begin); it <= (end); it++)
#define ROF(it,begin,end) for (int it = (begin); it >= (end); it--)
using namespace std;
int const maxn=12005;
char s[maxn];
int mat[5][5];
int sig(int x)
{
	return x<0?-1:1;
}
/*
int qukpow(int base,long long k)
{
	int res=1;
	while(k>0)
	{
		if(k&1)res=mat[abs(res)][abs(base)]*sig(res)*sig(base);
		base=mat[abs(base)][abs(base)]*sig(base)*sig(base);
		k>>=1;
	}
	return res;
}*/
int main()
{
	int i,j,res,l,con,T,len;
	long long x;
	map<char,int>mp;
	bool has[5];
	for(i=1;i<=4;i++)mat[1][i]=mat[i][1]=i;
	for(i=2;i<=4;i++)mat[i][i]=-1;
	mat[2][3]=4;mat[2][4]=-3;mat[3][2]=-4;mat[3][4]=2;
	mat[4][2]=3;mat[4][3]=-2;
	//for(i=1;i<=4;i++,cout <<endl)for(j=1;j<=4;j++)cout <<mat[i][j]<<" ";
	mp['i']=2;mp['j']=3;mp['k']=4;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		res=1,con=0;
		bool flag=false;
		scanf("%d %d",&l,&x);
		len=l*x;
		//if(x&1)x=1;else x=2;
		memset(has,false,sizeof(has));
		scanf("%s",s);
		for(i=l;i<len;i++)s[i]=s[i-l];
		s[i]='\0';
		for(i=0;i<len;i++)
		{
			res=mat[abs(res)][mp[s[i]]]*sig(res);	
			//cout <<res<<" "<<i<<endl;
			if(res==4&&has[2])flag=true;
			if(res>0)has[res]=true;
		}
		/*cout <<res<<endl;
		res=qukpow(res,x);
		cout <<res<<endl;
		for(i=2;i<=4;i++)if(has[i])con++;*/
		if(res!=-1)flag=false;
		if(!flag)printf("Case #%d: NO\n",cas);
		else printf("Case #%d: YES\n",cas);
	}
	return 0;
}
