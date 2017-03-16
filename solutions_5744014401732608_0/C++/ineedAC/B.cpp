/*
* Filename:    B.cpp
* Created:     2016年05月08日 16时58分14秒 星期日
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
const int maxn=50+7;
//Global Variables
int n,m,t,ans;
string s;
ll B,M;
int a[maxn][maxn];
//Function Declaration
void init(){
	for (int i = 1; i <= B; i += 1)
	{
		for (int j = 1; j <= B; j += 1)
		{
			if(i>=j)a[i][j]=0;
			else{
				a[i][j]=1;
			}
		}
	}
}
void print(){
	for (int i = 1; i <= B; i += 1)
	{
		for (int j = 1; j <= B; j += 1)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}
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
		printf("Case #%d:",tcase);
		scanf("%lld%lld",&B,&M);
		ll res=1;
		ll pp=B-2;
		res=res<<pp;
		if(M<=res){
			printf(" POSSIBLE\n");
			init();
			ll tmp=res-M;
			int num=2;
			while(tmp!=0){
				if(tmp%2){
					a[num][B]=0;
				}
				tmp/=2;
				num++;
			}
			print();
		}else{
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}

