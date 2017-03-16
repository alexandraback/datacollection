
#include<string.h>

#include<stdio.h>

#include<stdlib.h>

#include<ctype.h>

#include <map>
#include <string>
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
#include <fstream>
#define INF     9999999
using namespace std;
double pp[30][1010][1010];
int main()
{
    ifstream cin("B-small-attempt2.in");
    ofstream cout("out.out");
    int t;
    memset(pp,sizeof(pp),0);
    for(int i=1;i<=20;i++)pp[i][0][0]=1;
    pp[2][2][0]=0.5;
    pp[3][2][0]=0.75;
    pp[3][1][1]=0.25;
    for(int i=4;i<=20;i++)pp[i][2][0]=1;
pp[4][1][1]=0.5;
for(int i=5;i<=20;i++)pp[i][1][1]=1;
for(int i=6;i<=20;i++)pp[i][0][2]=1;
pp[7][4][0]=0.5;
pp[8][4][0]=0.75;
pp[8][3][1]=0.25;
pp[9][4][0]=0.875;
pp[9][3][1]=0.375;
pp[9][2][2]=0.125;
pp[10][4][0]=0.875+0.0625;
pp[10][3][1]=0.375+0.0625;
pp[10][2][2]=0.125+0.0625;
pp[10][1][3]=0.0625;
for(int i=11;i<=20;i++)pp[i][4][0]=1;
pp[11][3][1]=0.875;
pp[11][2][2]=0.375;
pp[11][1][3]=0.125;
for(int i=12;i<=20;i++)pp[i][3][1]=1;
pp[12][2][2]=0.75;
pp[12][1][3]=0.25;
for(int i=13;i<=20;i++)pp[i][2][2]=1;
pp[13][1][3]=0.5;
for(int i=14;i<=20;i++)pp[i][1][3]=1;
for(int i=15;i<=20;i++)pp[i][0][4]=1;
pp[16][6][0]=0.5;
pp[17][6][0]=0.75;
pp[17][5][1]=0.25;
pp[18][6][0]=0.875;
pp[18][5][1]=0.375;
pp[18][4][2]=0.125;
pp[19][6][0]=0.875+0.0625;
pp[19][5][1]=0.375+0.0625;
pp[19][4][2]=0.125+0.0625;
pp[19][3][3]=0.0625;
pp[20][6][0]=0.875+0.0625+0.03125;
pp[20][5][1]=0.375+0.0625+0.03125;
pp[20][4][2]=0.125+0.0625+0.03125;
pp[20][3][3]=0.0625+0.03125;
pp[20][2][4]=0.03125;
    /*
    int h=1;
    for(int i=1;i<20;i++)
    {
        if(pp[i-1][])

    }*/
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,x,y,wx,wy;
        cin>>n>>wx>>wy;
        double p=1.0;
        cout<<"Case #"<<tt<<": "<<pp[n][abs(wx)][wy]<<endl;
    }
}
/*
int b[1000010];
int c[1000010];
int main()
{
    ifstream cin("A-large.in");
    ofstream cout("out.out");
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int a,n;
        cin>>a>>n;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        sort(b,b+n);
        //cout<<b[0];
int mini=0;
int left=0;
int right=n-1;
int cc=0;
int flag=0;
while(left<=right)
{
    if(a>b[left])
    {
        a+=b[left];
        left++;
    }

    else
    {c[cc++]=right-left+1;
    a+=(a-1);
    if(a==1){flag=1;break;}
    }
}
if(cc==0)cout<<"Case #"<<tt<<": "<<0<<endl;
else
{
    int tmp=cc;
    for(int i=0;i<cc;i++)
    if(i+c[i]<tmp)
    tmp=i+c[i];
    if(flag==1)
    tmp=c[0];
    cout<<"Case #"<<tt<<": "<<tmp<<endl;

}
    }
    return 0;
}
*/
