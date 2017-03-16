#include <cstdio>
#include <cstring>
int T;
char s[1013];
int main(){
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++){
		scanf("%s",&s);
		int slen=strlen(s);
		char ans[1013];
		ans[0] = s[0];
		ans[1] = '\0';
		char maxans = s[0];
		for (int i=1;i<slen;i++){
			if (maxans<=s[i]){
				for (int j=i;j>0;j--){
					ans[j] = ans[j-1];
				}
				ans[0] = s[i];
				maxans=s[i];
				ans[i+1] = '\0';
			}
			else {
				ans[i] = s[i];
				ans[i+1]='\0';
			}
		}
		printf("Case #%d: %s\n",Case, ans);

	}
	return 0;
}
