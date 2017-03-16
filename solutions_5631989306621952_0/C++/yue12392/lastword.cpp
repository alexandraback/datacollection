#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int T,f,r;
char str[2000],ans[3000];

int main(){
	freopen("lastword.in","r",stdin);
	freopen("lastword.out","w",stdout);
	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf(" %s",str);
		f=1500; r=1500; ans[f]=str[0];
		for(int j=1;j<strlen(str);j++){
			if (str[j]>=ans[f]){
				f--; ans[f]=str[j];
			}
			else {
				r++; ans[r]=str[j];
			}
		}
		printf("Case #%d: ",i);
		for (int j=f; j<=r; j++) printf("%c",ans[j]); printf("\n");
	}
	return 0;
}
