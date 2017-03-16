#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
const int MAXN=10000;
int T,Done,Len;
double Pb[MAXN];
double Upb[MAXN];
double Pos[MAXN];
double min(double a,double b)
{
	if(a<b)
	return a;
	return b;
}
void solve(int cnum)
{
	scanf("%d%d",&Done,&Len);
	for(int i=1;i<=Done;i++)
	scanf("%lf",&Pb[i]);
	for(int i=1;i<=Done;i++)
	Upb[i]=1.0-Pb[i];
	Pos[0]=1;
	for(int i=1;i<=Done;i++)
	Pos[i]=Pos[i-1]*Pb[i];
	double AnsKeep=Pos[Done]*(Len-Done+1)+(1-Pos[Done])*(Len-Done+1+Len+1);
	double AnsGiveup=Len+2.0;
	double AnsBack=(Done+Len+1.0);
	for(int i=1;i<Done;i++)
	AnsBack=min(AnsBack,Pos[i]*(Done-i+Len-i+1)+(1-Pos[i])*(Len+1+Done-i+Len-i+1));
	double ans=min(AnsKeep,AnsGiveup);
	ans=min(ans,AnsBack);
	printf("Case #%d: %.6lf\n",cnum,ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		solve(tt);
	}
	getchar();
	return 0;
}