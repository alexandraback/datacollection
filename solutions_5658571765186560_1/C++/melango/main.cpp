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
if(x>6){return 0;}
if(x==5&&c>2){return 1;}//need to check!!
if(x==5&&c<3){return 0;}
if(x>r){return 0;}
if(x==6&&c<3){return 0;}
if(x==6&&c>3){return 1;}
if(x==6&&c==3){return 0;}//need to check
return 4;
}
int main()
{int sum=0;
    ifstream input;
    input.open("D-large.in");
    ofstream output;
    output.open("outputlarge.txt");
    ofstream output2;
    output2.open("test1.txt");
    for(int i=1;i<7;i++)
        for(int j=1;j<21;j++)
            for(int k=1;k<21;k++)
                {//output2<<i<<" "<<j<<" "<<k<<" "<<endl;
}
    int cse=1;
    int t;
    input>>t;

    while(cse<=t)
    {
    int poss=3;
int x,r,c;
input>>x>>r>>c;
poss=solve(x,r,c);

if(poss==4){sum++;output2<<sum<<" "<<x<<" "<<r<<" "<<c<<" "<<endl;}
if(poss==0){        output<<"Case #"<<cse<<": RICHARD"<<endl;cout<<x<<" "<<r<<" "<<c<<endl;
        cout<<"Case #"<<cse<<": RICHARD"<<endl;}
        else if(poss=1){        output<<"Case #"<<cse<<": GABRIEL"<<endl;cout<<x<<" "<<r<<" "<<c<<endl;
        cout<<"Case #"<<cse<<": GABRIEL"<<endl;}
        cse++;
    }
cout<<sum;
    return sum;

}
