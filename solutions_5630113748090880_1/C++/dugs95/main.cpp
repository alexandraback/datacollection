//
//  main.cpp
//  hfjkdafb
//
//  Created by divya gupta on 16/04/16.
//  Copyright (c) 2016 divya gupta. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int mark[2505];
int main() {
    // your code goes here
    int t,x,i,j,a;
    x=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=0;i<=2500;i++)
        {
            mark[i]=0;
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<(2*n-1);j++)
            {
                cin>>a;
                mark[a]++;
            }
        }
        vector<int> ans;
        
        for(i=0;i<=2500;i++)
        {
            if(mark[i]%2)
            {
                ans.push_back(i);
            }
        }
        
        sort(ans.begin(),ans.end());
        cout<<"Case #"<<x<<": ";
        for(i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
        
        
    }
    return 0;
}