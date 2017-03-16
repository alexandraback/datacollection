#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream in("A-small-attempt1.in");
ofstream out("A-small-attempt1.out");
int t;
in>>t;
for(int y=1;y<=t;y++)
{
int r,c,w;
in>>r>>c>>w;
int k=c/w;
if(c%w==0)
k--;
int res=w+k;
out<<"Case #"<<y<<": ";
out<<res<<"\n";
}
}
