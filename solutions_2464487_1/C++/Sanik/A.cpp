#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("AL.in");
ofstream fout("Aout.txt");

int N;
unsigned long long low, high;
unsigned long long t,r;

long double area(long double n)
{
       long double rx = r;
       return n+2*n*(n-1)+2*n*rx;
}

void s()
{
   unsigned long long test = (low+high)/2;
   long double a = area(test);
   if(a<=t) low = test;
   else high = test;
}

int main()
{
    fin >> N;
    for(int i=0;i<N;i++)
    {
            fin >> r >> t;
            high = t/r*2+1;
            low = 1;
            //cout << low << " " << high << endl;
            while(low+1!=high)s();
            fout << "Case #" << i+1 << ": " << low << endl;
    }
    
    system("pause");
}
