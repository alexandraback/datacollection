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
int t,n,i,j;
double arr1[1005];
double arr2[1005];
bool used2[1005];
bool used1[1005];
int main()
{
	scanf("%d",&t);
	int cs = 0;
	while (t--) {
		scanf("%d",&n);
		for (i=0;i<n;++i)
			scanf("%lf",&arr1[i]);
		for (i=0;i<n;++i)
			scanf("%lf",&arr2[i]);
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);
		memset(used2,0,sizeof(used2));
		int res2 = 0;
		for (i=0;i<n;++i)
		{
			double mini = 1E100;
			int nummin= -1;
			for (j=0;j<n;++j)
				if (!used2[j] && arr2[j] > arr1[i] && arr2[j] < mini)
				{
					mini = arr2[j];
					nummin = j;
				}
			if (nummin == -1) {
				for (j=0;j<n;++j)
					if (!used2[j])
						break;
				used2[j] = true;
			}
			else
			{
				used2[nummin] = true;
				++res2;
			}
		}
		memset(used2,0,sizeof(used2));
		int r = n-1;
		int l = 0;
		int r2 = n-1;
		int res1 = 0;
		while (l<=r) {
			if (arr1[r] > arr2[r2]) {
				++res1;
				--r;
				--r2;
			}
			else {
				++l;
				--r2;
			}
		}
		printf("Case #%d: %d %d\n",++cs,res1, n-res2);
	}
}
