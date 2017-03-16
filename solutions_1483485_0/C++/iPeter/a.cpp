#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

char g[200];
char p[60] = {
	'y', 'h', 'e', 's', 'o', 'c', 'v',
	'x', 'd', 'u', 'i', 'g', 'l', 'b',
	'k', 'r', 'z', 't', 'n', 'w', 'j',
	'p', 'f', 'm', 'a', 'q'};
int main(){
	int t;
	scanf("%d%*c",&t);
	for(int i=0;i<t;i++){
		gets(g);
		for(int j=0;g[j]!=0;j++){
			if(g[j]==' ') continue;
			g[j]=p[g[j]-'a'];
		}
		printf("Case #%d: %s\n", i+1, g);
	}
	
	return 0;
}
