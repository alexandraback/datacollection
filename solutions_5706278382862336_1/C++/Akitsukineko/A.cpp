
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


long
gcd ( long a, long b )
{
    long c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}


int main()
{
    int numTestCase;
    cin>>numTestCase;
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
    	long P = 0;
        long Q = 0;
        double a;
        
        int result = 0;
        string temp = "";
        string num1 = "";
        string num2 = "";
        
    	cin>>temp;
       
        int i = 0;
        for (; temp[i]!='/'; i++) {
            //cout<<temp[i];
            num1.append(1,temp[i]);
        }
        i+=1;
        for (; temp[i]!=NULL; i++) {
            //cout<<temp[i];
            num2.append(1,temp[i]);
        }
        P = std::stol(num1);
        Q = std::stol(num2);
        
        P = P/gcd(P,Q);
        Q = Q/gcd(P,Q);
        
        
        a = (double)P/(double)Q;
        

        
        if ((Q^(Q-1))<Q) {
            cout<<"Case #"<<tc+1<<": impossible"<<endl;
        }
        else
        {
            int i = 0;
            double tmp = 1;
            for (; tmp>a; i++) {
                tmp = tmp/2;
                //cout<< tmp;
            }
            result = i;
            
            cout<<"Case #"<<tc+1<<": "<<result<<endl;
        }
        

    }

    return 0;
}

