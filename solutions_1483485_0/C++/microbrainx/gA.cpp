#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int ntc;
char r[110],g[110];
char lookup[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

void translate(char g[],char r[],int n){
	for (int i=0;i<n;i++)
		if (g[i]!=' ') r[i]=lookup[g[i]-'a'];
		else r[i]=' ';
}

int main(){
	scanf("%d\n",&ntc);
	for (int tc=1;tc<=ntc;tc++){
		gets(g);
		memset(r,0,sizeof(r));
		translate(g,r,strlen(g));
		printf("Case #%d: %s\n",tc,r);
	}
	return 0;
}