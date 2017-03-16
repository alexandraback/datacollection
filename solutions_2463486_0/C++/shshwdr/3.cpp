
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

 char ch[10000000];

bool fair(int i)
{

    itoa(i,ch,10);
    string chh=ch;
    int len=chh.length();
    for(int j=0;j<len;j++)
    if(chh[j]!=chh[len-j-1])return 0;


    return 1;
}
int main()
{
    int num;
    ifstream cin("B-large.in");
    ofstream cout("out.out");
    cin>>num;
    int a=0;
    int mapp[1000];
    for(int i=1;i<500;i++)
    if(fair(i))
    {
        if(fair(i*i))
       // cout<<i<<endl<<i*i<<endl;
       mapp[a++]=i*i;
    }
    for(int i=1;i<=num;i++)
{
    int s,b;
    int cou=0;
    cin>>s>>b;
for(int j=0;j<a;j++)
{
    if(s<=mapp[j]&&mapp[j]<=b)cou++;
}
cout<<"Case #"<<i<<": "<<cou<<endl;

}

      return 0;
}




