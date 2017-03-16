#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

long long Min(long long a,long long b)
{
    if(a<b) return a;
    else return b;
}

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    int T;
    long long r,t,left,right,mid;
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>r>>t;
        left=1;
        right=1;
        for(int i=1;i<=9;i++)
        {
            right=right*10;
        }
        right=Min(right,t/(2*r-1))+1;
        while((left+1)<right)
        {
            mid=(left+right)/2;
            long long tmp=2*mid*mid+(2*r-1)*mid;
            if(tmp<=t) left=mid;
            else right=mid;
        }
        cout<<"Case #"<<ca<<": "<<left<<endl;
    }
    return 0;
}





































