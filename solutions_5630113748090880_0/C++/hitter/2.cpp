#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int main()
{
    int t;
    cin>>t;
    for(long i=1;i<=t;i++)
    {
        int n;
        int a[2600]={0};
        cin>>n;
        int m=2*n-1;
        while(m--)
        {
            int temp;
            for(int j=0;j<n;j++)
            {
                cin>>temp;
                a[temp]++;
            }
        }
        cout<<"Case #"<<i<<": ";
        for(int j=1;j<2600;j++)
        {
            if(a[j]!=0 && a[j]%2!=0)
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
    
    
 