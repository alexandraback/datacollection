/* ***********************************************
Author        :kuangbin
Created Time  :2015/4/11 22:03:39
File Name     :B.cpp
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

int getch(char ch){
	if(ch == 'i')return 2;
	else if(ch == 'j')return 3;
	else return 4;
}
int calc(int a,int b){
	if(a < 0 || b < 0){
		if(a < 0 && b < 0)return calc(-a,-b);
		else return -calc(abs(a),abs(b));
	}
	if(a == 1)return b;
	else if(a == 2){
		if(b == 1)return 2;
		else if(b == 2)return -1;
		else if(b == 3)return 4;
		else return -3;
	}
	else if(a == 3){
		if(b == 1)return 3;
		else if(b == 2)return -4;
		else if(b == 3)return -1;
		else return 2;
	}
	else {
		if(b == 1)return 4;
		else if(b == 2)return 3;
		else if(b == 3)return -2;
		else return -1;
	}
}
int gao(int a,long long n){
	int ret = 1;
	int tmp = a;
	while(n){
		if(n&1)ret = calc(ret,tmp);
		tmp = calc(tmp,tmp);
		n >>= 1;
	}
	return ret;
}
char str[10010];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int L;
	long long X;
	scanf("%d",&T);
	int iCase = 0;
	while(T--){
		iCase++;
		scanf("%d%I64d",&L,&X);
		int t = 1;
		scanf("%s",str);
		for(int i = 0;i < L;i++){
			t = calc(t,getch(str[i]));
		}
		long long sx = -1;
		int sy = -1;
		int now = 1;
		for(long long i = 1;i <= 4 && i <= X;i++){
			for(int j = 0;j < L;j++){
				now = calc(now,getch(str[j]));
				//printf("now %d\n",now);
				if(now == 2){
					sx = i;
					sy = j;
					break;
				}
			}
			if(sx != -1)break;
		}
		if(sx == -1){
			printf("Case #%d: NO\n",iCase);
			continue;
		}
		long long ex = -1;
		int ey = -1;
		now = 1;
		for(long long i = X;i >= 1 && i >= X-4;i--){
			for(int j = L-1;j >= 0;j--){
				now = calc(getch(str[j]),now);
				//printf("now ** %d\n",now);
				if(now == 4){
					ex = i;
					ey = j;
					break;
				}
			}
			if(ex != -1)break;
		}
		if(ex == -1){
			printf("Case #%d: NO\n",iCase);
			continue;
		}
		//printf("%I64d %d %I64d %d\n",sx,sy,ex,ey);
		if(ex < sx || (ex == sx && ey <= sy)){
			printf("Case #%d: NO\n",iCase);
			continue;
		}
		int tmp = 1;
		if(sx == ex){
			for(int i = sy+1; i < ey;i++)
				tmp = calc(tmp,getch(str[i]));
		}
		else {
			for(int i = sy+1;i < L;i++)
				tmp = calc(tmp,getch(str[i]));
			tmp = calc(tmp,gao(t,ex-sx-1));
			for(int i = 0;i < ey;i++)
				tmp = calc(tmp,getch(str[i]));
		}
		if(tmp == 3)printf("Case #%d: YES\n",iCase);
		else printf("Case #%d: NO\n",iCase);
	}
    return 0;
}
