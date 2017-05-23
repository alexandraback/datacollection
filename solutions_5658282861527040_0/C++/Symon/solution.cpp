#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
typedef __int64 LL;
char A[35],B[35],K[35];
LL memo[31][2][2][2],lenk,lena,lenb;
LL MX(LL a,LL b){return (a>b)?a:b;}
LL bin(LL val,char *str)
{
	LL id=0;
	if(!val) str[id++]='0';
	while(val>0)
	{
		str[id++]=(val%2)+'0';
		val/=2;
	}
	str[id]='\0';
	//reverse(str,str+id);
	return id;
	//printf("%I64d\n",id);
}
void ad(LL len,LL L,char *str)
{
	LL i;
	for(i=len;i<L;i++) str[i]='0';
	str[L]='\0';
	reverse(str,str+L);
}
LL dp(LL pos,LL prek,LL prea,LL preb)
{
	if(pos==lenk) return 1;
	LL &ret=memo[pos][prek][prea][preb];
	if(ret!=-1) return ret;
	ret=0;
	LL i,j,l,prek1,prea1,preb1;
	for(i=0;i<=1;i++)
	{
		if(prea && i>A[pos]-'0') break;
		if(prea && i==A[pos]-'0') prea1=1;
		else prea1=0;
		for(j=0;j<=1;j++)
		{
			if(preb && j>B[pos]-'0') break;
			if(preb && j==B[pos]-'0') preb1=1;
			else preb1=0;
			l=i&j;
			if(prek && l>K[pos]-'0') continue;
			if(prek && l==K[pos]-'0') prek1=1;
			else prek1=0;
			ret+=dp(pos+1,prek1,prea1,preb1);
		}
	}
	return ret;
}
int main()
{
	LL t,cas=0,ans,a,b,k;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.in","w",stdout);
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&k);
		a--;b--;k--;
		lena=bin(a,A);
		lenb=bin(b,B);
		lenk=bin(k,K);
		LL mx=MX(lena,lenb);
		mx=MX(mx,lenk);
		ad(lena,mx,A);
		ad(lenb,mx,B);
		ad(lenk,mx,K);
		lenk=mx;
		memset(memo,-1,sizeof(memo));
		ans=dp(0,1,1,1);
	//	printf("%s %s %s\n",A,B,K);
		printf("Case #%I64d: %I64d\n",++cas,ans);
	}
	return 0;
}