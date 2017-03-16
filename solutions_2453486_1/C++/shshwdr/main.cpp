#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include<cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <utility>
#include <fstream>
#define INF     9999999
using namespace std;

int main()
{
    int num;
    string a[4];
    ifstream cin("A-large.in");
    ofstream cout("out.out");
    cin>>num;
    for(int nn=1;nn<=num;nn++)
    {
        int f=0;
        int f1=0;

            for(int i=0;i<4;i++)
            {cin>>a[i];}
            cout<<"Case #"<<nn;
            for(int i=0;i<4;i++)
            {
                int ff=0;
            char t=a[i][0];


            if(t=='T'){
                       t=a[i][1];

                       }
            for(int j=1;j<4;j++)
            if(a[i][j]!=t&&a[i][j]!='T'){ff=1;break;}
            if(ff==0&&t!='.') {cout<<": "<<t<<" won"<<endl;f=1;break;}

            }
            if(f==1){continue;}

            for(int i=0;i<4;i++)
            {
                int ff=0;
            char t=a[0][i];

            if(t=='T'){
                       t=a[1][i];

                       }

            for(int j=1;j<4;j++)
            if(a[j][i]!=t&&a[j][i]!='T'){ff=1;break;}
            if(ff==0&&t!='.') {cout<<": "<<t<<" won"<<endl;f=1;break;}
            }
if(f==1)continue;

int ff=0;
            char t=a[0][0];
            if(t=='T'){
                       t=a[1][1];

                       }

            for(int j=1;j<4;j++)
            {

            int i=j;
            if(a[i][j]!=t&&a[i][j]!='T'){ff=1;break;}}
            if(ff==0&&t!='.') {cout<<": "<<t<<" won"<<endl;f=1;}

if(f==1)continue;
//cout<<"rest"<<endl;
           t=a[3][0];

            if(t=='T'){
                       t=a[2][1];

                       }
ff=0;
            for(int j=0;j<4;j++)
            {

            int i=3-j;
            if(a[i][j]!=t&&a[i][j]!='T'){ff=1;break;}}
            if(ff==0&&t!='.') {cout<<": "<<t<<" won"<<endl;f=1;}

if(f==1)continue;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
if(a[i][j]=='.')
{


    f1=1;
    break;
}
if(f1==0)cout<<": Draw"<<endl;
else
            cout<<": Game has not completed"<<endl;

    }
      return 0;
}




