#include<bits/stdc++.h>
using namespace std;
typedef long long int i64;
int main()
{   freopen("A-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int t=1;t<=tt;t++)
    {
        int p,q;
        scanf("%d/%d",&p,&q);
        int age=0;
        bool f=true;
        double x = log2(q);
        double a = x-int(x);
        if(a!=0)f=false;
        while(p<q && f)
        {
            if(!(q&1))
            {
                q=q/2;
                age++;
                //cout<<q<<endl;
            }
            else
            {
                f=false;
                break;
            }
        }
        if(f)printf("Case #%d: %d\n",t,age);
        else printf("Case #%d: impossible\n",t);
    }
    return 0;
}
