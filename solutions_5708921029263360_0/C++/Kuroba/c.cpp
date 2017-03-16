#include <bits/stdc++.h>
using namespace std;

int T, J, P, S, K;
int n;
int arr[1000]; // list of values
int a[1000];
int cnt[1000] = {0};
int ans[1000] = {0};
int hi = 0;
int idx;
void bf(int x){
    if (x == n){
        if (idx > hi){
            hi = idx;
            //printf("ANSWER FOUND = %d\n", hi);
            for(int i = 0; i<idx; i++){
                ans[i] = arr[i];
                //printf("%d %d %d\n", ans[i]/100+1, ans[i]/10%10+1, ans[i]%10+1);
            }
            //printf("===\n");


        }
        return;
    }

    int i = a[x]/100+1;
    int j = a[x]/10%10+1;
    int k = a[x]%10+1;
    //printf("CONSIDERING %d %d %d\n", i, j, k);
    //printf("%d %d %d\n", cnt[i*100+k], cnt[i*100 + j*10], cnt[j*10 + k]);
    if (cnt[i*100+k] < K && cnt[i*100 + j*10] < K && cnt[j*10 + k] < K){
        cnt[i*100+k]++;
        cnt[i*100 + j*10]++;
        cnt[j*10 + k]++;
        arr[idx] = (i-1)*100 + (j-1)*10 + (k-1);
        idx++;
        //printf("ADDING %d %d %d\n", i, j, k);
        bf(x+1);
        //printf("POPPING %d %d %d\n", i, j, k);
        idx--;
        cnt[i*100+k]--;
        cnt[i*100 + j*10]--;
        cnt[j*10 + k]--;
    }

    bf(x+1);


}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);

    for (int cas = 1; cas<=T; cas++){
        printf("Case #%d: ", cas);

        scanf("%d%d%d%d", &J, &P, &S, &K); // 27 different combinations
        n = 0;
        hi = 0;
        idx = 0;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i<J; i++){
            for(int j = 0; j<P; j++){
                for (int k = 0; k<S; k++){
                    a[n] = i*100 + j*10 + k;
                    n++;

                }
            }
        }

        bf(0);
        //printf("%d\n", n);
        printf("%d\n", hi);

        for(int i = 0; i<hi; i++){
            printf("%d %d %d\n", ans[i]/100+1, ans[i]/10%10+1, ans[i]%10+1);
        }


    }


}
