#include<fstream.h>
#include<iostream.h>
#include<ctype.h>
int main()
{
    ofstream fout("C://wiki//tongue//out.out");
    ifstream fin("C://wiki//tongue//a.in");
    char tru[3][200]={"our language is impossible to understand",
                          "there are twenty six facttrual possibilities",
                          "so it is okay if you want to just give up"};
    char google[3][200]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                          "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                          "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    char alphamap[30];
    int i,j,k;
    for(i=0;i<30;i++)
                     alphamap[i]=0;
    alphamap[16]='z';
    alphamap[25]='q';
    for(i=0;i<3;i++)
    {
                    for(j=0;google[i][j];j++)
                    {
                                          if(google[i][j]==' ')
                                                          continue;
                                          alphamap[google[i][j]-97]=tru[i][j];
                                          
                    }
    }
   
    char g[30][200],english[30][200],tmp;
    int t;
    fin>>t;
    fin>>tmp;
    for(i=0;i<t;i++)
    {
                    fin.getline(g[i],200);
    }
    for(i=0;i<t;i++)
    {
                    
                    
                    for(j=0;g[i][j];j++)
                    {
                                        cout<<g[i][j];
                                        if(g[i][j]==' ')
                                                      english[i][j]=' ';
                                        else
                                        if(g[i][j]-97<27&&g[i][j]>=0)
                                        {
                                          english[i][j]=alphamap[g[i][j]-97];
                                          }
                    }
                    english[i][j]=0;
                    
                    fout<<"Case #"<<i+1<<": ";
                    if(!i)
                          fout<<alphamap[tmp-97]<<english[i]<<endl;
                    else        fout<<english[i]<<endl;
                    
                    
    }
}
