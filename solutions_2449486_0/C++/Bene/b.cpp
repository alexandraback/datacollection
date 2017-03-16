#include<cstdio>
#include<cstring>
int n,m,h[105][105];
int mxh[105], mxs[105];
int canh[105][105], cans[105][105];
int sumh[105], sums[105], numh[105], nums[105];
bool doneh[105], dones[105];
int max(int a, int b) {
    return a>=b? a:b;
}
bool check() {
    while (1) {
        bool notEnd = false;
        bool thisTime = false;
        for (int i=0;i<n;i++) {
            if (doneh[i]) continue;
            notEnd=true;
            if (sumh[i] == numh[i]) {
                thisTime=true;
                doneh[i] = true;
                for (int j=0;j<m;j++) {
                    if (dones[j]) continue;
                    nums[j] -= 1;
                    if (cans[i][j]) sums[j] -= 1;
                }
                break;
            }
        }
        if (thisTime) continue;
        for (int j=0;j<m;j++) {
            if(dones[j]) continue;
            notEnd=true;
            if(sums[j]==nums[j]) {
                thisTime=true;
                dones[j] =true;
                for (int i=0;i<n;i++) {
                    if (doneh[i]) continue;
                    numh[i] -=1;
                    if (canh[i][j]) sumh[i] -= 1;
                }
                break;
            }
        }
        if (!notEnd) break;
        if (notEnd && !thisTime) return false;
    }
    return true;
}
int main() {
    int T;
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) mxh[i] = sumh[i] = 0, numh[i]=m, doneh[i]=0;
        for (int j=0;j<m;j++) mxs[j] = sums[j] = 0, nums[j]=n, dones[j]=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                scanf("%d", &h[i][j]);
                mxh[i] = max(mxh[i], h[i][j]);
                mxs[j] = max(mxs[j], h[i][j]);
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                canh[i][j] = (mxh[i]==h[i][j])?1:0;
                sumh[i] += canh[i][j];
                cans[i][j] = (mxs[j]==h[i][j])?1:0;
                sums[j] += cans[i][j];
            }
        }
        printf("Case #%d: ", t);
        if (check()) printf("YES\n");
        else printf("NO\n");
    }
}
