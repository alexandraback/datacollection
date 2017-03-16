/*

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
int T;
int n, V, mn;
int a[21];
int f[100000*20 + 1];
int be[21];
bool dfs(int x) {
    if (x>=n) {
        int sum1=0, sum2=0, last1, last2;
        for (int i=0;i<n;i++) {
            if (be[i]==1) {
                sum1+=a[i];
                last1 = i;
            }
            else if (be[i]==2) {
                sum2+=a[i];
                last2 = i;
            }
        }
        if (sum1 == 0 && sum2 == 0) return false;
        if (sum1 == sum2) {
            for (int i=0;i<n;i++)
                if (be[i]==1) printf("%d%c", a[i], i==last1?'\n':' ');
            for (int i=0;i<n;i++)
                if (be[i]==2) printf("%d%c", a[i], i==last2?'\n':' ');
            return true;
        }
        return false;
    }
    for (int i=0;i<=2;i++) {
        be[x]=i;
        if (dfs(x+1)) return true;
    }
    return false;
}
void display()
{
    scanf("%d",&T);
    for (int ca=1;ca<=T;ca++) {
        printf("Case #%d:\n",ca);
        scanf("%d",&n);
        V = 0;
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            V+=a[i];
        }
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=0;i<n;i++) 
            for (int v=V;v>=a[i];v--) 
                f[v] += f[v-a[i]];
        for (mn=0; mn<=V; mn++)
           if (f[mn]>1) break; 
        if (mn == V+1)
            printf("Impossible\n");
        else {
            sort(a, a+n);
            while (a[n-1]>mn) n--;
            memset(be,0,sizeof(be));
            if (!dfs(0))
                printf("Impossible\n");
        }
    }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt.out","w",stdout);
    display();
    return 0;
}

