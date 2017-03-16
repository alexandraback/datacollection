#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("input.txt");
    outfile.open("output.txt");
    int T;
    //cin>>T;
    infile>>T;
    for (int i=1 ; i<=T ; i++)
    {
        long long K,C,S;
        //cin>>K>>C>>S;
        infile>>K>>C>>S;
        long long X=K/2;
        if(K%2==1)
            X+=1;
        if(C==1 && S<K)
        {
            //cout<<"Case #"<<i<<": "<<"IMPOSSIBLE\n";
            outfile<<"Case #"<<i<<": "<<"IMPOSSIBLE\n";
            continue;
        }
        if(C!=1 && S<X)
        {
            //cout<<"Case #"<<i<<": "<<"IMPOSSIBLE\n";
            outfile<<"Case #"<<i<<": "<<"IMPOSSIBLE\n";
            continue;
        }
        if(C==1)
        {
            //cout<<"Case #"<<i<<": ";
            outfile<<"Case #"<<i<<": ";
            for (int j=1 ; j<=K ; j++)
            {
                //cout<<j<<" ";
                outfile<<j<<" ";
            }
            //cout<<"\n";
            outfile<<"\n";
            continue;
        }
        int B=0;
        //cout<<"Case #"<<i<<": ";
        outfile<<"Case #"<<i<<": ";
        for (int j=K ; j>X ; j--)
        {
            //cout<<B+j<<" ";
            outfile<<B+j<<" ";
            B=B+K;
        }
        if(K%2==1)
        {
            //cout<<K/2+1<<" ";
            outfile<<K/2+1<<" ";
        }
        //cout<<"\n";
        outfile<<"\n";
    }
}
