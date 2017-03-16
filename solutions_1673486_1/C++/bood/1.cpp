#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>

using namespace std;
int t,a,b;
double ret;
vector<double> p,P,E;
void calc()
{
    P[0]=p[0];
    for(int i=1;i<a;i++) {
        P[i]=P[i-1]*p[i];
    }
    E.resize(a);
    ret = 2+b;
    for(int k=0;k<a;k++) {
        E[k]=b-a+1+2*(a-(k+1))+(1-P[k])*(b+1);
        //cout<<"E"<<k+1<<"="<<E[k]<<endl;
        if(E[k]<ret) ret=E[k];
    }
}
void input()
{
    cin>>a>>b;
    p.resize(a);
    P.resize(a);
    for(int i=0;i<a;i++) cin>>p[i];
}
void output(int ncase)
{
    //cout<<"Case #"<<ncase<<":"<<" "<<ret<<endl;
    printf("Case #%d: %.6f\n",ncase,ret);
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
