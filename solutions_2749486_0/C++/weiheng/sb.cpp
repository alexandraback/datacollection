#include <iostream>
#include <cmath>
using namespace std;

char EW[2]={'E','W'};
char NS[2]={'N','S'};
int now;

int step(int x, char *str)
{
    int p=0;
    if(x<0)
    {
        while(p>x)
        {
            p-=now;
            now++;
            cout<<str[1];
        }
    }
    int i=x-p;
    while(i>0)
    {
        cout<<str[1]<<str[0];
        i--;
        now+=2;
    }
}

int main()
{
    int t,cas;
    int x,y;
    cas=1;
    int i,j;
    cin>>t;
    while(cas<=t)
    {
        cin>>x>>y;
        now=1;
        cout<<"Case #"<<cas<<": ";
        if(abs(x)<abs(y))
        {
            step(x,EW);
            step(y,NS);
        }
        else
        {
            step(y,NS);
            step(x,EW);
        }
        cout<<endl;
        cas++;
    }
    return 0;
}
