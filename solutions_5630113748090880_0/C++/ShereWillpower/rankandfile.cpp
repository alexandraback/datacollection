#include<bits/stdc++.h>
using namespace std;

int main()
 {
     freopen("B-small-attempt0.in","r",stdin);
     freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    int p;
    for(p=1;p<=t;p++)
     {
        int n;
        cin>>n;

        int i,j,k;
        int arr[2501]={0};
        for(i=0;i<=(2*n)-2;i++)
         {
            for(j=0;j<n;j++)
                {
                   cin>>k;
                   arr[k]++;
                 }

         }
         cout<<"Case #"<<p<<": ";
         for(j=0;j<2501;j++)
           {
              if(arr[j]%2==1)
                cout<<j<<" ";
           }
           cout<<endl;
     }
 }

