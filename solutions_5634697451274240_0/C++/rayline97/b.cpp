#include <cstdio>
#include <cstring>

int main(){
	char s[186];
	int T;
	scanf("%d",&T);
	for(int j = 1;j<=T;j++){
		scanf("%s",s);
		int n = strlen(s);
		int sum = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='-') ++sum;
		}
		int ans = 0;
		while(sum){
			ans++;
			if(s[0]=='+'){
				for(int i=0;i<n;i++){
					if(s[i]=='+'){
						s[i] = '-';
						sum++;
					}else break;
				}
			}else{
				for(int i=0;i<n;i++){
					if(s[i]=='-') {
						s[i] = '+';
						sum--;
					}else break;
				}
			}
		}
		printf("Case #%d: %d\n", j, ans);
	}
}