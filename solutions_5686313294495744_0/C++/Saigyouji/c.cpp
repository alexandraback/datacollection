#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int tc,tci=0;
    cin>>tc;
    while(tc--)
    {
        tci++;
        vector<string> s1;
        vector<string> s2;
        int i,n,s=0;
        cin>>n;
        map<string,int> mp1;
        map<string,int> mp2;
        for(i=0;i<n;i++)
        {
            string a,b;
            cin>>a>>b;
            s1.push_back(a);
            s2.push_back(b);
            mp1[a]++;
            mp2[b]++;
        }
        for(i=0;i<n;i++)
        {
            if(mp1[s1[i]]-1>0&&mp2[s2[i]]-1>0)s++;
        }
        cout<<"Case #"<<tci<<": "<<s<<endl;
    }
    return 0;
}
