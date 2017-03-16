#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t, n, in[1005], i, j, sum = 0;
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    scanf("%d",&t);
    for(int cnt = 1;cnt <= t;cnt++){
        scanf("%d",&n);
        memset(in, 0, sizeof(in));
        sum = 0;
        for(i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            in[a]++;
            sum+=a;
        }
        //printf("%d\n",sum);
        int ret = 1000;
        int b[1005];
        for(i=1;i<=1000;i++){
            int te = 0;
            for(j=0;j<=1000;j++)
                b[j] = in[j];
            for(j=1000;j>i;j--){
                if(b[j]){
                    if(j > 3*i){
                        te+=b[j];
                        b[j-j/2] += b[j];
                        b[j/2] += b[j];
                        b[j] = 0;
                    }else{
                        te += b[j];
                        b[j-i] += b[j];
                        b[i] += b[j];
                        b[j] = 0;
                    }
                }
            }
            ret = min(ret, i+te);
        }

        printf("Case #%d: %d\n",cnt,ret);
    }
    return 0;
}
