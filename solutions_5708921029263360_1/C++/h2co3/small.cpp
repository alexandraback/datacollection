#include <bits/stdc++.h>

int J,P,S,K;
std::vector<std::tuple<int,int,int>> vec;
std::vector<int> choices,best;
int count[3][3][3][3];

void search(int at) {
    if ((int)choices.size() + (int)vec.size() - at < (int)best.size()) {
        return ;
    }
    if (at == (int)vec.size()) {
        best = choices;
        return ;
    }

    int A[3];
    std::tie(A[0],A[1],A[2]) = vec[at];

    bool flag = true;
    for (int i = 0; i < 3; ++ i) {
        for (int j = i + 1; j < 3; ++ j) {
            if (count[i][j][A[i]][A[j]] + 1 > K) {
                flag = false;
            }
        }
    }

    if (flag) {
        for (int i = 0; i < 3; ++ i) {
            for (int j = i + 1; j < 3; ++ j) {
                count[i][j][A[i]][A[j]] ++;
            }
        }
        choices.push_back(at);
        search(at + 1);
        choices.pop_back();
        for (int i = 0; i < 3; ++ i) {
            for (int j = i + 1; j < 3; ++ j) {
                count[i][j][A[i]][A[j]] --;
            }
        }
    }

    search(at + 1);

}

void work() {
    vec.clear();
    for (int i = 0; i < J; ++ i) {
        for (int j = 0; j < P; ++ j) {
            for (int k = 0; k < S; ++ k) {
                vec.emplace_back(i,j,k);
            }
        }
    }
    best.clear();
    search(0);

    printf("%d\n",(int)best.size());
    for (auto id : best) {
        int a,b,c;
        std::tie(a,b,c) = vec[id];
        printf("%d %d %d\n",a + 1,b + 1,c + 1);
    }
}

int main() {
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d%d%d%d",&J,&P,&S,&K);
        printf("Case #%d: ",++ca);
        work();
    }
}
