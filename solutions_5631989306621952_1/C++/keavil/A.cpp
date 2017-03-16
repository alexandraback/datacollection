#include<bits/stdc++.h>
using namespace std;
string x;
string now,ck;
int T;
int main()
{
    cin>>T;
    for(int data=1;data<=T;data++)
    {
        cin>>x;
        now="";
        for(int i=0;i<x.size();i++)
        {
            string tmp="";
            tmp+=x[i];
            ck=tmp+now;
            now+=x[i];
            if(ck>now)now=ck;
        }
        cout<<"Case #"<<data<<": "<<now<<endl;
    }
}
