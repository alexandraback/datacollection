#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int n;
        cin>>n;
        vector<int> vec;
        int tempmax=-1;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            vec.push_back(temp);
            tempmax=max(tempmax,temp);
        }
        int tempmin=tempmax;
        for(int i=1;i<=tempmax;i++)
        {
            int sum=i;
            for(int j=0;j<n;j++)
            {
                if(vec[j]>i)
                {
                    if(vec[j]%i==0)
                    {
                        sum+=(vec[j]/i-1);
                    }
                    else
                    {
                        sum+=(vec[j]/i);
                    }
                }
            }
            tempmin=min(tempmin,sum);
        }
        cout<<"Case #"<<tt<<": "<<tempmin<<endl;
    }
    return 0;
}
