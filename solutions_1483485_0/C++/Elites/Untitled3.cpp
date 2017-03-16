#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>

using namespace std;

int main ()
{
     int x,l,tem,cas;
     char ch,a[1000],b[1000],k[100]={0};
     ifstream file("C:/Users/Rahul/Desktop/A-small-attempt3.in");
     ifstream ifile("C:/Users/Rahul/Desktop/key.txt");
     ofstream ofile("C:/Users/Rahul/Desktop/output.txt");
     for(x=0;x<=25;x++)
     {
                      ifile.get(ch);
                      ifile.get(ch);
                      ifile.get(ch);
                      k[x]=ch;
                      ifile.get(ch);
     }
     file>>tem;
     file.get(ch);
     while(cas++!=tem)
     {
                      file.getline(a,1000);
                               l=strlen(a);
                               for(x=0;x<l;x++)
                               {
                                               if(isalpha(a[x])) b[x]=k[a[x]-97];
                                               else b[x]=a[x];
                               }
                               b[x]=0;
                               ofile<<"Case #"<<cas<<": "<<b<<endl;
                               
     }
     file.close();
     ofile.close();
     //system("pause");
     return 0;
}
