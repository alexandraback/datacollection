//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE
int r,c,m;
int i,j,t;
int cs;
char arr[60][60];
int dp[60][60][3600];

int can(int n, int num, int blanks) {
	if (num > blanks)
		return 0;
	if (n>=r)
		return 0;
	if (num == blanks && num <=c && num != 1)
		return 1;
	int &ret = dp[n][num][blanks];
	if (ret>=0)
		return ret;
	ret = 0;
	for (int i = 1;i<=num;++i)
	{
		if (can(n+1,i,blanks-num)==1) {
			ret = 1;
			return ret;
		}
	}
	return ret;
}

void btrack(int n, int num, int blanks) {
	if (num > blanks)
		return;
	if (n>=r)
		return;
	if (num == blanks && num <=c && num != 1)
	{
		for (int j = 0; j < num; ++j)
			arr[n][j] = '.';
		return;
	}
	for (int i = 1;i<=num;++i)
	{
		if (can(n+1,i,blanks-num)==1) {
			btrack(n+1,i,blanks-num);
			for (int j = 0; j < num; ++j)
				arr[n][j] = '.';
			return;
		}
	}
}
int main()
{
	scanf("%d",&t);
	while (t--) {
		printf("Case #%d:\n",++cs);
		scanf("%d %d %d",&r,&c,&m);
		if (r==1 && c==1) {
			printf("c\n");
		}
		else if (r==1) {
			{
				int i;
				printf("c");
				for (i=0;i<(r*c-m)-1;++i)
					printf(".");
				for (i=0;i<m;++i)
					printf("*");
				printf("\n");
			}
		}
		else if (c==1) {
			{
				int i;
				printf("c\n");
				for (i=0;i<(r*c-m)-1;++i)
					printf(".\n");
				for (i=0;i<m;++i)
					printf("*\n");
			}
		}
		else {
			if (m == r*c-1) {
				printf("c");
				for (i=0;i<c-1;++i)
					printf("*");
				printf("\n");
				for (i=0;i<r-1;++i)
				{
					for (j=0;j<c;++j)
						printf("*");
					printf("\n");
				}
			}
			else {
				memset(dp,-1,sizeof(dp));
				int blank = r*c-m;
				int num = -1;
				for (i=1;i<=c;++i)
					if (can(1,i,blank-i))
						num = i;
				if (num == -1)
					printf("Impossible\n");
				else
				{
					for (i=0;i<r;++i)
						for (j=0;j<c;++j)
							arr[i][j] = '*';
					for (i=0;i<num;++i)
						arr[0][i] = '.';
					btrack(1,num, blank-num);
					arr[0][0] = 'c';
					for (i=0;i<r;++i) {
						for (j=0;j<c;++j)
							printf("%c",arr[i][j]);
						printf("\n");
					}
				}
			}
		}
	}
}
