#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std;
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ppii pair< pii,int >
#define big 2000000000

int kasus,jawab;
LL a,b,temp,gcd;
set <LL> s;

int main()
{
//    freopen("A-large.in","r",stdin);
//    freopen("a-large.out","w",stdout);
    
    temp = 1LL;
    for (int i=1;i<=42;i++)
    {
        temp *= 2LL;
        s.insert(temp);
    }
    
    scanf("%d",&kasus);
    for (int z=1;z<=kasus;z++)
    {
        scanf("%lld/%lld",&a,&b);
        gcd = __gcd(a,b);
        a /= gcd;
        b /= gcd;
        printf("Case #%d: ",z);
        if (b==1LL && a==0) {printf("impossible\n"); continue;}
        else
        {
            if (s.find(b)==s.end()) {printf("impossible\n"); continue;}
            jawab = 0;
            while (a < b)
            {
                a *= 2LL;
                jawab++;
            }
            if (jawab > 40) {printf("impossible\n"); continue;}
            else printf("%d\n",jawab);
        }
    }
    
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
