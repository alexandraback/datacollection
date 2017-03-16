#include <stdio.h>
#include <string.h>
char conv[28]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main(){
	int i,test,testt,len;
	char mun[1000]={0,};
	FILE *in,*out;
	in=fopen("input.txt","r");
	fscanf(in,"%d\n",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fgets(mun,1000,in);
		len=strlen(mun);
		fprintf(out,"Case #%d: ",test);
		if(mun[len-1]==10)
			len--;
		for(i=0;i<len;i++){
			if(mun[i]>='a' && mun[i]<='z')
				fprintf(out,"%c",conv[mun[i]-'a']);
			else
				fprintf(out,"%c",mun[i]);
		}
		fprintf(out,"\n");
	}
	fcloseall();
	return 0;
}
