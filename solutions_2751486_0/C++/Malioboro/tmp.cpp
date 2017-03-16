#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <time.h>
using namespace std;
#define ot(x) cout<<x<<endl
#define cen cout<<endl
#define rep(u,a,b) for(int u=a;u<b;u++)
#define reo(z,b) for(int z=0;z<b;z++)
#define st ot((float)((float)t2-t1)/CLOCKS_PER_SEC)
int i,t,j,m,q,k,u,n,maks,mnm,a[10005];
long long int tmp,tma;
int main ()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        string s;
        cin>>s;
        long long int tot=0,m=0,akh=0,awl=0,tmp=0;
        scanf("%d",&k);
        for(j=0;j<s.length();j++){
            if(s[j]!='a' && s[j]!='i' &&  s[j]!='e' &&  s[j]!='u' && s[j]!='o')
                tmp++;
            else
                tmp=0;

            if(tmp==k){
                tmp=k-1;
                akh=j;
                awl=j-k+1;
                tot+=(long long)(s.length()-akh)*(awl+1-m);
                m=awl+1;
            }
        }
        printf("Case #%d: %lld\n",i,tot);
    }
    return 0;
}
/*
space for testcase

*/
