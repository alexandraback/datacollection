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
        double C,F,X;
        in >> C >> F >> X;

        //cout << "Read values = " << C << " " << F << " "<< X << endl;
        double prevTime = X/2;
        double reuseTerm = 0;
            //cout << " Calculated time with farms = " << 0 << " == "<<prevTime << endl;
        for(int i = 1; i < 100000; ++i)
        {
            double newTerm1 = C/(2+ (i-1)*F);
            double newTerm2 = X/(2+ i*F);
            reuseTerm += newTerm1;
            double time = reuseTerm + newTerm2;
            //cout << " Calculated time with farms = " << i << " == "<<time << endl;
            if(time > prevTime)
            {
                break;
            }
            prevTime = time;
        }
        
        out << "Case #"<<caseN+1<<": ";
        out.setf( std::ios::fixed, std:: ios::floatfield );
        out.precision(7);
        out << prevTime << endl;
    }
        
    in.close();
    out.close();
    return 0;
}
