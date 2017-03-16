#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,b,n;
string s;
int main()
{
    cin>>t;
    for(int ij=1;ij<=t;ij++)
    {
        cin>>n;
        vector<vector<int> > V(2*n-1,vector<int>(n));
        vector<bool> parita(2505,true);
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>V[i][j];
                if(parita[V[i][j]])parita[V[i][j]]=false;
                else parita[V[i][j]]=true;
            }
        }
        cout <<"Case #"<<ij<<":";
        for(int i=0;i<parita.size();i++)
        {
            if(!parita[i])cout <<" "<<i;
        }
        cout <<endl;
    }
    return 0;
}
