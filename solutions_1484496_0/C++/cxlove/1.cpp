/*
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define eps 1e-8
using namespace std;
int main(){
//  freopen("1.in","r",stdin);
//  freopen("1.out","w",stdout);
    int t,n,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a[200],mmax=0,cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]==0)
               cnt++;
            mmax=max(a[i],mmax);
        }
        printf("Case #%d:",++cas);
        if(cnt){
            for(int i=0;i<n;i++)
                if(a[i]==0)
                    printf(" %.6f",100.0/cnt);
                else
                    printf(" 0.000000");
            printf("\n");
            continue;
        }
        double low=0,high=mmax,mid;
        while(high-low>eps){
            mid=(low+high)/2;
            double tt=0;
            for(int i=0;i<n;i++)
                tt+=mid/a[i];
            if(tt<=1.0)
                low=mid;
            else
                high=mid;
        }
        for(int i=0;i<n;i++)
            printf(" %.6f",mid*100/a[i]);
        printf("\n");
    }
    return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 300;
int a[maxn];
vector<int> s[3];
int sum[3];
bool flag;
int t, n;

void init() {
   scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    flag = false;
    for (int i = 0; i < 3; i++) {
        s[i].clear();
        sum[i] = 0;
    }
}

void print() {
    printf("%d",s[0][0]);
    for (int i = 1; i < s[0].size(); i++) printf(" %d",s[0][i]);
    printf("\n%d",s[1][0]);
    for (int i = 1; i < s[1].size(); i++)
        printf(" %d",s[1][i]);
    printf("\n");

}

void dfs(int k) {
    if(flag) return;
    if (!flag && sum[0] != 0 && sum[0] == sum[1]) {
        print();
        flag = true;
    }
    if (k >= n) return;
    for (int i = 0; i < 3; i++) {
        s[i].push_back(a[k]);
        sum[i] += a[k];
        dfs(k + 1);
        sum[i] -= a[k];
        s[i].pop_back();
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d",&t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n",i);
        init();
        dfs(0);
        if(!flag) printf("Impossible\n");
    }
    return 0;
}



