#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("B-large.in","r",stdin);
    freopen("output_large.txt","w",stdout);
    int t;
    int k=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int temp[2505]={0};
        int x=(2*n-1)*n,y;
        for(int i=0;i<x;i++)
        {
            cin>>y;
            temp[y]++;
        }
        cout<<"Case #"<<k<<": ";
        for(int i=0;i<2505;i++)
        {
            if(temp[i]%2!=0)
                cout<<i<<" ";
        }
        cout<<endl;
        k++;
    }
}
