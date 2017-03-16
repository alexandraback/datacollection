/*************************************************************************
> File Name: A.cpp
> Author: myf
> Mail: 374684987@qq.com 
> Created Time: Sun 05 May 2013 00:16:16 CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int N=111;

int t,n,s;
int a[N];

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q!=t+1;q++){
		scanf("%d%d",&s,&n);
		for(int i=0;i!=n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		int ans=n;
		for(int i=0;i!=n+1;i++){
			int tot=n-i,now=s;
			for(int j=0;j!=i;j++){
				if (now==1&&now<=a[j]) {tot+=n+1;break;}
				while(now<=a[j]) tot++,now+=now-1;
				now+=a[j];
			}
			ans=min(ans,tot);
		}
		printf("Case #%d: %d\n",q,ans);
	}
	fclose(stdout);
	return 0;
}
