#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int a[1010],b[1010];
bool aa[1010],bb[1010];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas = 1;
	int n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++){
			scanf("%d%d",&a[i],&b[i]);
			aa[i] = bb[i] = false;
		}
		int s = 0;
		int t = 0,tt = 0;
		while (1)
		{
			if(tt == n) break;
			bool flag = false;
			for(i = 0;i < n;i++){
				if(!bb[i] && b[i] <= s){
					if(aa[i]) s += 1;
					else s += 2;
					bb[i] = true;
					flag = true;
					t++;
					tt++;
				}
			}
			if(flag)continue;
			for(i = 0;i < n;i++){
				if(!aa[i] && bb[i] && a[i] <= s){
					s++;
					aa[i] = true;
					flag = true;
					t++;
					break;
				}
			}
			if(flag) continue;
			int ii=-1,tmp=-1;
			for(i = 0;i < n;i++){
				if(!aa[i] && a[i] <= s){
					if(tmp < b[i]){
						tmp = b[i];
						ii = i;
					}
				}
			}
			if(tmp >= 0){
				s++;
				aa[ii] = true;
				flag = true;
				t++;
			}
			if(flag) continue;
			break;
		}
		for(i = 0;i < n;i++)
			if(!bb[i]) break;
		if(i < n)printf("Case #%d: Too Bad\n",cas++);
		else printf("Case #%d: %d\n",cas++,t);
	}



	return 0;
}