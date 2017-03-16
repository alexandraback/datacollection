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
    //	freopen("D:\\GCJ 2012\\A-small-attempt2.in","r",stdin);freopen("D:\\GCJ 2012\\A-small-attempt2.out","w",stdout);
    //	freopen("D:\\GCJ 2012\\A-small-attempt1.in","r",stdin);freopen("D:\\GCJ 2012\\A-small-attempt1.out","w",stdout);
    	freopen("D:\\GCJ 2012\\A-large.in","r",stdin);freopen("D:\\GCJ 2012\\A-large.out","w",stdout);
    int testcase;
    char flag[100];
    cin>>testcase;
    cin.getline(flag,100);
    for (int caseId=1;caseId<=testcase;caseId++)
    {
        int N;
        cin>>N;
        double a[201],sum=0.0,ma=0.0;
        int n=N;
        for(int i=0;i<N;i++)
        {
            cin>>a[i];sum+=a[i];
            if(a[i]>ma)ma=a[i];
        }
        double avg=2*(sum/double(N)),Sum=sum;
        for(int i=0;i<N;i++)
        {
            if(a[i]>avg){n--;Sum=Sum-a[i];a[i]=-1;}
        }
        avg=Sum/double(n)+(sum/double(n));
        printf("Case #%d:",caseId);
        for(int i=0;i<N;i++)
        {
            cout<<" ";
            double asw;
            if(a[i]!=-1)asw=(avg-a[i])*100.0/sum;else asw=0.000000;
            cout<<setiosflags(ios::fixed)<<setprecision(6)<<asw;
        }
        cout<<endl;
        
    }
    return 0;
}