#include<cstdio>
#include<iostream>
using namespace std;

char replace[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int t;
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	scanf("%d\n",&t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		char c;
		do{
			if(scanf("%c",&c) == EOF) break;
			if(c == '\n') break;
			else if(c == ' ') printf("%c", c);
			else if(c >= 'a' && c <= 'z'){
				int pos = c - 'a';
				printf("%c", replace[pos]);
			}
		}while(true);
		printf("\n");
	}
	return 0;
}
			