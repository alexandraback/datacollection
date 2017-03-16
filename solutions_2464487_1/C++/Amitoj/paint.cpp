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
#include "bigInt.h"
using namespace std;  
typedef BigInt::Rossi Integer;

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
        uint64_t r,t;
        Integer high (100000000000);
        Integer low (1);


        Integer num;
        
        in >> r >> t;
        r= r+r+1;
        Integer one(1);
        Integer two(2);
        Integer RR(r);
        Integer TT(t);
        while(1)
        {
            if(high == low)
            {
                num = high; break;
            }
            else if(high < low)
            {
                num = low; 
                cout <<"===================weir====================\n";
                break;
            }
            else if(high -low == one)
            {
                num = high;
                Integer sum;
                sum = num*(RR+(two*num)-two);
                if(sum >TT )
                    num = low;
                break;
            }
            num = (high + low)/two;
            Integer sum ;
                sum = num*(RR+(two*num)-two);
            if(sum < TT) {
                low = num;
            } else if (sum == TT)
            {
                break;
            }
            else
            {
                high = num;
            }
        }

        out << "Case #"<<caseN+1<<": " << num.toUlong() << endl;

    }
        
    in.close();
    out.close();
    return 0;
}
