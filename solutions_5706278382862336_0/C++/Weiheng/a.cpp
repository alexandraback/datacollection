#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t,c;
    cin>>t;
    c=1;
    int p,q;
    while(c<=t)
    {
        scanf("%d/%d",&p,&q);
        long long x,y;
        y=1;
        y<<=40;
        if( y*p%q !=0 ){
            cout<<"Case #"<<c<<": impossible"<<endl;
        } else {
            x = y*p/q;
            int num=40;
            while( (x>>num) == 0)num--;
            num=40-num;
            cout<<"Case #"<<c<<": "<<num<<endl;
        }
        c++;
    }
    return 0;
}

