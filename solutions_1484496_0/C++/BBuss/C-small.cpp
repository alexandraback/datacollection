#include<cstdio>
#include<cstring>

using namespace std;

int marc[32];
int v[32], n;

bool bt(int i){

    if(i == n){

        int s1 = 0;
        int s2 = 0;
        int q1 = 0;
        int q2 = 0;

        for(int j = 0; j < n; ++j){
            if(marc[j] == 1) {s1 += v[j]; q1++;}
            else if(marc[j] == 2) {s2 += v[j]; q2++;}
        }

        if(s1 == s2 && q1 > 0 && q2 > 0){

            //printf("%d %d\n", s1, s2);
            for(int j = 0; j < n; ++j){
                if(marc[j] == 1) printf("%d ", v[j]);
            }
            printf("\n");
            for(int j = 0; j < n; ++j){
                if(marc[j] == 2) printf("%d ", v[j]);
            }
            printf("\n");

            return true;
        }
        else return false;
    }

    for(int k = 0; k < 3; ++k){
        marc[i] = k;
        if(bt(i+1))return true;
    }
    marc[i] = 0;
        
    return false;
}

int main(void){

    int t;

    scanf("%d", &t);

    for(int i = 1; i <= t; ++i){

        printf("Case #%d:\n", i);

        scanf("%d", &n);

        for(int j = 0; j < n; ++j){
            scanf("%d", &v[j]);
            marc[j] = 0;
        }

        if(!bt(0)) printf("Impossible\n");
    }

    return 0;
}
