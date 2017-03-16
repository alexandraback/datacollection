#include <iostream>
#include <cmath>
using namespace std;
char rep[27] = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	char str[110];
	int i,j,t;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++){
		gets(str);
		for(j=0;str[j]!='\0';j++)
			if(str[j]>='a'&&str[j]<='z')
				str[j]=rep[str[j]-'a'];
		printf("Case #%d: %s\n",i,str);
	}
	return 0;
}