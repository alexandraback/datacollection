#include <stdio.h>

char s[101];
int dap[101];

int main()
{
    int t;
    int i,j;

    FILE  *in, *out;

    in=fopen("B-large.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++){
        fscanf(in,"%s",&s);

        j=1;
        while(s[j]!='\0'){
            if(s[j]!=s[j-1]) dap[i]++;
            j++;
        }
        if(s[j-1]=='-') dap[i]++;

        for(j=0;j<102;j++) s[j]='\0';
	}

	for(i=1;i<=t;i++){
        fprintf(out,"Case #%d: %d\n",i,dap[i]);
	}
}
