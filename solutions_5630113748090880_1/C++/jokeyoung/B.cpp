#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>

using namespace std;



int main()
{     
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out","w",stdout);
    
    int count[2501];
    
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        cin>>n;
        
        for(int i=0;i<2501;i++)
            count[i]=0;
        
        for(int i=0;i<n*(2*n-1);i++)
        {
            int temp;
            cin>>temp;
            
            count[temp]++;    
                
        }//
        
        cout<<"Case #"<<cas<<":";
        
        for(int i=1;i<=2500;i++)
            if(count[i]%2==1)
                cout<<" "<<i;
        
        cout<<endl;
            
        //printf("Case #%d: %d\n",cas,ans);      
        //cout<<"Case #"<<cas<<": "<<s<<endl;
          
    }//
    
  //system("pause");
}
