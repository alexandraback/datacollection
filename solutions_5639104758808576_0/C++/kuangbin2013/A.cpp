/* ***********************************************
Author        :kuangbin
Created Time  :2015/4/11 8:39:58
File Name     :GCJ_QR\A.cpp
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
char str[1010];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int n;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d%s",&n,str);
		int ans = 0;
		int now = 0;
		for(int i = 0;i <= n;i++){
			int num = str[i]-'0';
			if(num == 0)continue;
			if(now < i){
				ans += i-now;
				now = i;
			}
			now += num;
		}
		printf("Case #%d: %d\n",iCase,ans);
	}
    return 0;
}
