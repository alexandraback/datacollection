#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#define fin in
#define fout out
typedef unsigned uint;
uint T;
double C,F,X,minTime;
double a;
struct context
{
    double rate;
    double now;
    double spended;

};
int main()
{
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small-attempt0.txt");
    in >> T;
    context text;    
    out<<fixed;
    out<<setprecision(7); 
    for (uint i = 0; i < T; i++)
    {
        in>>C>>F>>X;
        text.now=0;
        text.rate=2;
        text.spended=0.0;
        minTime=X/2;
        while(text.spended<minTime)
        {
            a=text.spended+(X-text.now)/text.rate;//without change
            minTime=(a<minTime)?a:minTime;
            if(text.now<C)
            {
                text.spended=text.spended+(C-text.now)/text.rate;
                text.rate+=F;
                text.now=0;
            }
        }
        out<<"Case #"<<i+1<<": "<<minTime<<endl;
    }
    fin.close();
    fout.close();
}
