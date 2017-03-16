#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(){
	int num;
	int ans;
	int tmp;
	int t,s,p,i,j,n,mm;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for (i = 1;i <= t;i++){
		num = 0;
		ans = 0;
		scanf("%d%d%d",&n,&s,&p);
		for (j = 0;j < n;j++){
			scanf("%d",&tmp);
			if (tmp % 3 == 0){
				mm = tmp/3;
				if (mm >= p){
					ans ++;
				}
				else if (mm == p-1 && mm > 0 && mm < 10){
					num ++;
				}
			}
			else if (tmp %3 == 1){
				mm = tmp/3+1;
				if (mm >= p){
					ans ++;
				}
			}
			else{
				mm = tmp/3+1;
				if (mm >= p){
					ans ++;
				}
				else if (mm == p-1 && mm < 10){
					num ++;
				}
			}
		}
		if (num >= s){
			ans += s;
		}
		else{
			ans += num;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	
}