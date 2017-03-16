#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b,c,total=0,totalb=0,d;
        cin>>a>>b>>c;

        for(int j=0;j<a;j++)
        {
            cin>>d;
            if(c==1&&d==0)continue;
            if(d>=(c*3)-2)total++;
            else if(d>=(c*3)-4)totalb++;
        }

        cout<<"Case #"<<i+1<<": "<<total+(totalb>b?b:totalb)<<endl;
    }
    return 0;
}

