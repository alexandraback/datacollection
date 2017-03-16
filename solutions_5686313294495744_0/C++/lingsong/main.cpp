//
//
//  noob
//
//  Created by Lingsong Zeng on 2/29/16.
//  Copyright © 2016 Lingsong Zeng. All rights reserved.
//



#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
set<string>f,s;
string a[20][2];
int main()
{
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                cin>>a[i][j];
        int ans=n;
        for(int i=0;i<(1<<n);i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
                if((1<<j)&i)
                    cnt++;
            if(cnt>=ans)
                continue;
            bool flag=true;
            f.clear();
            s.clear();
            for(int j=0;j<n;j++)
            if((1<<j)&i)
            {
                f.insert(a[j][0]);
                s.insert(a[j][1]);
            }
            for(int j=0;j<n;j++)
            if(((1<<j)&i)==0)
            {
                if(f.find(a[j][0])==f.end()||s.find(a[j][1])==s.end())
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)continue;
            ans=cnt;
        }
        printf("%d\n",n-ans);
    }
}