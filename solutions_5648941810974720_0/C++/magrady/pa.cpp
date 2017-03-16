#include<stdio.h>
#include<algorithm>
#include<string>
const char f[]="ZWUXGOHFSI";
const char g[]="0246813579";
const char *h[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[100001];
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		int i,j,k;
		scanf("%s",s);
		int n;
		for(n=0;s[n];n++);
		int cnt[26]={0};
		int ans[10]={0};
		for(i=0;i<n;i++){
			cnt[s[i]-'A']++;
		}
		for(i=0;i<10;i++){
			int c=cnt[f[i]-'A'];
			ans[g[i]-'0']=c;
			for(j=0;h[g[i]-'0'][j];j++){
				cnt[h[g[i]-'0'][j]-'A']-=c;
			}
		}
		printf("Case #%d: ",T);
		for(i=0;i<=9;i++){
			for(j=0;j<ans[i];j++){
				printf("%c",i+'0');
			}
		}
		puts("");
	}
}
