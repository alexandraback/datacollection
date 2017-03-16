#include<stdio.h>
#include<string.h>

char text[110];
char dic[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,T;
	scanf("%d\n",&T);
	for(t=0;t<T;t++){
		fgets(text, 109, stdin);
		int l = strlen(text);

		for(int i=0;i<l;i++){
			if(text[i] != ' ')
				text[i] = dic[text[i] - 97];
		}
		printf("Case #%d: ",t+1);
		fputs(text, stdout);
		printf("\n");
	}
	return 0;
}