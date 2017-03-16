
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[121][121];
char s[50000];
long long int base = 1000000007;
int check(char * a){
	int len = strlen(a);
	int used[26];
	for(int i=0;i<26;i++)used[i] = 0;
	char pre = s[0];
	for(int i=0;i<len + 1;i++){
		if(s[i] == pre){
			continue;
		}
		if(s[i] != pre){
			if(used[pre - 'a'] != 0)return -1;
			used[pre - 'a'] ++;
		}
		pre = s[i];
	}
	return 1;
	
}
int main(){
	int T;
	scanf("%d",&T);
	int N;
	for(int ca = 1; ca <=T ;ca++){
		scanf("%d",&N);
		int total[10];
		for(int i=0;i<N;i++){
			scanf("%s",str[i]);
			total[i] = i;
		}
		printf("Case #%d: ",ca);
		fprintf(stderr,"Case #%d: ",ca);
		long long int ans = 0;
		do{
			s[0] = 0;
			for(int i=0;i<N;i++){
				strcat(s, str[total[i]]);
			}
			if(check(s) == 1){
				ans++;
				}
		}while(next_permutation(total,total+N));
		printf("%lld\n",ans);
	}
	return 0;
}
