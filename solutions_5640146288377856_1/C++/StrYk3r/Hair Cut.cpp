#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,p;
    ifstream IF;
    ofstream OF;
    IF.open("input.txt");
    OF.open("output.txt");
    IF>>t;
    for(p=1;p<=t;p++)
    {
        long long int m,n,w,i,j;
        IF>>m>>n>>w;
        j=n/w;
        j=j*m;
        if(n%w==0)
            j=j-1;
        j+=w;
        OF<<"Case #"<<p<<": "<<j<<endl;
    }
    IF.close();
    OF.close();
    return 0;
}

