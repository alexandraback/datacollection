#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,t,tt;
    int i,j,k;



    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        string s;
        cin>>s;
        char last=s[0];
        int cnt=1;

        for (i=1;i<s.size();i++)
        {
            if (s[i]==last) continue;
            last=s[i];
            cnt++;
        }

        if (s[i-1]=='+') cnt--;


        cout<<"Case #"<<tt<<": "<<cnt<<endl;
    }

    return 0;
}


