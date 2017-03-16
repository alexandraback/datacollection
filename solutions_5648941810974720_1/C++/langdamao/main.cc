#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

char biao[11]="ZWXUFVONIR";
char quan[11][11]={"ZERO","TWO","SIX","FOUR","FIVE","SEVEN","ONE","NINE","EIGHT","THREE"};
int num[11]={0,2,6,4,5,7,1,9,8,3};
int have[55],ans[3000];
char str[2005];
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		int l=strlen(str);
		memset(have,0,sizeof(have));
		memset(ans,0,sizeof(ans));
		int n=0;
		for (int i=0;i<l;i++) have[str[i]-'A']++;
		for (int i=0;i<10;i++){
			while(have[biao[i]-'A']){
				int k=strlen(quan[i]);
				for (int j=0;j<k;j++){
					have[quan[i][j]-'A']--;
				}
				ans[n++]=num[i];
			}
		}
		sort(ans,ans+n);
		printf("Case #%d: ",ca++);
		for (int i=0;i<n;i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
