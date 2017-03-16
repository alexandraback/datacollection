#include<stdio.h>

char map[]="yhesocvxduiglbkrztnwjpfmaq";

int main(int argc,char *argv[])
{
	char ip[1000],ch;
	int T,ite,size,i;
	FILE *fp,*fp1;
	fp=fopen(argv[1],"r");
	fp1=fopen("output.txt","w");
	fscanf(fp,"%d\n",&T);
	for(ite=1;ite<=T;ite++)
	{	
		size=0;
		fprintf(fp1,"Case #%d: ",ite);
		while(1)
		{
			ch=getc(fp);
			//printf("%c",ch);
			if(ch=='\n')
				break;
			else if(ch>='a'&&ch<='z')
			{
				ch=map[ch-'a'];
				//printf("%c",ch);
			}
			putc(ch,fp1);
			//ip[size]=ch;
			//size++;
		}
		fprintf(fp1,"\n");
		/*ip[size]='\0';
		  for(i=0;;i++)
		  {
		  if(ip[i]=='\0')
		  break;
		  printf("%c",ip[i]);
		  }*/
	}
	return 1;
}
