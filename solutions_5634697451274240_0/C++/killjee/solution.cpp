#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    std:ios::sync_with_stdio(false);
    ifstream infile;
    ofstream oufile;
    infile.open("input.txt");
    oufile.open("output.txt");
    int T;
    //cin>>T;
    infile>>T;
    for (int i=1 ; i<=T ; i++)
    {
        string S;
        //cin>>S;
        infile>>S;
        int Ans=0;
        bool X=0;
        for (int j=S.size()-1 ; j>=0 ; j--)
        {
            char c=S[j];
            if(X==1)
            {
                if(c=='+')
                    c='-';
                else
                    c='+';
            }
            if(c=='-')
            {
                Ans+=1;
                if(X==0)
                    X=1;
                else
                    X=0;
            }
        }
        //cout<<"Case #"<<i<<": "<<Ans<<endl;
        oufile<<"Case #"<<i<<": "<<Ans<<endl;
    }
}
