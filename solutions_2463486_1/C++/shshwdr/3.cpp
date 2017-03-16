
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

 char ch[1000];

bool fair(__int64 i)
{


    _i64toa(i,ch,10);
    string chh=ch;
    int len=chh.length();

    for(int j=0;j<len;j++)

    if(chh[j]!=chh[len-j-1])
    {

return 0;}


    return 1;
}
int main()
{
    int num;
    ifstream cin("C-large-1.in");
    ofstream cout("out.out");

    int a=0;
    __int64 mapp[1000];
    for(__int64 i=1;i<10000002;i++)
    if(fair(i))
    {
        //cout<<"aa"<<i<<endl<<i*i<<endl<<endl;
       if(fair(i*i))
{
       mapp[a++]=i*i;
}
    }
        cin>>num;
    for(int i=1;i<=num;i++)
{
    __int64 s,b;
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




