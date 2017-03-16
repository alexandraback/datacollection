#include <stdio.h>
#include <string.h>
#define MAX 105

int main()
{
	int test_case, i,j;
	char normal[MAX];
	char mapping[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	FILE* fp;

	fp = fopen("output.txt","w");

	scanf("%d",&test_case);
	getchar();
	for(i=1; i<=test_case; i++) {
		gets(normal);
		fprintf(fp,"Case #%d: ",i);
		for(j=0; j<strlen(normal); j++) {
			if(normal[j]!=' ') fprintf(fp,"%c",mapping[normal[j]-'a']);
			else fprintf(fp,"%c",normal[j]);
		}
		fprintf(fp,"\n");
	}
	return 0;
}