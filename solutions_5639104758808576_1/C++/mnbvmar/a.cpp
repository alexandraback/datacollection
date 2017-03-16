#include <bits/stdc++.h>

using namespace std;

const int MaxLen = 1005;

char tab[MaxLen];
int N;

void input(){
    scanf("%d%s", &N, tab);
}

void test(){
    input();

    int smallest = 0, current = 0;
    for(int i = 0; i < N; i++){
        current += (tab[i]-'0') - 1;
        smallest = min(smallest, current);
    }
    printf("%d\n", abs(smallest));
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        test();
    }
}
