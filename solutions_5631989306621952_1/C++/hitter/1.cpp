#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(long i=1;i<=t;i++)
    {
        string a;
        cin>>a;
        char temp;
        for(int j=1;a[j]!='\0';j++)
        {
            if(a[j]>=a[0])
            {
                temp=a[j];
                for(int k=j-1;k>=0;k--)
                a[k+1]=a[k];
                a[0]=temp;
            }
        }
        cout<<"Case #"<<i<<": "<<a<<endl;
    }
    return 0;
}
    
    
 