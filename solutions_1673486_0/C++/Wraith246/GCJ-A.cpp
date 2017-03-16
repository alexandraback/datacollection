#include <vector>
#include <algorithm>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    //	freopen("D:\\GCJ 2012\\A-small-attempt0.in","r",stdin);freopen("D:\\GCJ 2012\\A-small-attempt0.out","w",stdout);
    	freopen("D:\\GCJ 2012\\A-small-attempt1.in","r",stdin);freopen("D:\\GCJ 2012\\A-small-attempt1.out","w",stdout);
    //	freopen("D:\\GCJ 2012\\A-large.in","r",stdin);freopen("D:\\GCJ 2012\\A-large.out","w",stdout);
    int testcase;
    char flag[100];
    cin>>testcase;
    cin.getline(flag,100);
    for (int caseId=1;caseId<=testcase;caseId++)
    {
        int A,B;
        double res[100001];
        cin>>A>>B;
        double N=A,M=B;
        for(int i=0;i<A;i++)cin>>res[i];
        double asw=2+M;
        for(int i=0;i<=A;i++)
        {
            double t=1;
            for(int j=0;j<A-i;j++)
            {
                t*=res[j];
            }
            asw=min(asw,t*(2*i+M-N+1)+(1-t)*(2*i+M-N+1+M+1));
        }
        printf("Case #%d: ",caseId);
        cout<<setiosflags(ios::fixed)<<setprecision(6)<<asw<<endl;
        
    }
    return 0;
}