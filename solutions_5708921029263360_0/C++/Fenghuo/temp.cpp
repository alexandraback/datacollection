#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <set>
#include <vector>
using namespace std;

int a[10][10][10];
int b[10][10],c[10][10],d[10][10];

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,TT;
    long long i1,i2,i0;



    cin>>T;
    for(TT=1;TT<=T;TT++)
    {
        int j,p,s,k;
        cin>>j>>p>>s>>k;

        for (i0=0;i0<10;i0++)
            for (i1=0;i1<10;i1++)
                for (i2=0;i2<10;i2++)
                    a[i0][i1][i2]=0;

        for (i0=0;i0<10;i0++)
            for (i1=0;i1<10;i1++)
            {
                b[i0][i1]=0;
                c[i0][i1]=0;
                d[i0][i1]=0;
            }

        for (i0=0;i0<j;i0++)
            for (i1=0;i1<p;i1++)
                for (i2=0;i2<s;i2++)
                {
                    if (b[i0][i1]<k && c[i1][i2]<k && d[i0][i2]<k)
                    {
                        a[i0][i1][i2]=1;
                        b[i0][i1]++;
                        c[i1][i2]++;
                        d[i0][i2]++;
                    }
                }

        int cnt=0;
        for (i0=0;i0<j;i0++)
            for (i1=0;i1<p;i1++)
                for (i2=0;i2<s;i2++)
                {
                    if (a[i0][i1][i2]==1) cnt++;
                }

        cout<<"Case #"<<TT<<": "<<cnt<<endl;
        for (i0=0;i0<j;i0++)
            for (i1=0;i1<p;i1++)
                for (i2=0;i2<s;i2++)
                {
                    if (a[i0][i1][i2]==1) cout<<i0+1<<" "<<i1+1<<" "<<i2+1<<endl;
                }
    }


    return 0;
}
