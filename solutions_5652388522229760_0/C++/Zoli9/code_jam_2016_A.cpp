#include <bits/stdc++.h>
using namespace std;
long long n, akt;
bool volt[10];
int test;
void f(long long x)
{
    while(x>0)
    {
        volt[x%10]=true;
        x/=10;
    }
}
int main()
{
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        for(int j=0; j<10; j++)
        {
            volt[j]=false;
        }
        bool kesz=false;
        if(n==0)
        {
            cout<<"Case #"<<tt<<": INSOMNIA"<<endl;
            continue;
        }
        akt=n;
        while(1)
        {
            f(akt);
            bool jo=true;
            for(int i=0; i<10; i++)
            {
                if(!volt[i])
                {
                    jo=false;
                    break;
                }
            }
            if(jo)
            {
                cout<<"Case #"<<tt<<": "<<akt<<endl;
                kesz=true;
                break;
            }
            akt+=n;
        }
    }


    return 0;
}
