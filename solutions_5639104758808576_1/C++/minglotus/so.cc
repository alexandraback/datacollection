#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
const int MAXL = 1005;

int cnt[MAXL];
char input[MAXL];
int main(){
//	freopen("1.txt","r",stdin);
	int t, maxlevel;
	scanf("%d", &t);
	int ks = 1;
	while(t--){
		memset(input,0,sizeof(input));
		scanf("%d",&maxlevel);
		scanf("%s",input);
		int curStaPeople = 0;
		int additional = 0;
		for(int i = 0; i <= maxlevel; ++i){
			if(input[i] == '0'){
				continue;
			}
			int tmp = 0;
			if(curStaPeople < i){
				tmp = i - curStaPeople;
				additional += tmp;
				curStaPeople += tmp;
			}
			curStaPeople += input[i] - '0';
		}
		printf("Case #%d: %d\n", ks++, additional);
	}
	return 0;
}
		
		
