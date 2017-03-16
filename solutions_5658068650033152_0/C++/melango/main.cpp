#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
int solve(int n,int m,int k);
int main()
{
    ifstream input;
    input.open("small4.txt");
    ofstream output;
    output.open("output4.txt");
    int t;
input>>t;
int cse;
for(cse=1;cse<=t;cse++)
{
int n;
int m;
int k;
input>>n>>m>>k;

output<<"Case #"<<cse<<": "<<solve(n,m,k)<<endl;
}

return 0;
}
int solve(int n,int m,int k)
{
if(k<5)
{
    return k;
}
if(n<3||m<3)
{
    return k;
}
if(k>m*n-5)
{
    int xy=k+4-m*n+2*m+2*n-8;
    return k+4-m*n+2*m+2*n-8;
}
int mini=2*m+2*n;
int check=0;
int i;
int j;
int df;
for (i=1;i<=m;i++)
{
    for (j=1;j<=n;j++)
    {
        if(abs(k-(i*j-4))+2*(i+j)-8<mini)
        {
            mini=abs(k-(i*j-4))+2*(i+j)-8;
            df=j;
        }
    }
}

int area=k+4;
int side2=0;
int side=sqrt(k+4)+1;
while(side>0)
{
    if (area%side==0)
    {
        side2=area/side;
        if(side<=n && side2<=m)
        {
            check=1;
            break;
        }
        if(side<=m && side2<=n)
        {

            check=1;
            break;
        }
    }

    side--;
}

return mini;
}
