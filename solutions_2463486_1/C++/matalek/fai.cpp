#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#define REP(x,n) for (int x = 0; x < (n); ++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define VAR(v,n) __typeof(n) v = (n)
#define FOREACH(i,c) for (VAR(i,(c).begin()); i!=(c).end(); ++i)
#define deb(a) a
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef pair <int,int> PII;
typedef vector< PII > VPII;

const int N = 10000003;
vector <LL> v;

bool pal(LL a)
{
    VI s;

    while(a != LL(0))
    {
        s.PB(a%LL(10));
        a/=LL(10);
    }

    bool guard = true;
    REP(i,s.size()/2)
        if(s[i] != s[s.size()-1-i])
            guard = false;

    return guard;

}

int main()
{
    int t;
    LL a, b;

    REP(i,N)
        if(pal(i) && pal(LL(i)*LL(i)))
            v.PB(LL(i)*LL(i));

    deb(printf("%d\n",v.size()); REP(i,v.size())
        printf("%lld, ",v[i]);
    printf("\n");)
    /*
    scanf("%d",&t);
    REP(abc,t)
    {
        scanf("%lld%lld",&a,&b);

        vector<LL>::iterator it1, it2;
        it1 = lower_bound(v.begin(),v.end(),a);
        it2 = upper_bound(v.begin(),v.end(),b);

        printf("Case #%d: %d\n",abc+1,distance(it1,it2));

    }
    */

    return 0;
}
