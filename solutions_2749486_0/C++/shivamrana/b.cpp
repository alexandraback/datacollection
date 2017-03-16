/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
int main()
{
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
int t;
si(t);
for(int cases=1;cases<=t;cases++)
{
printf("Case #%d: ",cases);
string s="";
int x,y;
si(x);
si(y);
int tx=0,ty=0;
int f;
if(x>0)
f=-1;
else f=1;
int step=1;
while(tx!=x)
{
tx=tx+(f*step);
step++;
if(f<0)
s+="W";
else s+="E";
f=(-1*f);
}
if(y>0)
f=-1;
else f=1;
step=1;
while(ty!=y)
{
ty=ty+(f*step);
step++;
if(f<0)
s+="S";
else s+="N";
f=(-1*f);
}
cout<<s<<endl;

}
//system("pause");
return 0;
}
