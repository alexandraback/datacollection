#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<string>

using namespace std;

char map[27] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char G[101];

int main(){
	int n, i, j;
	char c,dummy;
	
	scanf("%d",&n);
	scanf("%c",&dummy);
	
	for (i = 0 ; i < n ; i++){
		gets(G);
		for (j = 0 ; j < strlen(G) ; j++)
			if ((G[j] >= 97) && (G[j]<=122))
				G[j] = map[G[j]-97];
		printf("Case #%d: %s\n",i+1,G);
	}
	return 0;
}