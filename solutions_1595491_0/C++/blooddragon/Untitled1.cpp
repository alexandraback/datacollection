#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;                   

int main()
{
    int cases, input2, number, surprise, minimum, normaltotal, surprisetotal, j, blah;
    char input1, output;
    ifstream inputfile;
    ofstream outputfile;
    inputfile.open("B-small-attempt1.in");
    outputfile.open("B-small.out");
    inputfile >> cases;
    cout<<cases<<"\n";
    input1=inputfile.get();
    for(int i=0; i<cases; i++)
    {
            blah=0;
            outputfile<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<": \n";
            inputfile>>number;
            input1=inputfile.get();
            cout<<number<<" ";
            inputfile>>surprise;
            cout<<surprise<<" ";
            input1=inputfile.get();
            inputfile>>minimum;
            cout<<minimum<<" ";
            input1=inputfile.get();
            if(minimum>=1)
            normaltotal=minimum+(2*(minimum-1));
            else
            normaltotal=minimum;
            if(minimum>=2)
            surprisetotal=minimum+(2*(minimum-2));
            else
            surprisetotal=minimum;
            cout<<"\nNormal Total:"<<normaltotal<<"\nSurprise Total:"<<surprisetotal<<"\n";
            for(j=0; j<number; j++)
            {
                     inputfile>>input2;
                     input1=inputfile.get();
                     cout<<input2<<" ";
                     if(input2>=normaltotal)
                     blah++;
                     else if(input2>=surprisetotal && surprise>0)
                     {
                     blah++;
                     surprise--;
                     }
            }
            outputfile<<blah<<"\n";
            cout<<"\n"<<blah<<"\n";
    }
    inputfile.close();
    outputfile.close();
    getch();
    return 0;
}
