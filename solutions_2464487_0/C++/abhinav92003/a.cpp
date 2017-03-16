#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;
int main()
{
    int T,t=1,r,paint;
    scanf(" %d",&T);
    while(t<=T)
    {
        scanf(" %d %d",&r,&paint);
        long long init=(r+1)*(r+1)-r*r;
        double A=1,B=(n*(2*init-4)),C=2*paint;
        B=B/4;
        C/=2;
        C*=-1;
        double dis=(B*B-4*A*C);
        t++;
    }
	return 0;
}
