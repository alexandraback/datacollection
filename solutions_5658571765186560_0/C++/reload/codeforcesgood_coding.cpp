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
long long int x,t,r,c;
int main(int argc, char const *argv[])
{
        cin.sync_with_stdio(0);
        long long int X[5][5][5];

        for (int i = 0; i <5; ++i)
        {
            for (int j = 0; j <5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    X[i][j][k]=0;
                }
            }
        }

        X[3][2][3]=1;
        X[3][3][2]=1;
        X[3][3][3]=1;
        X[3][3][4]=1;
        X[3][4][3]=1;

        
        X[4][4][3]=1;
        X[4][3][4]=1;
        X[4][4][4]=1;
        cin>>t;
        for (int i = 0; i < t; ++i)
        {
            cin>>x>>r>>c;
            if(x==1)
            {
                cout<<"Case #"<<i+1<<": "<<"GABRIEL"<<endl;
            }
            else if (x==2)
            {
                 if(r*c % 2==0)
                     cout<<"Case #"<<i+1<<": "<<"GABRIEL"<<endl;
                else
                    cout<<"Case #"<<i+1<<": "<<"RICHARD"<<endl;
            }
            else
            {
                if (r*c % x==0)
                {
                    if (X[x][r][c]==1)
                    {
                        cout<<"Case #"<<i+1<<": "<<"GABRIEL"<<endl;
                    }
                    else
                    {
                        cout<<"Case #"<<i+1<<": "<<"RICHARD"<<endl;
                    }
                }
                else
                {
                    cout<<"Case #"<<i+1<<": "<<"RICHARD"<<endl;
                }
            }
        }

}
  


