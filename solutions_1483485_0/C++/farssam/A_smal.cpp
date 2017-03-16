#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define oo 0x7fffffff
#define N 10000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define SBS(x,y) ((x)<(y)?(y-x):(x-y))

using namespace std;

int t,n,p,m;
char trans[30]="yhesocvxduiglbkrztnwjpfmaq";
char s[1024];

int main(void){
	FILE *in,*out;
	int i,j;

	in=fopen("C-small-attempt0.in","r");
	out=fopen("output.txt","w");


	fscanf(in,"%d",&t);
	fgets(s,1024,in);
	for(i=1;i<=t;i++){
		fgets(s,1024,in);
		n=strlen(s);
		fprintf(out,"Case #%d: ",i);
		for(j=0;j<n;j++){
			if(s[j]>='a' && s[j]<='z')
				fprintf(out,"%c",trans[s[j]-'a']);
			else
				fprintf(out,"%c",s[j]);				
		}
		
	}


	return 0;

}