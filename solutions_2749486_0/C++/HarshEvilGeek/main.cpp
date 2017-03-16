//
//  main.cpp
//  Pogo
//
//  Created by Akhil Verghese on 5/12/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int t,q=0,x,y;
    char ans[500];
    cin>>t;
    while(t--)
    {
        for(int i=0;i<500;i++)
            ans[i]=0;
        q++;
        cin>>x>>y;
        int i,d=0;
        if(x>0)
        {
            i=0;
            while(i<x)
            {
                ans[2*d]='W';
                ans[2*d+1]='E';
                i++;
                d++;
            }
        }
        if(x<0)
        {
            i=0;
            while(i>x)
            {
                ans[2*d]='E';
                ans[2*d+1]='W';
                i--;
                d++;
            }
        }
        if(y>0)
        {
            i=0;
            while(i<y)
            {
                ans[2*d]='S';
                ans[2*d+1]='N';
                i++;
                d++;
            }
        }
        if(y<0)
        {
            i=0;
            while(i>y)
            {
                ans[2*d]='N';
                ans[2*d+1]='S';
                i--;
                d++;
            }
        }
        cout<<"Case #"<<q<<": ";
        int j=0;
        while(ans[j]!=0)
        {
            cout<<ans[j];
            j++;
        }
        cout<<endl;
        getchar();
    }
    return 0;
}

