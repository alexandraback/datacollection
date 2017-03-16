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

int mat[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("p3.out","w",stdout);
    long long int T,L,X;
    string s;
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        cin>>L>>X>>s;
        int P=1,sgnP=1,sp1=-1,sp2=-1,ans=0;
        for(int i=0;i<X;i++)
        {
            for(int j=0;j<s.length();j++)
            {
                int v=s[j]-'g';
                //cout<<v<<endl;
                //cout<<P<<" "<<v<<" "<<sgnP*mat[P][v]<<endl;
                P=mat[P][v];
                
                if(P<0){P=-P;sgnP=-sgnP;}
                if(sgnP*P==2&&sp1==-1){sp1=L*i+j;P=sgnP=1;}
                if(sgnP*P==3&&sp1!=-1&&sp2==-1){sp2=L*i+j;P=sgnP=1;}
                //cout<<sgnP<<" "<<P<<endl;
            }
        }
        if(sgnP*P==4&&sp1!=-1&&sp2!=-1)ans=1;
        cout<<"Case #"<<kase<<": "<<(ans ? "YES" : "NO")<<endl;
    }
}