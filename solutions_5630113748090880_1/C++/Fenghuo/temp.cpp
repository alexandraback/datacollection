#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;

bool bigger(string s1, string s2)
{
    return s1>=s2;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,t,tt;
    long long i,j,k;


    int cnt[2501];
    int a,b,c;
    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        cout<<"Case #"<<tt<<":";
        memset(cnt,0,sizeof(cnt));
        set<int> myset;
        set<int>::iterator it;

        cin>>a;
        c=2*a-1;
        while(c--)
        {
            for(i=0;i<a;i++)
            {
                cin>>b;
                cnt[b]++;
            }
        }

        for (i=0;i<2501;i++)
        {
            if (cnt[i]%2!=0)
            {
                myset.insert(i);
            }
        }
        for (it=myset.begin(); it!=myset.end(); ++it)
            cout <<" "<< *it;

        cout<<endl;

    }

    return 0;
}


