/*
* Filename:    C.cpp
* Created:     2016年05月08日 16时58分17秒 星期日
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
typedef long long ll;
typedef pair<int,int> PP;
//Init Const
const int INF=1e9;
const int maxn=1000+7;
//Global Variables
int n,m,t,ans;
int J,P,S,K;
map<PP,int> A,B,C;
//Function Declaration


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
		scanf("%d%d%d%d",&J,&P,&S,&K);
//		J=min(J,K);
//		P=min(P,K);
//		S=min(S,K);
		A.clear();B.clear();C.clear();
		ans=0;
		for (int i = 1; i <=J; i += 1)
		{
			for (int j = 1; j <= P; j += 1)
			{
				for (int k = 1; k <= S; k += 1)
				{
//					printf("%d %d %d\n",i,j,k);
					if(A[PP(i,j)]<K&&B[PP(i,k)]<K&&C[PP(j,k)]<K){
						A[PP(i,j)]++;
						B[PP(i,k)]++;
						C[PP(j,k)]++;
						ans++;
					}
				}
			}
		}
		printf(" %d\n",ans);
		A.clear();B.clear();C.clear();
		for (int i = 1; i <=J; i += 1)
		{
			for (int j = 1; j <= P; j += 1)
			{
				for (int k = 1; k <= S; k += 1)
				{
					
					if(A[PP(i,j)]<K&&B[PP(i,k)]<K&&C[PP(j,k)]<K){
						printf("%d %d %d\n",i,j,k);
						A[PP(i,j)]++;
						B[PP(i,k)]++;
						C[PP(j,k)]++;
					}
				}
			}
		}
	}
	return 0;
}

