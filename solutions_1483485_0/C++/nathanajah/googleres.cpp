#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,i;
string s;
int tmp;
char arr[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
string conv(string x)
{
    int i;
    string ret;
    for (i=0;i<x.length();++i)
    {
        if (x[i]>='a' && x[i]<='z')
        {
            x[i]=arr[x[i]-'a'];
        }
        ret.append(1,x[i]);
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    getline(cin,s);
    for (i=0;i<n;++i)
    {
        getline(cin,s);
        printf("Case #%d: ",i+1);
        cout << conv(s) << "\n";
    }
}
