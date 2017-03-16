#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007
long long int gcd(long long int a,long long int b){
      if(b==0)return a;
      return gcd(b,a%b);
}
char str[1000000];
long long int mat[5][5];
long long int convert[256],t,fans,ans,mul,X;
int main(int argc, char const *argv[])
{
        cin.sync_with_stdio(0);
        cin>>t;
        long long int l,x; 
        for (int i = 1; i <=4 ; ++i)
        {
            mat[1][i]=i;
            mat[i][1]=i;
            mat[i][i]=-1;
        }
        mat[1][1]=0;
        mat[2][3]=4;
        mat[2][4]=-3;
        mat[3][2]=-4;
        mat[3][4]=2;
        mat[4][2]=3;
        mat[4][3]=-2;
        
        convert['i']=2;
        convert['j']=3;
        convert['k']=4;

        for (int i = 0; i < t; ++i)
        {

            long long int indexi=-1,indexk=-1;
            cin>>l>>X;;
            cin>>str;

            if( X<=8){

            int len=strlen(str);
            
            long long int z=X*l;
            
            for (int j = len; j < z; ++j)
            {
                str[j] = str[j-l]; 
            }
            ans=1;
            mul=1;
            for (int j= 0; j< z ; ++j)
            {
                x=convert[str[j]];               
                ans = mat[abs(ans)][x];
                ans=ans*mul;
                if(ans>0)mul=1;
                else mul=-1;

                if(ans==2 && indexi==-1)
                {
                    indexi=j;
                }

            }

            ans=1;
            mul=1;
            for (int j = z-1; j>=0; j--)
            {
                x=convert[str[j]];               
                ans = mat[x][abs(ans)];
                ans=ans*mul;
                if(ans>0)mul=1;
                else mul=-1;
                if(ans==4 && indexk==-1)
                {
                    indexk=j;
                }
            }
            if(ans!=-1)
            {
                cout<<"Case #"<<i+1<<": NO"<<endl;
                continue;
            }
            if(indexk==-1 || indexi==-1)
            {
                cout<<"Case #"<<i+1<<": NO"<<endl;
            }
            else
            {
                if(indexi + 1 < indexk )
                {
                     cout<<"Case #"<<i+1<<": YES"<<endl;
                }
                else
                {
                     cout<<"Case #"<<i+1<<": NO"<<endl;
                }
            }
        }
        else
        {

            long long int z=4*l;
            int len=strlen(str);

            for (int j = len; j < z; ++j)
            {
                str[j] = str[j-l]; 
            }
            ans=1;
            mul=1;
            for (int j= 0; j< z ; ++j)
            {
                x=convert[str[j]];               
                ans = mat[abs(ans)][x];
                ans=ans*mul;
                if(ans>0)mul=1;
                else mul=-1;

                if(ans==2 && indexi==-1)
                {
                    indexi=j;
                }
            }
            ans=1;
            mul=1;
            for (int j = z-1; j>=0; j--)
            {
                x=convert[str[j]];               
                ans = mat[x][abs(ans)];
                ans=ans*mul;
                if(ans>0)mul=1;
                else mul=-1;
                if(ans==4 && indexk==-1)
                {
                    indexk=j;
                }
            }
            z=(X%4)*l;
            ans=1;
            mul=1;
            for (int j= 0; j< z ; ++j)
            {
                x=convert[str[j]];               
                ans = mat[abs(ans)][x];
                ans=ans*mul;
                if(ans>0)mul=1;
                else mul=-1;

                if(ans==2 && indexi==-1)
                {
                    indexi=j;
                }
            }
            if(ans!=-1 || X%4==0)
            {
                cout<<"Case #"<<i+1<<": NO"<<endl;
                continue;
            }
            if(indexk==-1 || indexi==-1)
            {
                cout<<"Case #"<<i+1<<": NO"<<endl;
            }
            else
            {
                cout<<"Case #"<<i+1<<": YES"<<endl;
            }
        }
    }
}