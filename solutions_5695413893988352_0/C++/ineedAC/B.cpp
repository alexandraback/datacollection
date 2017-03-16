/*
* Filename:    B.cpp
* Desciption:  Desciption
* Created:     2016年05月01日 00时31分51秒 星期日
* Author:      JIngwei Xu [mail:xu_jingwei@outlook.com]
*
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

//Init Const
const int INF=1e9;
const int maxn=20;

//Global Variables
int n,m,t;
int len;
string s1,s2;
ll a[maxn],b[maxn];
int minabs;
ll ansa[maxn],ansb[maxn];
//Function Declaration
void check();
void dfs(int deep);
//Main Program
int main()
{
#ifdef AC_THIS_PROBLEM
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d",&t);
	for (int tcase = 1; tcase<=t; tcase += 1)
	{
		printf("Case #%d: ",tcase);
		cin>>s1>>s2;
		len=s1.length();
		for (int i = 0; i < len; i += 1)
		{
			if(s1[i]=='?')a[i]=-1;
			else a[i]=s1[i]-'0';
			if(s2[i]=='?')b[i]=-1;
			else b[i]=s2[i]-'0';
		}
		minabs=INF;
		dfs(0);
		for (int i = 0; i < len; i += 1)
		{
			printf("%d",(int)ansa[i]);
		}
		printf(" ");
		for (int i = 0; i < len; i += 1)
		{
			printf("%d",(int)ansb[i]);
		}
		printf("\n");
	}
	return 0;
}
void check(){
	ll anum=0,bnum=0;
	ll pows=1;
	for (int i = len-1; i >=0; i += -1)
	{
		anum+=a[i]*pows;
		bnum+=b[i]*pows;
		pows*=10;
	}
	if(abs(anum-bnum)<minabs){
		minabs=abs(anum-bnum);
		for (int i = 0; i < len; i += 1)
		{
			ansa[i]=a[i];
			ansb[i]=b[i];
		}
	}
}
void dfs(int deep){
	if(deep==len){
		check();
		return;
	}
	if(a[deep]!=-1&&b[deep]!=-1){
		dfs(deep+1);
	}
	else if (a[deep]==-1&&b[deep]!=-1)
	{
		for (int i = 0; i < 10; i += 1)
		{
			a[deep]=i;
			dfs(deep+1);
		}
		a[deep]=-1;
	}
	else if (a[deep]!=-1&&b[deep]==-1)
	{
		for (int i = 0; i < 10; i += 1)
		{
			b[deep]=i;
			dfs(deep+1);
		}
		b[deep]=-1;
	}
	else{
		for (int i = 0; i < 10; i += 1)
		{
			for (int j = 0; j < 10; j += 1)
			{
				a[deep]=i;
				b[deep]=j;
				dfs(deep+1);
			}
		}
		a[deep]=-1;
		b[deep]=-1;
	}
	
}
