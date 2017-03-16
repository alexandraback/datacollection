#include<stdio.h>
int T ,X ,Y;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i;
	char tok[5];
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d %d", &X, &Y);
		printf("Case #%d: ", t);
		tok[2] = 0;

		if(X>0) tok[0]='W', tok[1]='E';
		else{
			tok[0]='E', tok[1]='W';
			X *= -1;	
		}
		for(i=1; i<=X; i++) printf("%s",tok);

		if(Y>0) tok[0]='S', tok[1]='N';
		else{
			tok[0]='N', tok[1]='S';
			Y *= -1;	
		}
		for(i=1; i<=Y; i++) printf("%s",tok);
		printf("\n");
	}
	return 0;
}