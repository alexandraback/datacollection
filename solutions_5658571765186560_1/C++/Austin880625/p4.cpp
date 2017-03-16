//
//  p1.cpp
//  
//
//  Created by Mac on 4/3/15.
//
//

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("p4l.out","w",stdout);
    int T;
    cin>>T;
    int X,R,C;
    
    for(int kase=1;kase<=T;kase++)
    {
        int ans=0;
        cin>>X>>R>>C;
        if(R*C%X)ans=0;
        else if(X==1)ans=1;
        else if(X==2)ans=1;
        else if(X==3)
        {
            if(R>=2&&C>=2)ans=1;
        }
        else if(X==4)
        {
            if(R>2&&C>2)ans=1;
        }
        else if(X==5)
        {
            if(R>C)swap(R,C);
            if(R<=2)ans=0;
            if(R==3)ans=(C>=10 ? 1 : 0);
            if(R>=4)ans=1;
        }
        else if(X==6)
        {
            if(R>C)swap(R,C);
            if(R<=3)ans=0;
            if(R==4)ans=(C>=6 ? 1 : 0);
            if(R>=5)ans=1;
        }
        else if(X>=7)ans=0;
        cout<<"Case #"<<kase<<": "<<(ans ? "GABRIEL" : "RICHARD")<<endl;
    }
}