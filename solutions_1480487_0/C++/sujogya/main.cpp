#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
double s[205];
double x[205];
double ans[205];
int n;
bool used[205];
double sum;
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("out4.txt","w",stdout);
    int t;
    cin>>t;
    int cas = 1;
    while(t--)
    {
        memset(used,0,sizeof(used));
        sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            sum+=s[i];
        }
        double total = sum*2;
        double aver=total/n;
        bool f = 1;
        int ret = n;
        double rest = total;
        while(f)
        {
            f = 0;
            for(int i=0;i<n;i++)
            {
                if(used[i])
                    continue;
                if(s[i]>aver)
                {
                    used[i]=1;
                    ret--;
                    f=1;
                    total-=s[i];
                    //cout<<"del "<<s[i]<<endl;
                }
            }
            aver=total/ret;
        }
        aver = total/ret;
        //cout<<aver<<endl;
        for(int i=0;i<n;i++)
        {
            if(used[i])
            {
                ans[i]=0;
                continue;
            }
            if(s[i]>=aver)
                ans[i]=0;
            else
                ans[i]=(aver-s[i])/sum;
        }
        printf("Case #%d:",cas++);
        for(int i=0;i<n;i++)
        {
            printf(" %.6lf",ans[i]*100);
        }
        cout<<endl;
    }
    return 0;
}
