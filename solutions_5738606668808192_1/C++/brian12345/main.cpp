#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
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
int findprime(long long a, int base)
{
    long long p=a/power(base,8);
    for (long long i=2;i<p;i++)
    {
        if (a%i==0)
        {
            return i;
        }
    }
    return 0;
}
long long baseconverter(int base,string str)
{
    long long total=0;
    for (int i=0;i<16;i++)
    {
        if (str[i]=='1')
        {
            total=total+power(base,15-i);
        }
    }
    return total;
}
string binaryadder(string a)
{
    for (int i=0;i<16;i++)
    {
        if (a[14-i]=='0')
        {
            a[14-i]='1';
            return a;
        }
        else if (a[14-i]=='1')
        {
            a[14-i]='0';
        }
    }
    return "0";
}

int main()
{
    ofstream fout;
    fout.open("answer");
    long long test=0, divisor[9]={0};
    string jamcoin="1000000000000001";
    int count=0;
    fout<<"Case #1: "<<endl;
    while (jamcoin!="0" && count<500)
    {
        for (int i=2;i<=10;i++)
        {
            test=baseconverter(i,jamcoin);
            cout<<test<<endl;
            divisor[i-2]=findprime(test,i);
            if (divisor[i-2]==0)
            {
                test=-1;
                i=11;
            }
        }
        if (test!=-1)
        {
            fout<<jamcoin<<jamcoin<<" ";
            for (int i=0;i<9;i++)
            {
                fout<<divisor[i]<<' ';
            }
            fout<<endl;
            count++;
        }
        jamcoin=binaryadder(jamcoin);
    }
}
