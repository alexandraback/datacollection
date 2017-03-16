#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <set>
using namespace std;

int main()
{
    freopen("testA.in","r",stdin);
    freopen("testA.out","w",stdout);
    string e[3], r[3];
    e[0]="our language is impossible to understand";
    e[1]="there are twenty six factorial possibilities";
    e[2]="so it is okay if you want to just give up";
    r[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
    r[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    r[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
    char mapa[26];

    for(int i=0; i<3; i++)
    for(int j=0; j<e[i].size(); j++)
    if(e[i][j]!=' ')
    mapa[r[i][j]-'a']=e[i][j];

    mapa['z'-'a']='q';
    mapa['q'-'a']='z';

    int T;
    cin >> T;
    char basura[10];
    cin.getline(basura,10);
    for(int i=1; i<=T; i++)
    {
        char word[101];
        cin.getline(word,101);
        int s=0;
        string k;
        for(int j=0; j<sizeof(word); j++)
        if(word[j]>='a' && word[j]<='z')
        s=j;

        for(int j=0; j<strlen(word); j++)
        if(word[j]!=' ')
        {
            k+=mapa[word[j]-'a'];
        }
        else
        {
            k+=' ';
        }
        cout << "Case #" << i << ": " << k << endl;
    }

}
