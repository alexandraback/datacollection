#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
using namespace std;
int solve(int x, int r, int c)
{
if(r<c){return solve(x,c,r);}
if(x==1){return 1;}
if((r*c)%x!=0){return 0;}
if(x==2){return 1;}
if(x>r*c){return 0;}
if(x==4&&r<4){return 0;}
if(x==4&&c<3){return 0;}
if(x==4&&c>2){return 1;}
if(x==3&&c>1){return 1;}
if(x==3&&c==1){return 0;}
return 4;
}
int main()
{
    ifstream input;
    input.open("small.in");
    ofstream output;
    output.open("output.txt");
    ofstream output2;
    output2.open("test.txt");
    for(int i=1;i<5;i++)
        for(int j=1;j<5;j++)
            for(int k=1;k<5;k++)
                output2<<i<<" "<<j<<" "<<k<<" "<<endl;
    int cse=1;
    int t;
    input>>t;

    while(cse<=t)
    {
    int poss=3;
int x,r,c;
input>>x>>r>>c;
poss=solve(x,r,c);
if(poss==4){}
if(poss==0){        output<<"Case #"<<cse<<": RICHARD"<<endl;cout<<x<<r<<c<<endl;
        cout<<"Case #"<<cse<<": RICHARD"<<endl;}
        else if(poss=1){        output<<"Case #"<<cse<<": GABRIEL"<<endl;cout<<x<<r<<c<<endl;
        cout<<"Case #"<<cse<<": GABRIEL"<<endl;}
        cse++;
    }

    return 0;
}
