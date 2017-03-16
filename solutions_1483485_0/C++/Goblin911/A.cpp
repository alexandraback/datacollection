#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

char f[256];
int n;
bool ff[256];
void init(){
	freopen("A.in","r",stdin);
	char a[100],b[100];
	for (int t=0;t<3;t++){
		scanf("%[^\n]%*c",a);
		scanf("%[^\n]%*c",b);
		//printf("%s : %s\n",a,b);
		for (int i=0;i<strlen(a);i++) f[a[i]]=b[i];
	}
	f['z']='q';f['q']='z';
}

void solve(){
	freopen("A.out","w",stdout);
	scanf("%d\n",&n);char s[1000],ans[10000];;
	for (int t=1;t<=n;t++){
		scanf("%[^\n]%*c",s);
		printf("Case #%d: ",t);
		for (int i=0;i<strlen(s);i++) {
			ans[i]=f[s[i]];
		}
			
		ans[strlen(s)]='\0';
		printf("%s",ans);
		printf("\n");
	}
}

int main(){
	init();
	solve();
}