#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    int t;
    ifstream R("C-small-attempt0.in");
    ofstream W("C1.out");
    R>>t;
    for(int i=1;i<=t;++i)
    {
        int a,b;
        R>>a>>b;
        int c=a;
        int digt=0;
        int num=0;
        int base=1;
        while(c>0)
        {
            c=c/10;
            digt++;
        }
        for(int j=1;j<digt;j++)
            base=base*10;
        for(int j=a;j<b;++j)
        {
            int m[10];
            m[1]=j;
            for(int k=1;k<digt;k++)
            {
                m[k+1]=(m[k]%10)*base+(m[k]/10);
                int good=1;
                for(int l=1;l<=k;++l)
                    if(m[k+1]==m[l])
                        good=0;
                if(m[k+1]>j && m[k+1]<=b && good==1)
                    num++;
            }
        }
        W<<"Case #"<<i<<": "<<num<<endl;
    }
    system("pause");    
}
