#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,result,n,s,p,in[200];
    cin>>t;
    for(int casenum=1;casenum<=t;casenum++)
    {
        result=0;
        cin>>n>>s>>p;
        for(int i=0;i<n;i++)
            cin>>in[i];
        sort(in,in+n);
        for(int i=0;i<n;i++)
        {
            if(3*p-2<=in[i])
                result++;
            else if(p==1)
            {
                if(in[i]>=1)
                    result++;
            }
            else if(3*p-4<=in[i] && s!=0)
            {
                result++,s--;
            }
        }
        cout<<"Case #"<<casenum<<": "<<result<<endl;
    }
}
