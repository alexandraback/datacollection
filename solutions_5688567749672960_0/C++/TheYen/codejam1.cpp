#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ul;
ul x,ct;
ul reversex(ul n)
{
    ul reverse=0;
    while (n != 0)
   {
      reverse = reverse * 10;
      reverse = reverse + n%10;
      n       = n/10;
   }
   return reverse;
}
void bfs()
{
set<ul> s;
queue<pair<ul,ul> > q;
q.push({12,1});
s.insert(12);
while(!q.empty())
{
pair<ul,ul> v;
v=q.front();
ul n1=reversex(v.first);
q.pop();
if(v.first==x)
{
    ct=v.second;
    return;
}
if(s.find(n1)==s.end())
{
    q.push({n1,v.second+1});
    s.insert(n1);
}
if(s.find(v.first+1)==s.end())
{
    q.push({v.first+1,v.second+1});
    s.insert(v.first+1);
}

}

}
int main()
{
   freopen("kk.in","r",stdin);
    freopen("kk1.out","w",stdout);
    int t,p=0;
    cin>>t;
    while(t--)
    {
        ct=0;
        ul n;
        cin>>n;
        x=n;
        cout<<"Case #"<<++p<<": ";
        if(n<=20)
        {
            cout<<n<<endl;
        }
        else
        {

        bfs();

        cout<<ct+11<<endl;
        }
    }
    return 0;
}
