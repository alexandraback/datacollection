#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("A-small-attempt0.in");
    if (!fin.is_open())
    {
        cout<<"error!"<<endl;
        return -1;
    }
    ofstream fout;
    fout.open("answer");
    int cases=0, number=0, total=0, lastnumber=0;
    int digits[10]={0};
    int temp=0,lasttemp=0;
    fin>>cases;
    fin.get();
    for (int i=0;i<cases;i++)
    {
        fin>>number;
        fin.get();
        int digits[10]={0};
        total=0;
        if (number==0)
        {
            lastnumber=0;
        }
        else
        {
            int count=2;
            while (total<10)
            {
                int devider=10;
                lasttemp=number;
                while (number>=devider/10)
                {
                    temp=lasttemp/devider;
                    temp*=devider;
                    digits[(lasttemp-temp)/(devider/10)]=1;
                    cout<<(lasttemp-temp)/(devider/10)<<endl;
                    lasttemp=temp;
                    devider*=10;
                }
                total=0;
                for (int j=0;j<10;j++)
                {
                    total+=digits[j];
                }
                lastnumber=number;
                number=number/(count-1)*count;
                count++;
                cout<<"total: "<<total<<endl;
            }
        }
        if (lastnumber!=0)
        {
            fout<<"Case #"<<i+1<<": "<<lastnumber<<endl;
        }
        else if (lastnumber==0)
        {
            fout<<"Case #"<<i+1<<": INSOMNIA"<<endl;
        }
    }
}
