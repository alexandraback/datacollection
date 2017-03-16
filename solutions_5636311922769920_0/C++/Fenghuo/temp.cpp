#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

long long power(long long a, long long b)
{
    long long result=1;
    while (b--) result*=a;
    return result;
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,t,tt;
    long long i,j,k;

    long long a,b,c;
    long long result;
    bool endd;

    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        cin>>a>>b>>c;
        if (a>b*c)
        {
            cout<<"Case #"<<tt<<": IMPOSSIBLE"<<endl;
            continue;
        }

        cout<<"Case #"<<tt<<":";

        i=0;
        endd=false;
        while(1)
        {
            j=b-1;
            result=0;
            while(1)
            {
                result+=i*power(a,j);
                j--;
                i++;
                if (i==a) {i=0;endd=true;}
                if (j<0) break;
            }
            cout<<" "<<result+1;
            if (endd) break;
        }
        cout<<endl;
    }

    return 0;
}


