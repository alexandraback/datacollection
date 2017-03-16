#include "stdafx.h"

#include<iostream>

#include<cstring>
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string s[4],t1;
    ifstream Fp;
    ofstream fout;
    Fp.open("input.txt");
    fout.open("output.txt");
    long t,i,j,Flg=0,n,ans=0,I,tmp1=0,tmp2=0;
    Fp>>t;
    getline(Fp,s[0]);
    for(I=0;I<t;I++)
    {
        tmp2=0;
        tmp1=0;
        ans=0;
        getline(Fp,t1,' ');
        Fp>>n;
        getline(Fp,s[0]);
        for(i=0;i<t1.length()-n+1;i++)
        {
            Flg=0;
            if(t1[i]=='a' || t1[i]=='e' || t1[i]=='i' || t1[i]=='o' ||t1[i]=='u' )
                continue;
            else
            {
                tmp1=i;
                for(j=i+1;j<i+n;j++)
                {
                   if(t1[j]=='a' || t1[j]=='e' || t1[j]=='i' || t1[j]=='o' ||t1[j]=='u' )
                   {
                       Flg=1;
                       i=j;
                       break;
                   }
                }
                if(Flg==0)
                {

                   ans+=((tmp1-tmp2)+1)*(t1.length()-j+1);
                   tmp2=tmp1+1;
                }
            }


        }
        fout<<"Case #"<<I+1<<": "<<ans<<endl;
    }
    fout.close();

}
