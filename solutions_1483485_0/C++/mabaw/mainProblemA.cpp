#include <stdio.h>
// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

FILE *fin;
FILE *fout;

int t;
char s[200];
char a[26] = {'y','h','	e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main(int argc, char* argv[])
{

  ofstream fout;
  fout.open ("A-small-attempt3.out");


		fin = fopen("A-small-attempt3.in","r");
	//	fout = fopen("A-small-attempt1.out","w");
	
	fscanf(fin,"%d",&t);
	fgets(s,101,fin);
	for(int i=0;i<t;i++)
	{
		fgets(s,102,fin);
		//fprintf(fout,"Case #%d: ",i+1);
		 fout << "Case #" << i+1 << ": ";
		
		for(int j=0;s[j+1]!='\0';j++)
		{
			if(s[j]==' ')  fout << " ";
			else fout << a[s[j]-'a'] ;
			//if(s[j]==' ') fprintf(fout," ");
			//else fprintf(fout,"%c",a[s[j]-'a']);
		}
		//fprintf(fout,"\n");
		 fout << "\n";
	}
	fclose(fin);
	fout.close();
	return 0;
}