#include <bits/stdc++.h>

using namespace std;


typedef long long LL;
typedef long double LD;

const LD Eps = 3e-16;

bool is_zero(LD x){
    return x >= -Eps && x <= Eps;
}

struct Case {
    int N;
    vector<int> D, S;


    void input(){
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            for(int j = 0; j < b; j++){
                D.push_back(a);
                S.push_back(c+j);
            }
        }
    }


    void run(){
        if(D.size() ==1){
            printf("0\n"); return;
        }

        assert(D.size() == 2);
        LL maxFirst=0, minSecond=8e18;
        for(int i = 0; i < 2; i++){
            maxFirst = max(maxFirst, (LL)(360 - D[i]) * S[i]);
            minSecond = min(minSecond, (LL)(720 - D[i]) * S[i]);
        }

//        printf("%.16Lf %.16Lf\n", maxFirst, minSecond);

        if(is_zero(maxFirst-minSecond) || minSecond < maxFirst){
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
};

int main(){
    int numTests;
    scanf("%d", &numTests);

    for(int i = 1; i <= numTests; i++){
        Case C;
        C.input();
        printf("Case #%d: ", i);
        C.run();
    }
}
