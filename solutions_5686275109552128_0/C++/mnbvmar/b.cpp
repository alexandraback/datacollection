#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1005;

int N;
int tab[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &tab[i]);
}

void test(){
    input();
    sort(tab, tab+N);
    int maxLimit = tab[N-1];
    int result = 1e9;

    for(int limit = 1; limit <= maxLimit; limit++){
        int total = 0;
        for(int i = 0; i < N; i++){
            total += max(0, (tab[i]-1)/limit);
        }
        result = min(result, total+limit);
    } 

    printf("%d\n", result);
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        test();
    }
}
