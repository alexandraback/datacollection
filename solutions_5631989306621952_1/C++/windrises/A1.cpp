#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<complex>
#define ft first
#define sd second
#define pb push_back
#define mkp make_pair
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)<(b)?(b):(a))
using namespace std;
typedef long long LL;
typedef pair<int,int> Pair;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
const int maxn=5010;
int n;
char a[maxn];
char b[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%s",a+2000);
        int len=strlen(a+2000);
        int p1=2000,p2=2000;
        b[2000]=a[2000];
        for(int i=2001;i<=2000+len;i++)
        {
            if(a[i]>=b[p1])
            {
                b[--p1]=a[i];
            }
            else
            {
                b[++p2]=a[i];
            }
        }
        printf("Case #%d: %s\n",kase,b+p1);
    }
}
