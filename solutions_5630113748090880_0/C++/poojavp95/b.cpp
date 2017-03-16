#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
    int n,x;
    cin>>n;
    map<int, int > m;
    for(int j=0;j< 2*n -1; j++)
    {
        for(int k=0;k<n;k++)
        {
        cin>>x;
        m[x]++;
        }
    }
    cout<<"Case #"<<i<<": ";
    map<int ,int >:: iterator it;
    for(it=m.begin();it!=m.end();++it)
    {
        if(it->second % 2 !=0)
        {
            cout<< it->first <<" ";
        }
    }
    cout<<endl;
}
}
