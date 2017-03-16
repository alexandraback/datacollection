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
bool good(string temp,int n)
{
int c=0;
for(int i=0;i<temp.length();i++)
{
if(temp[i]!='a'&&temp[i]!='e'&&temp[i]!='i'&&temp[i]!='o'&&temp[i]!='u')
{
int j=i;
c=0;
while(temp[j]!='a'&&temp[j]!='e'&&temp[j]!='i'&&temp[j]!='o'&&temp[j]!='u'&&j<temp.length())
{
j++;
c++;
}
if(c==n)
return true;
}
}
return false;
}

int main()
{
freopen("a.in","r",stdin);
freopen("a.out","w",stdout);
int t;
si(t);
for(int cases=1;cases<=t;cases++)
{
printf("Case #%d: ",cases);
string s;
cin>>s;
int n;
si(n);
vector<string> sub;
for(int i=0;i<s.length();i++)
for(int j=i;j<s.length();j++)
{
string temp(s.begin()+i,s.begin()+j+1);
sub.push_back(temp);
}
int count=0;
for(int i=0;i<sub.size();i++)
{
if(good(sub[i],n))
count++;
}
cout<<count<<endl;

}
//system("pause");
return 0;
}
