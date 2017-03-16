#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s;
    int T;
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        cin>>s;
        string u="";
        for(int i=0;i<s.length();i++)
        {
            u=max(s[i]+u,u+s[i]);
        }

        cout<<"Case #"<<tt<<": "<<u<<endl;
    }
}
