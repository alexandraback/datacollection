#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fstream>

using namespace std;
int fastread()
{
    int input;
    char c=0;
    while (c<33) c=getchar();
    input=0;
    while (c>33)
    {
        input=input*10+c-'0';
        c=getchar();
    }
    return input;
}

// computes gcd(a,b)
long long int gcd(long long int a, long long int b) {
    long long int tmp;
    while(b){a%=b; tmp=a; a=b; b=tmp;}
    return a;
}

bool IsPowerOfTwo(long long int x)
{
    return (x & (x - 1)) == 0;
}

int main()
{
    int t,s, cnt;
    long long int y;
    char c;
    long long int p,q;
    ifstream myfile;
    myfile.open("/Users/jigyayadav/Downloads/A-small-attempt0.in-2.txt");
    ofstream outfile;
    outfile.open("/Users/jigyayadav/Downloads/A-smallout.txt");
    myfile>>t;
    int ans;
    for(s=1;s<=t;s++)
    {
//        cout<<"Here"<<endl;
        ans=1;
        myfile>>p;
        myfile>>c;
        myfile>>q;
//        cout<<"Read"<<p<<" "<<q<<endl;
        cnt=0;
        y=gcd(p,q);
//        cout<<"gcd="<<y<<endl;
//        cout<<"Hre1"<<p<<" "<<q<<endl;
        p=p/y;
        q=q/y;
//        cout<<p<<" "<<q<<endl;
        if(!IsPowerOfTwo(q) || p>q)
        {
            outfile<<"Case #"<<s<<": "<<"impossible"<<endl;
        }
        else
        {
            while(p<q)
            {
                q/=2;
                cnt++;
            }
            outfile<<"Case #"<<s<<": "<<cnt<<endl;
        }
    }
    myfile.close();
    outfile.close();
    return 0;
}