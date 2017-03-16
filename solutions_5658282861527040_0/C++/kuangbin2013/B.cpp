/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/4 0:21:51
File Name     :E:\2014ACM\±ÈÈü\2014_GCJ_R1B\B.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int A,B,K;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&A,&B,&K);
		iCase++;
		int ans = 0;
		for(int i = 0;i < A;i++)
			for(int j = 0;j < B;j++)
				if((i&j) < K)
					ans++;
		printf("Case #%d: %d\n",iCase,ans);
	}
    return 0;
}
