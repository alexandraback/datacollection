/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

vector<long long> faq;

int solve(int cc)
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    int sol=0;
    for(int i=0;i<faq.size();i++)
        if(faq[i]>=a&&faq[i]<=b)
            sol++;
    printf("Case #%d: %d\n",cc,sol);
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    char tmp[128];
    for(long long i=1;i<=10000000;i++)
    {
        sprintf(tmp,"%lld",i);
        int len=strlen(tmp);
        bool ch=true;
        for(int j=0,k=len-1;j<len;j++,k--)
        {
            if(tmp[j]!=tmp[k])
                ch=false;
        }
        if(!ch) continue;

        long long ii=i*i;
        sprintf(tmp,"%lld",ii);
        len=strlen(tmp);
        bool isPalin=true;
        for(int j=0,k=len-1;j<len;j++,k--)
        {
            if(tmp[j]!=tmp[k])
                isPalin=false;
        }
        if(isPalin)
            faq.push_back(ii);
    }
/*
    printf("%d\n",faq.size());
    for(int i=0;i<faq.size();i++)
        printf("%lld\n",faq[i]);
*/

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);

	return 0;
}
