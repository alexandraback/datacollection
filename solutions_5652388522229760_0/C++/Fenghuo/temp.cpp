#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool ex[10];
int result[1000001];

void filll(int a)
{
    while (a!=0)
    {
        ex[a%10]=true;
        a/=10;
    }
}

bool alltrue()
{
    int i;
    for (i=0;i<10;i++)
    {
        if (ex[i]==false) break;
    }

    if (i==10) return true;
    else return false;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,t,tt;
    int i,j,k;

    for (i=0;i<1000001;i++) result[i]=0;

    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        cin>>t;

        for (i=0;i<10;i++) ex[i]=false;

        int test=1;
        while (test<100)
        {
            filll(t*test);
            if (alltrue())
            {
                result[t]=t*test;
                break;
            }

            test++;
        }

        if (test==100) cout<<"Case #"<<tt<<": INSOMNIA"<<endl;
        else cout<<"Case #"<<tt<<": "<<result[t]<<endl;
    }

    return 0;
}


