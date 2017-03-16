#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,itr=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> ans;
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a;
                cin>>a;
                ans[a]++;
            }

        }
        map<int,int>::iterator it=ans.begin();
        vector<int> ans1;
        while(it!=ans.end()){
            if(it->second%2==1)
            ans1.push_back(it->first);
        it++;}

        cout<<"Case #"<<itr++<<": ";

        for(int i=0;i<n;i++)
        cout<<ans1[i]<<" ";
        cout<<endl;


    }

return 0;}
