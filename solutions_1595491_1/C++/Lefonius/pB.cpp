#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int t, n, s, p, num, ans, time=0, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &s, &p);
		ans=0;
		for(i=0; i<n; i++){
			scanf("%d", &num);
			if( ((num/3)+(num%3>0)) >= p ) ans++;
			else if(num%3==0 || num%3==2){
				if( ((num/3)+(num%3>0))==p-1 && s>0 && num>0 ){
					s--;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", ++time, ans);
	}
	return 0;
}
