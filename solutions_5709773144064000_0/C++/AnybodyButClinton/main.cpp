#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream in("B-small-attempt0.in");
ofstream out("output.out");

int t;
double s,c,f,x,n,d;

void reset()
{
    s=2;
    n=0;
    d=0;
}

void scan()
{
    in>>c>>f>>x;
}

bool buyornot()
{
    if((x-c)/s>x/(s+f))return 1;
    else return 0;
}
//n=0 or c or x
void calculate()
{
    while(n!=x)
    {
        if(n==0)
        {
            if(c<x)
            {
               d+=(c/s);
               n=c;
            }
            else
            {
                d+=(x/s);
                n=x;
            }
        }
        if(n==c)//c<x
        {
            if(buyornot())
            {
                s+=f;
                n=0;
            }
            else
            {
                d+=((x-c)/s);
                n=x;
            }
        }
    }
}

void print(int t)
{
    out<<"Case #"<<t<<": "<<setprecision(60)<<d<<endl;
}

int main()
{
    in>>t;
    for(int i=0;i<t;i++)
    {
        reset();
        scan();
        calculate();
        print(i+1);
    }
    return 0;
}
