#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b, pot;
        cin>>a>>b;
        double total=1,c[100000]={0}, min,val;
        min = b+2;
        for(int j=1;j<=a;j++)
        {
            cin>>c[j];
            total*=c[j];
            val = (a+b+1-j*2)*total+(a+2*b+2-j*2)*(1-total);
            if(val<min)min=val;
        }
        //val = *total + *(1-total);
        if(val<min)min=val;
        cout<<"Case #"<<i+1<<": "<< setiosflags(ios::fixed)<<setprecision(6)<<min<<endl;
    }
    return 0;
}
