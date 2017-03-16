#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream in("A-large.in");
ofstream out("A-large.out");
int t;
in>>t;
for(int y=1;y<=t;y++)
{
int r,c,w;
in>>r>>c>>w;
int k=c/w;
int add=(r-1)*k;
if(c%w==0)
k--;
int res=add+w+k;
out<<"Case #"<<y<<": ";
out<<res<<"\n";
}
}
