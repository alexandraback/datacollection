//
//  main.cpp
//  A
//
//  Created by 黄宇凡 on 16/4/9.
//  Copyright © 2016年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

using namespace std;
int vis[10];
long long n,k,i,j,l,x,y;
bool check( )
{
    bool flag=true;
    for(int i = 0;i <= 9;i++)
    {
        if (vis[i]==0) {flag=false; break;}
    }
    return flag;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("large.out","w",stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++){
        cin >> x;
        if(x == 0){
            printf("Case #%d: ",i);
            cout << "INSOMNIA"<<endl;
        }
        else{
            memset(vis,0,sizeof(vis));
            long long t=1;
            n=x;
            while(n > 0){
                vis[n%10]=1;
                n=n/10;
            }
        
            while(!check())
            {
                t++;
                n=x*t;
                while(n > 0)
                {
                    vis[n%10]=1;
                    n=n/10;
                }
            }
            printf("Case #%d: ",i);
            cout << t * x << endl;
        }
    }
    return 0;
}

