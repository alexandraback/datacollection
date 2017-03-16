#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e6+5;

using namespace std;

inline int isg(char s)
{
    return s=='i' || s=='e' || s=='o' || s=='a' || s=='u';
}
char s[N];
int a[N];
int b[N];

int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int Test;
    int n;
    ll ans=0,r;
    scanf("%d",&Test);
    for(int test=1;test<=Test;++test)
    {
        scanf("%s%d",&s,&n);
        int len =strlen(s);

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        b[len]=len;
        for(int i=len-1;i>=0;--i)
        {
            a[i] = 1-isg(s[i]);
            if (a[i+1] && a[i]) a[i]+=a[i+1];
            if (a[i]>n) a[i]=n;
            if (a[i]==n) b[i]=i;
            else b[i]=b[i+1];
        }
//        for(int i=0;i<len;++i) printf("%d ",a[i]);
//        printf("\n");
//        for(int i=0;i<len;++i) printf("%d ",b[i]);
//        printf("\n");
        ans=0;
        for(int i=0;i<len;++i)
        {
            r = b[i]+n-1;
            if (r>len) r = len;
            ans+=len-r;
         //   printf("%d\n",ans);
        }
        printf("Case #%d: %lld\n",test,ans);
    }
    return 0;
}
