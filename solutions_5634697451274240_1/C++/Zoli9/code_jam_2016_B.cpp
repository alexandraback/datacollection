#include <bits/stdc++.h>
using namespace std;
int test;
string s;
int main()
{
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s;
        int db=0;
        for(int i=0; i<s.size()-1; i++) if(s[i]!=s[i+1]) db++;
        if((db%2==0 && s[0]=='+') || (db%2==1 && s[0]=='-')) cout<<"Case #"<<tt<<": "<<db<<endl;
        else cout<<"Case #"<<tt<<": "<<db+1<<endl;
    }
    return 0;
}
