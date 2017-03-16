#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    ifstream R("B-small-attempt0.in");
    ofstream W("B1.out");
    int t,n,s,p,ti[101];
    int num;
    R>>t;
    for(int i=1;i<=t;++i)
    {
        num=0;
        R>>n>>s>>p;
        for(int j=1;j<=n;++j)
        {
            R>>ti[j];
            if(p==0)
            {
                num++;
                continue;
            }
            if(ti[j]>=3*p-2 && 3*p-2>=0)
            {
                num++;
                continue;
            }
            if(ti[j]<3*p-2 && ti[j]>=3*p-4 && 3*p-4>=0 && s>0)
            {
                num++;
                s--;
            }
        }
        W<<"Case #"<<i<<": "<<num<<endl;
    }
    system("pause");    
}
