#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
int main()
{
    ifstream fin("C://google//tongue//a.in");
    ofstream fout("C://google//tongue//out.out");
    char goo[3][200]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                          "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                          "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    char ori[3][200]={"our language is impossible to understand",
                          "there are twenty six factorial possibilities",
                          "so it is okay if you want to just give up"};
    char charset[30];
    int i,j,k;
    //cout<<ori[0]<<endl<<ori[1]<<endl<<ori[2];getch();
    for(i=0;i<30;i++)
                     charset[i]=0;
    charset[25]='q';//missing element already calculated from the output
    charset[16]='z';//given in the description"
    for(i=0;i<3;i++)
    {
                    for(j=0;goo[i][j];j++)
                    {
                                          if(goo[i][j]==' ')
                                                          continue;
                                          charset[goo[i][j]-97]=ori[i][j];
                                          //cout<<ori[i][j]<<endl;
                    }
    }
   
    //actual program starts here
    int t;
    char g[30][200],englipees[30][200],tmp;
    fin>>t;
    fin>>tmp;
    
    for(i=0;i<t;i++)
    {
                    fin.getline(g[i],200);
                    //cout<<g[i]<<endl;
    }
    for(i=0;i<t;i++)
    {
                    
                    
                    for(j=0;g[i][j];j++)
                    {
                                        cout<<g[i][j];
                                        if(g[i][j]==' ')
                                                      englipees[i][j]=' ';
                                        else
                                        if(g[i][j]-97<27&&g[i][j]>=0)
                                        {
                                            
                                          //if(i==)  
                                          englipees[i][j]=charset[g[i][j]-97];
                                          }
                    }
                    englipees[i][j]=0;
                    
                    fout<<"Case #"<<i+1<<": ";
                    if(!i)
                          fout<<charset[tmp-97]<<englipees[i]<<endl;
                    else        fout<<englipees[i]<<endl;
                    
                    //fout<<"Case #"<<i+1<<": "<<englipees[i]<<endl;
                    
    }
    getch();
}
