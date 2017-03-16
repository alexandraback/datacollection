#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{


    int t,ti;
    cin>>t;
    ti=t;

    for(; t>0; t--)
    {
        int n,a;
        vector<int> p(2600,0),v;
        cin>>n;


        for(int i=0;i<(2*n-1)*n;i++)
        {
        cin>>a;
        p[a]++;
        }

        for(int i=0;i<p.size();i++)
        {
        if(p[i]%2==1)
        {
        v.push_back(i);
        }
        }


        cout<<"Case #"<<(ti-t+1)<<": ";

        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
