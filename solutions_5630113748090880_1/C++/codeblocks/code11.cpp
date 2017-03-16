#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int k=0;
    while(t--)
    {
        k++;
        int n;
        cin>>n;
        int height;
        map<int,int> freq;
        for(int i=0;i<(2*n)-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>height;
                freq[height]++;

            }
        }
        vector<int> v;
     for(map<int,int> ::iterator it=freq.begin();it!=freq.end();it++)
     {
         if((it->second)%2!=0)
         {
             v.push_back(it->first);
         }
     }

sort(v.begin(),v.end());
cout<<"Case #"<<k<<": ";
for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
cout<<"\n";
    }
}
