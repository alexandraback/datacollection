#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int main(){
	int t;
	int n;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num[1000];
	scanf("%d",&t);
	int i;
	int j;
	int k;
	int sum = 0;
	for (i = 1;i <= t;i++){
		scanf("%d",&n);
		printf("Case #%d:\n",i);
		sum = 0;
		for (j = 0;j < n;j++){
			scanf("%d",&num[j]);
			sum += num[j];
		}
	
		int sum1,sum2,weishu;
		int ans1[50],ans2[50];
		for (k = 1;k < 3486784401;k++){
			sum1 = 0;sum2 = 0;
			weishu = 0;
			int tmp = k;
			while (tmp != 0){
				if (tmp % 3 == 1){
					sum1 += num[weishu];
				}
				else if (tmp % 3 == 2){
					sum2 += num[weishu];
				}
				weishu ++;
				tmp /= 3;
			}
			if (sum1 == sum2){
				break;
			}
		}
		if (k == 3486784401){
			printf("Impossible\n");
			continue;
		}
		ans1[0] = 0;
		ans2[0] = 0;
		weishu = 0;
		while (k != 0){
			if (k % 3 == 1){
				ans1[++ans1[0]] = num[weishu];
			}
			else if (k % 3 == 2){
				ans2[++ans2[0]] = num[weishu];
			}
			weishu ++;
			k /= 3;
		}

		for (j = 1;j <= ans1[0];j ++){
			printf("%d ",ans1[j]);
		}
		printf("\n");
		for (j = 1;j <= ans2[0];j++){
			printf("%d ",ans2[j]);
		}
		printf("\n");
	}
}