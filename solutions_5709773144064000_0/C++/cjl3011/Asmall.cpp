#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int main(int argc,char *argv[])
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    int t;
    double c,f,x;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        double sum=0;
        scanf("%lf %lf %lf",&c,&f,&x);
        double tmp=2;
        while(c/tmp+x/(tmp+f)<x/tmp)
        {
            sum+=c/tmp;
            tmp+=f;
        }
        sum+=x/tmp;
        printf("Case #%d: %.7lf\n",cas,sum);
    }
    return 0;
}

