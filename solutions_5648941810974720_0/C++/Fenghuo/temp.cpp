#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,t,tt;
    long long i,j,k;

    long long myresult=1;
    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        multiset<int> ms;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        string s;
        cin>>s;
        for (i=0;i<s.size();i++)
        {
            cnt[s[i]-'A']++;
        }

        i=cnt['X'-'A'];
        while(i)
        {
            i--;
            ms.insert(6);
            cnt['S'-'A']--;
            cnt['I'-'A']--;
            cnt['X'-'A']--;
        }

        i=cnt['W'-'A'];
        while(i)
        {
            i--;
            ms.insert(2);
            cnt['T'-'A']--;
            cnt['W'-'A']--;
            cnt['O'-'A']--;
        }

        i=cnt['S'-'A'];
        while(i)
        {
            i--;
            ms.insert(7);
            cnt['S'-'A']--;
            cnt['E'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
            cnt['N'-'A']--;
        }

        i=cnt['V'-'A'];
        while(i)
        {
            i--;
            ms.insert(5);
            cnt['F'-'A']--;
            cnt['I'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
        }

        i=cnt['Z'-'A'];
        while(i)
        {
            i--;
            ms.insert(0);
            cnt['Z'-'A']--;
            cnt['E'-'A']--;
            cnt['R'-'A']--;
            cnt['O'-'A']--;
        }

        i=cnt['U'-'A'];
        while(i)
        {
            i--;
            ms.insert(4);
            cnt['F'-'A']--;
            cnt['O'-'A']--;
            cnt['U'-'A']--;
            cnt['R'-'A']--;
        }

        i=cnt['O'-'A'];
        while(i)
        {
            i--;
            ms.insert(1);
            cnt['O'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
        }

        i=cnt['G'-'A'];
        while(i)
        {
            i--;
            ms.insert(8);
            cnt['E'-'A']--;
            cnt['I'-'A']--;
            cnt['G'-'A']--;
            cnt['H'-'A']--;
            cnt['T'-'A']--;
        }

        i=cnt['R'-'A'];
        while(i)
        {
            i--;
            ms.insert(3);
            cnt['T'-'A']--;
            cnt['H'-'A']--;
            cnt['R'-'A']--;
            cnt['E'-'A']--;
            cnt['E'-'A']--;
        }

        i=cnt['N'-'A']/2;
        while(i)
        {
            i--;
            ms.insert(9);
            cnt['N'-'A']--;
            cnt['I'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
        }

        cout<<"Case #"<<tt<<": ";

        multiset<int>::iterator it;
        for (it=ms.begin(); it!=ms.end(); ++it)
        cout<<*it;

        //for (i=0;i<26;i++) cout<<i<<":"<<cnt[i]<<endl;

        cout<<endl;
    }

    return 0;
}


