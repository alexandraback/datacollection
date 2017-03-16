/* ***********************************************
Author        :kuangbin
Created Time  :2015/4/11 9:40:34
File Name     :GCJ_QR\B.cpp
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

int a[1010];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int n;
	scanf("%d",&T);
	int iCase = 0;
	while(T--){
		iCase++;
		scanf("%d",&n);
		int Max = 0;
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			Max = max(Max,a[i]);
		}
		int ans = Max;
		for(int i = 1;i <= Max;i++){
			int tmp = i;
			for(int j = 0;j < n;j++){
				tmp += (a[j]+i-1)/i-1;
			}
			ans = min(ans,tmp);
		}
		printf("Case #%d: %d\n",iCase,ans);
	}
    return 0;
}
