#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    cin >> t;
    int A;
    int N;
    int mote[100];
    for (int casenum=1; casenum<=t; casenum++)
    {
        cin >> A;
        cin >> N;
        for (int i=0; i<N; i++)
            cin >> mote[i];

        int incre=0;
        int result=N;

        if (A!=1)
        {
            for (int i=0; i<N; i++)
                for (int j=i+1;j<N;j++)
                    if (mote[j]<mote[i])
                    {
                        int temp=mote[j];
                        mote[j]=mote[i];
                        mote[i]=temp;
                    }

            for (int i=0; i<N; i++)
            {
                if (mote[i]<A)
                    A=A+mote[i];
                else
                {
                    int temp=N-i+incre;
                    if (temp<result)
                        result=temp;
                    int k=1;
                    while ((A=2*A-1)<=mote[i] && k+incre<result)
                        k++;
                    incre=incre+k;
                    if (incre>=result)
                        break;
                    else
                        A=A+mote[i];
                }
            }
            if (incre<result)
                result=incre;
        }
        cout << "Case #" << casenum << ": " << result  << endl;
    }
    return 0;
}
