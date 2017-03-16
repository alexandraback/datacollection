
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
