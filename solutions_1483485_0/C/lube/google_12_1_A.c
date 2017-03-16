#include<stdio.h>
int main(void)
{
      FILE *fp,*fout;
      fp=fopen("\A-small-attempt6.in","r");
      fout=fopen("google_12_A_out.txt","w");
      int T;
      char ch;
      fscanf(fp,"%d",&T);
      int i;
      fscanf(fp,"%d");
      for(i=1;i<=T;i++)
      {
            fprintf(fout,"Case #%d: ",i);
            while((fscanf(fp,"%c",&ch)==1)&& (ch!='\n'))
            {
                  switch(ch)
                  {
                        case 'a':fprintf(fout,"y");break;case 'n':fprintf(fout,"b");break;
                        case 'b':fprintf(fout,"h");break;case 'o':fprintf(fout,"k");break;
                        case 'c':fprintf(fout,"e");break;case 'p':fprintf(fout,"r");break;
                        case 'd':fprintf(fout,"s");break;case 'q':fprintf(fout,"z");break;
                        case 'e':fprintf(fout,"o");break;case 'r':fprintf(fout,"t");break;
                        case 'f':fprintf(fout,"c");break;case 's':fprintf(fout,"n");break;
                        case 'g':fprintf(fout,"v");break;case 't':fprintf(fout,"w");break;
                        case 'h':fprintf(fout,"x");break;case 'u':fprintf(fout,"j");break;
                        case 'i':fprintf(fout,"d");break;case 'v':fprintf(fout,"p");break;
                        case 'j':fprintf(fout,"u");break;case 'w':fprintf(fout,"f");break;
                        case 'k':fprintf(fout,"i");break;case 'x':fprintf(fout,"m");break;
                        case 'l':fprintf(fout,"g");break;case 'y':fprintf(fout,"a");break;
                        case 'm':fprintf(fout,"l");break;case 'z':fprintf(fout,"q");break;
                        case ' ':fprintf(fout," ");
                  }
            }
            fprintf(fout,"\n");
      }
      fclose(fp);fclose(fout);
      return 0;
}
