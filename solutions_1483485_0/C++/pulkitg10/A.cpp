#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<ctype.h>
using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
char rep[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[10000];
int main(){
	int t ,i,test;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf(" %[^\n]",s);
		for(i=0;i<strlen(s);i++)
			if(!isspace(s[i]))
				s[i]=rep[s[i]-'a'];
		printf("Case #%d: %s\n",t,s);
	}
	return 0;
}

