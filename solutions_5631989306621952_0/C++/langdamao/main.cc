#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
char str[1005],qian[1005],hou[1005];
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int qiannow=0;
		int hounow=0;
		scanf("%s",str);
		int l=strlen(str);
		qian[qiannow]=str[0];
		qiannow++;
		for (int i=1;i<l;i++){
			if(str[i]>=qian[qiannow-1]){
				qian[qiannow++]=str[i];
			}
			else{
				hou[hounow++]=str[i];
			}
		}
		printf("Case #%d: ",ca++);
		for (int i=qiannow-1;i>=0;i--) printf("%c",qian[i]);
		for (int i=0;i<hounow;i++) printf("%c",hou[i]);
		printf("\n");
	}
	return 0;
}
