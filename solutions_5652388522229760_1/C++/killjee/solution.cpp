#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
    std:ios::sync_with_stdio(false);
    ifstream infile;
    infile.open("input.txt");
    ofstream oufile;
    oufile.open("output.txt");
    long long T;
    //cin>>T;
    infile>>T;
    for (long long i=1 ; i<=T ; i++)
    {
        long long N;
        //cin>>N;
        //N=3500000+i*3;
        infile>>N;
        //cout<<i<<" "<<N<<endl;
        if(N==0)
        {
            //cout<<"Case #"<<i<<": "<<"INSOMNIA\n";
            oufile<<"Case #"<<i<<": "<<"INSOMNIA\n";
            continue;
        }
        long long Memo[10]={0},j=1;
        while(1)
        {
            long long A=N*j,ch=0;
            while (A!=0)
            {
                long long c=A%10;
                Memo[c]=1;
                A=A/10;
            }
            for (long long k=0 ; k<10 ; k++)
            {
                if(Memo[k]==0)
                {
                    ch=1;
                    break;
                }
            }
            if(ch==0)
                break;
            j++;
        }
        //cout<<"Case #"<<i<<": "<<" "<<j*N<<endl;
        oufile<<"Case #"<<i<<": "<<j*N<<endl;
    }
}
