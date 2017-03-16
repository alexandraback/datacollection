#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T,tt,n,i,j,temp,ans,s[100500],anss[100],ansnum;
int zhi[10050] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void dfs(int a){
	if (ansnum==j) return;
	if (a==n)
	{
		for (int i = 2;i<=10;i++)
		{
			anss[i] = 0;
			for (int k =0;k<=24;k++)
			{
				temp = ans = 0;
				for (int j = 1;j<=n;j++)
				{
					if (j == 1) temp = 1;
					else temp = (temp*i)%zhi[k];
					ans = (ans+s[j]*temp)%zhi[k];
				}
				if (ans == 0)
				{
					anss[i] = zhi[k];
					break;
				}
			}
			if (anss[i] == 0) return;
		}
		for (int i =n;i>=1;i--)
		{
			printf("%d",s[i]);
		}
		printf(" ");
		for (int i =2;i<=10;i++)
		{
			printf("%d ",anss[i]);
		}
		printf("\n");
		ansnum ++;
		return;
	}
	s[a] = 1;
	dfs(a+1);
	s[a] = 0;
	dfs(a+1);
}
int main(){
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);
	scanf("%d",&T);
	
	for (tt= 1;tt <= T;tt++)
	{
		ansnum = 0;
		printf("Case #%d:\n",tt);
		scanf("%d%d",&n,&j);
		s[1] = s[n] = 1;
		dfs(2);
	}
}
