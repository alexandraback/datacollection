#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef __int64 ll;
const int MAXN = 10010;
ll E, R;
int N;
ll val[MAXN];
ll ans;


int main()
{
    int T, cas = 1;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%I64d %I64d %d", &E, &R, &N);
        for(int i = 0; i < N; i++)
            scanf("%I64d", &val[i]);
        ans = 0;
        if(R >= E){
            for(int i = 0 ; i <  N; i++)
                ans += val[i]*E;
		}else{
            ll cur = E;
            for(int i = 0; i < N; i++){
                int j = i+1;
                while(j < N && val[j] <= val[i])
                    j++;
                if(j == N){
                    ans += cur*val[i];
                    cur = R;
				}else{
					ll tmp = min(cur+(j-i)*R-E, cur);
                    if(tmp <= 0){
                        cur += R;
                        continue;
					}else{
                        ans += tmp*val[i];
                        cur -= tmp;
                        cur += R;
                        if(cur > E) cur = E;
					}
				}
			}
		}
		printf("Case #%d: %I64d\n", cas++, ans);
	}
    return 0;
}