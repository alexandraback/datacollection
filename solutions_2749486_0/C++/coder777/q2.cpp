#include <iostream>
#include<fstream>

using namespace std;
int main()
{
    int t,a,b,i,j,n=2,k;
    ifstream fin("inp.txt");
    ofstream fout("outp.txt");
    fin>>t;
    for(j=1;j<=t;j++)
    {
        fin>>a>>b;
        fout<<"Case #"<<j<<": ";
        //for(k=0;k<n;k++)
        if(a>0 && b>0)
        {
            for(i=1;i<=a;i++)
                fout<<"WE";

            for(i=1;i<=b;i++)
                fout<<"SN";

        }
        else if(a==0 && b>0)
            for(i=1;i<=b;i++)
                fout<<"SN";

        else if(a<0 && b>0)
        {
            for(i=1;i<=(-1*a);i++)
                fout<<"EW";
            for(i=1;i<=b;i++)
                fout<<"SN";

        }
        else if(b==0 && a>0)
            for(i=1;i<=a;i++)
                fout<<"WE";

        else if(a<0 && b<0)
        {
            for(i=1;i<=(-1*a);i++)
                fout<<"EW";

            for(i=1;i<=(-1*b);i++)
                fout<<"NS";

        }
        else if(a==0 && b<0)
            for(i=1;i<=(-1*b);i++)
                fout<<"NS";
                else if(a<0 && b==0)
            for(i=1;i<=(-1*a);i++)
                fout<<"EW";

        else if(a>0 && b<0)
        {
            for(i=1;i<=a;i++)
                fout<<"WE";
            for(i=1;i<=(-1*b);i++)
                fout<<"NS";
        }

        fout<<"\n";

    }
    return 0;
}
