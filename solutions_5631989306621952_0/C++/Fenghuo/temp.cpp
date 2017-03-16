#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool bigger(string s1, string s2)
{
    return s1>=s2;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,t,tt;
    long long i,j,k;


    string s,ss;
    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        cin>>s;
        ss.clear();
        string s1;
        string s2;
        for (i=0;i<s.size();i++)
        {
            s1=ss;
            s1+=s[i];

            s2=s[i];
            s2+=ss;

            if (s1>=s2) ss=s1;
            else ss=s2;
        }


        cout<<"Case #"<<tt<<": "<<ss<<endl;

    }

    return 0;
}


