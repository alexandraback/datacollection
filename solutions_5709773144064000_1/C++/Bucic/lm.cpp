#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,l,a[100][100],b[100][100],t;
double c,f,x,rj,tmp;
int main()
{
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    fin>>t;
    for (int o=0; o<t; o++)
    {
        fin>>c>>f>>x;
        rj=0;
        tmp=x/c-2/f-2;

        k=ceil(tmp);
        if (k<-1) k=-1;

        for (int i=0; i<=k; i++)
            rj+=1/(2+i*f);
        rj=rj*c;

        rj+=x/(2+(k+1)*f);
        fout<<"Case #"<<o+1<<": "<<fixed<<setprecision(7)<<rj<<endl;

    }
    return 0;
}
