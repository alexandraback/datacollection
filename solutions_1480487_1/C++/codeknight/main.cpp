//
//  main.cpp
//  codejam20121B
//
//  Created by 李嘉俊 on 12-5-5.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
double data[300];
bool t[300];
int main ()
{
    freopen("/Users/leonroxas/Desktop/codejam20121B/codejam20121B/data.in", "r", stdin);
    freopen("/Users/leonroxas/Desktop/codejam20121B/codejam20121B/data.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int _t=1; _t<=T; _t++) {
        memset(t, 0, sizeof(t));
        printf("Case #%d:",_t);
        int n;
        scanf("%d",&n);
        double sum=0,temp,ans;
        for (int i=0;i<n; i++) {
            scanf("%lf",&data[i]);
            sum+=data[i];
        }
        int x=0;
        double s=0;
        temp = sum*2.00/(double)n;
        bool end = true;
        while (end) {
            end=false;
        for (int i=0;i<n; i++) {
            if(temp-data[i]<0 && t[i]!=1)
            {
                end=true;
                x+=1;
                t[i]=1;
            }
        }
            temp=sum*2.00;
            for(int i=0;i<n;i++)
                if(t[i])
                    temp-=data[i];
            temp/=(n-x);
        }
        for (int i=0;i<n; i++) {
            if(!t[i]){
            data[i]=temp-data[i];
            ans=data[i]/sum*100.00;
            }
            else
                ans=0;
            s+=ans;
            printf(" %.6lf",ans);
           
                
        }
        cout<<endl;
    }
    
    return 0;
}

