#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int te;
    cin>>te;
    int ocor[2505];
    for(int t=1;t<=te;t++)
    {
        for(int i=0;i<2505;i++) ocor[i]=0;
        int n;
        cin>>n;
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a;
                cin>>a;
                ocor[a]++;
            }
        }
        vector<int> resp;
        for(int i=0;i<2505;i++)
        {
            if(ocor[i]&1)
            {
                resp.push_back(i);
            }
        }
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<resp.size();i++)
        {
            cout<<resp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
