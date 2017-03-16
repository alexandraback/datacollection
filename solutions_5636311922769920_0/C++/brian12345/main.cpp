#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

long long power(int base,int pow)
{
    long long result=1;
    for (int i=0;i<pow;i++)
    {
        result*=base;
    }
    return result;
}

int main()
{
    ifstream fin;
    fin.open("D-small-attempt0.in");
    if (!fin.is_open())
    {
        cout<<"error! "<<endl;
        return -1;
    }
    ofstream fout;
    fout.open("answer");
    long long K=0,C=0,S=0,cases=0;
    fin>>cases;
    fin.get();
    for (int i=0;i<cases;i++)
    {
        fout<<"Case #"<<i+1<<": ";
        int students=0;
        fin>>K;
        fin.get();
        fin>>C;
        fin.get();
        fin>>S;
        fin.get();
        students=(K-1)/C+1;
        long long pos=0;
        if (K-C<=0)
        {
            pos=1;
            for (int k=0;k<K;k++)
            {
                pos=pos+power(K,k)*(K-k-1);
            }
            fout<<pos<<' ';
        }
        else if(K-C>0)
        {
            if (students<=S)
            {
                for (int j=0;j<students-1;j++)
                {
                    pos=1;
                    for (int k=0;k<C;k++)
                    {
                        pos=pos+power(K,k)*(C-k-1+j*C);
                    }
                    fout<<pos<<' ';
                }
                pos=1;
                int parameter=K%C;
                if(parameter==0)
                {
                    parameter=C;
                }
                for (int j=0;j<parameter;j++)
                {
                    pos=pos+power(K,C-j-1)*((students-1)*C+j);
                }
                fout<<pos;
            }
            else if (students>S)
            {
                fout<<"IMPOSSIBLE";
            }
        }
        fout<<endl;
    }
}
