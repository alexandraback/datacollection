//
//  main.cpp
//  Osmos
//
//  Created by Akhil Verghese on 5/4/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[])
{
    
    int t,x=0,n,y,N[128],minsteps[100],q,smallest;
    bool flag;
    long long a;
    cin>>t;
    while(t--)
    {
        x++;
        y=0;
        cin>>a>>n;
        for(int i=0;i<n;i++)
            cin>>N[i];
        sort(N,N+n);
        q=0;
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(a>N[i])
                a+=N[i];
            else
            {
                flag=1;
                minsteps[q]=y+(n-i);
                q++;
                if(a==1)
                {
                    y++;
                    i++;
                }
                else
                {
                    while(a<=N[i])
                    {
                        a+=(a-1);
                        y++;
                    }
                }
                i--;
            }
        }
        if(flag==1)
        {
            smallest=y;
            for(int i=0;i<q;i++)
            {
                if(smallest>minsteps[i])
                    smallest=minsteps[i];
            }
            y=smallest;
        }
        else
            y=0;
        cout<<"Case #"<<x<<": "<<y<<endl;
        getchar();
    }
    
    return 0;
}