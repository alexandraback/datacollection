#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    std:ios::sync_with_stdio(false);
    //input.tie();
    //output.tie();
    ifstream input;
    input.open("inp.txt");
    ofstream output;
    output.open("out.txt");
    int T;
    input>>T;
    for (int i=0 ; i<T ; i++)
    {
        output<<"Case #"<<i+1<<": ";
        string s,b;
        input>>s;
        int A[26]={0};
        int B[10]={0};
        for (int j=0 ; j<s.size() ; j++)
        {
            A[s[j]-'A']+=1;
        }
        /*for(int j=0 ; j<26 ; j++)
        {
            char c=j+'A';
            cout<<c<<" "<<A[j]<<endl;
        }*/
        b="ZERO";
        B[0]=A['Z'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[0];
        }
        b="EIGHT";
        B[8]=A['G'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[8];
        }
        b="THREE";
        B[3]=A['H'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[3];
        }
        B[4]=A['R'-'A'];
        b="FOUR";
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[4];
        }
        b="SIX";
        B[6]=A['X'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[6];
        }
        b="SEVEN";
        B[7]=A['S'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[7];
        }
        b="FIVE";
        B[5]=A['V'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[5];
        }
        B[2]=A['T'-'A'];
        b="TWO";
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[2];
        }
        b="ONE";
        B[1]=A['O'-'A'];
        for (int j=0 ; j<b.size() ; j++)
        {
            A[b[j]-'A']-=B[1];
        }
        B[9]=A['N'-'A']/2;
        for (int j=0 ; j<=9 ; j++)
        {
            //cout<<B[j]<<endl;
            for (int k=0 ; k<B[j] ; k++)
            {
                output<<j;
            }
        }
        output<<endl;
    }
}
