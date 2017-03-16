#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;                   

int main()
{
    int cases;
    char input, output;
    ifstream inputfile;
    ofstream outputfile;
    inputfile.open("A-small.in");
    outputfile.open("A-small.out");
    inputfile >> cases;
    cout<<cases<<"\n";
    input=inputfile.get();
    for(int i=0; i<cases; i++)
                      {
                              outputfile<<"Case #"<<i+1<<": ";
                              do
                              {
                              input=inputfile.get();
                              cout<<input<<"\n";
                              if(input=='a')
                              output='y';
                              else if(input=='b')
                              output='h';
                              else if(input=='c')
                              output='e';
                              else if(input=='d')
                              output='s';
                              else if(input=='e')
                              output='o';
                              else if(input=='f')
                              output='c';      
                              else if(input=='g')
                              output='v';
                              else if(input=='h')
                              output='x';
                              else if(input=='i')
                              output='d';
                              else if(input=='j')
                              output='u';
                              else if(input=='k')
                              output='i';                 
                              else if(input=='l')
                              output='g';
                              else if(input=='m')
                              output='l';
                              else if(input=='n')
                              output='b';
                              else if(input=='o')
                              output='k';
                              else if(input=='p')
                              output='r';
                              else if(input=='q')
                              output='z';
                              else if(input=='r')
                              output='t';
                              else if(input=='s')
                              output='n';
                              else if(input=='t')
                              output='w';
                              else if(input=='u')
                              output='j';
                              else if(input=='v')
                              output='p';
                              else if(input=='w')
                              output='f';
                              else if(input=='x')
                              output='m';
                              else if(input=='y')
                              output='a';
                              else if(input=='z')
                              output='q';
                              else if(input==' ')
                              output=input;
                              outputfile.put(output);
                              }while(input!='\n' && !inputfile.eof());          
                              outputfile<<"\n";
                      }
    inputfile.close();
    outputfile.close();
    getch();
    return 0;
}
