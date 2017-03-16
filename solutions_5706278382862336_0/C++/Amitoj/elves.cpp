#include <algorithm>  
#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <list>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <iomanip>  
using namespace std;  

#define FOR(i,a,b) for(long i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  


int main(int argc, char** argv)
{
    ifstream in;
    in.open(argv[1],ios::in);
    ofstream out;
    out.open(argv[2],ios::out);
    int N = 0;
    in>>N;
    cout << " Total  " << N <<endl;
    REP(caseN,N)
    {
        cout<<"solving case "<<caseN+1<<endl;
        long long P,Q;
        char c;
        in >> P >> c >> Q;;

        cout << "Read values = " << P << " " << Q << endl;

        if(Q & (Q-1))
        {
            long long pwr = 1;
            while (Q%2 == 0)
            {
                Q >>= 1;
                pwr <<= 1;
            }

            if(P%Q == 0) 
            {
                P/= Q;
                Q = pwr;
            }
            else
            {
                out << "Case #"<<caseN+1<<": " << "impossible" << endl;
                continue;
            }
        }
        cout << "After reduction.. P = " << P << " Q = " << Q << endl;
        
        int Gens = 0;
        long long qq = Q;
        while(qq)
        {
            Gens++;
            qq >>=1;
        }
        Gens--;

        int subGen = 0;
        long long temp = 2;
        while(temp <= P)
        {
            subGen++;
            temp <<= 1;
        }

        cout << " Gens = " << Gens << " Sub gen = " << subGen << endl;
        int final = Gens -subGen;
        if (final>40 or (final <0))
                out << "Case #"<<caseN+1<<": " << "impossible" << endl;
        else
                out << "Case #"<<caseN+1<<": " << final << endl;
    }
        
    in.close();
    out.close();
    return 0;
}
