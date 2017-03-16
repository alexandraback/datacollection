#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    ifstream cin ("B-large.in");
    //ofstream cout ("clocks.out");
    freopen ("clock.out", "w", stdout);
    int n;
    cin>>n;
    for(int counter=1;counter<=n;counter++)
    {
        double c,f,x,sum1=0,sum2=0,k=2;
        cin>>c>>f>>x;
        if(c>x)
        sum1=x/2;
        else
        {
        while(1)
        {
            double ii=(c/k);
            if((x/k <= ii+(x/(k+f))))
            {
                sum1+=(x/k);
                break;
            }
            else
            {
                sum1+=ii;
                k+=f;
            }
        }
        }
        cout<<"Case #"<<counter<<": ";
        printf("%.7lf\n",sum1);
    }
return 0;
}
