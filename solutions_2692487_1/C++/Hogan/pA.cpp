#include<cstdio>
#include<algorithm>

int T, A, n, con[100];

int Min(int a, int b){return a<b ?a:b;}

int main(){

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &T);

    for (int F=0; F<T; F++){
        scanf("%d%d", &A, &n);

        for (int i=0; i<n; i++) scanf("%d", &con[i]);
        std::sort(con, con + n);

        int cnt = 0, myMin = n;

        for (int i=0; i<n; i++){
            if (A > con[i]) A += con[i];
            else {
                while (A <= con[i] && cnt <= n){
                    A += A - 1;
                    cnt++;
                }
                if (A > con[i]) A += con[i];
            }
            myMin = Min(myMin, cnt + n - 1 - i);
        }
        printf("Case #%d: %d\n", F + 1, myMin);
    }
}
