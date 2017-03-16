#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int te;
    cin>>te;
    for(int t=1;t<=te;t++)
    {
        string s;
        cin>>s;
        string resp;
        string temp;
        int maxim=0;
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'A'>=start)
            {
                temp=s[i];
                temp+=resp;
                resp=temp;
                start=s[i]-'A';
            }
            else
            {
                resp+=s[i];
            }
        }
        cout<<"Case #"<<t<<": "<<resp<<endl;
    }
    return 0;
}
