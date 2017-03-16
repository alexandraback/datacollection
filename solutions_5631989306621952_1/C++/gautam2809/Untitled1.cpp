#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("A-large.in","r",stdin);
    freopen("output_large.txt","w",stdout);
    int t;
    int k=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        deque<char> a;
        a.push_back(s[0]);
        for(int i=1;s[i]!='\0';i++)
        {
            if(a.front()>s[i])
                a.push_back(s[i]);
            else
                a.push_front(s[i]);
        }
        cout<<"Case #"<<k<<": ";
        for(int i=0;i<a.size();i++)
            cout<<a[i];
        cout<<endl;
        k++;
    }
}
