//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
const int MAXN=110;
int a[MAXN];
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	int n,A;
	scanf("%d",&T);
	int iCase=0;
	while(T--)
	{
		iCase++;
		scanf("%d%d",&A,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(A==1)
		{
			printf("Case #%d: %d\n",iCase,n);
			continue;
		}
		sort(a,a+n);
		int ans=1000;
		for(int i=0;i<=n;i++)
		{
			int tmp=i;
			int t=A;
			int j=0;
			while(j<n-i)
			{
				while(j<n-i && t>a[j])
				{
					t+=a[j];
					j++;
				}
				if(j<n-i)
				{
					t+=t-1;
					tmp++;
				}
			}
			ans=min(ans,tmp);
		}
		printf("Case #%d: %d\n",iCase,ans);
	}
	return 0;
}
