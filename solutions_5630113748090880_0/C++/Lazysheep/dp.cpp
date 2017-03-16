#include<bits/stdc++.h>
using namespace std ;
#define PB(u)  push_back(u);
#define AA   first
#define BB   second
#define inf 0x3f3f3f3f
typedef long long ll ;
typedef pair<int,int> PII ;
#define pi acos(-1)
#define sz size()
#define MAX 100005


int x[MAX],y[MAX];

int main()
{
    int T ;
    cin>>T ;
    int cas=1;
    while(T--)
    {
        double  t,v1,v2;
        cin>>t>>v1>>v2;
        bool flag=true;
        double time1=sqrt(2.0)*300/v1;
        double time2=600.0/v2;
        if(time1>time2) flag=false ;
        time1=600.0/v1;
        time2=600.0/v2+t;
        if(time1>time2) flag=false ;
        if(flag)  printf("Case #%d: Yes\n",cas++);
        else printf("Case #%d: No\n",cas++);
    }
    return 0;
}
