#include<iostream>
#include<cstdio>

using namespace std;
char trans[26]={'y','h','e','s','o',
                'c','v','x','d','u',
                'i','g','l','b','k',
                'r','z','t','n','w',
                'j','p','f','m','a',
                      'q'};

int main(){
	int t,kase=1;
	char c;
	scanf("%d",&t);
	c=getchar();
	while(t--){
		printf("Case #%d: ",kase);
		kase++;
		c=getchar();
		while(c != '\n'){
			if(c == ' ')
				printf(" ");
			else 
				printf("%c",trans[c-'a']);
			c=getchar();
		}
		printf("\n");
	}
	return 0;
}
