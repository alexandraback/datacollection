#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

double pro[100005];

int main()
{
    int t,a,b;
    double result=0,r1,r2,r3;
    cin>>t;
    for(int casenum=1;casenum<=t;casenum++)
    {
        cin>>a>>b;
        result=(b+2);//立即回车
        for(int i=0;i<a;i++)
            cin>>pro[i];
        for(int i=0;i<=a;i++)
        {
            r1=2*i+b-a+1;//一次过
            r2=2*i+2*b-a+2;//返工一次
            r3=1;
            for(int j=0;j<a-i;j++)
            {
                r3*=pro[j];
            }
            r1*=r3;
            r2*=(1-r3);
            //printf("i=%d re=%.6f\n",i,r1+r2);
            result=result<(r1+r2) ?result:(r1+r2);
        }
        printf("Case #%d: %.6f\n",casenum,result);
    }
    return 0;
}
