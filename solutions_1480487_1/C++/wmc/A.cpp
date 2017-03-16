#include <iostream>
#include <fstream>
#include <iomanip.h>

using namespace std;
int main ()
{

    ifstream R("A4.in");
    ofstream W("A4.out");
    int t;
    R>>t;
    for (int i=1;i<=t;++i)
    {
        int n;
        R>>n;
        double sum=0;
        double s[210];
        int m=n;
        int pass[210]={0};
        for(int j=1;j<=n;++j)
        {
            R>>s[j];
            sum=sum+s[j];
        }
        double prec[210];
        for(int j=1;j<=n;++j)
        {
            prec[j]=sum*2/n;
            prec[j]=prec[j]-s[j];
            prec[j]=prec[j]*100;
            prec[j]=prec[j]/sum;
        }
        
        for(int j=1;j<=n;++j)
        {
            if(prec[j]<0)
            {
                prec[j]=prec[j]/(m-1);
                pass[j]=1;
                m--;
                for(int k=1;k<=n;++k)
                {
                    if(pass[k]==0)
                    prec[k]=prec[k]+prec[j];
                }
                prec[j]=0;
            }
        }
        W<<"Case #"<<i<<":";
        for(int j=1;j<=n;++j)
        {
            W<<setprecision(10)<<" "<<prec[j];
        }
        W<<endl;
    }
    system("pause");
}
