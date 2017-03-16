#include<cstdio>
#include<vector>
#include<algorithm>
#define SIZE 39
using namespace std;
long long FSQ[SIZE] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
vector<long long> V(FSQ,FSQ+SIZE);
int main()
{
    freopen("C-small-attempt0 (1).in","r",stdin);
    freopen("out_fair and square.txt","w",stdout);
    long long a,b;
    int i,tt,T;
    vector<long long>::iterator p,q;
    scanf("%d",&T);
    for (tt=1;tt<=T;tt++)
    {
        scanf("%lld %lld",&a,&b);
        printf("Case #%d: ",tt);
        p = lower_bound(V.begin(),V.end(),a);
        q = upper_bound(V.begin(),V.end(),b);
        printf("%d\n",q-p);
    }
    return 0;
}
