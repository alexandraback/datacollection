#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int I=0;
    double C,F,X,minVal,temp,K;
    long long int CI,FI,XI,KI,minValI,tempI;
    while(T--)
    {
        I++;
        cin>>C>>F>>X;
        //CI=C*100000000;
        //FI=F;
        //XI=X*100000000;
        minVal=X/2;
        temp=C/2;
        K=2+F;
        while(temp+X/K<minVal)
        {
            minVal=temp+X/K;
            temp+=C/K;
            K+=F;
        }
        printf("Case #%d: %.7f\n",I,minVal);

    }
}
