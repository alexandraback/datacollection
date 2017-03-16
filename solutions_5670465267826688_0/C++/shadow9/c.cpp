#include<cstdio>

int getNum(char c){
    if(c == 'i') return 2;
    if(c == 'j') return 3;
    if(c == 'k') return 4;
}

int mul(int x, int y){
    int m = 1;
    if(x < 0){
        m *= -1;
        x = -x;
    }
    if(y < 0){
        m *= -1;
        y = -y;
    }
    int table[5][5] = {{0, 0, 0, 0, 0},
                       {0, 1, 2, 3, 4},
                       {0, 2, -1, 4, -3},
                       {0, 3, -4, -1, 2},
                       {0, 4, 3, -2, -1}};
    return m*table[x][y];
}

int main(){
    int T, L, X, cnt = 0;
    char str[100010];
    int in[100010], res[100010];
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%s", &L, &X, str);
        for(int i = 0; i < L; i++){
            in[i] = getNum(str[i]);
        }
        int pt = L;
        for(int i = 1; i < X; i++){
            for(int j = 0; j < L; j++){
                in[pt++] = in[j];
            }
        }
        for(int i = 2; i < L*X; i++){
            int pre3 = in[i];
            for(int j = i+1; j < L*X; j++){
                pre3 = mul(pre3, in[j]);
            }
            res[i] = pre3;
        }

        int pre1, pre2, pre3;
        bool ans = false;
        for(int i = 0; i < L*X-2 && !ans; i++){
            if(i == 0) pre1 = in[0];
            else pre1 = mul(pre1, in[i]);
            if(pre1 != getNum('i')) continue;

            for(int j = i+1; j < L*X-1 && !ans; j++){
                if(j == i+1) pre2 = in[i+1];
                else pre2 = mul(pre2, in[j]);
                if(pre2 != getNum('j')) continue;

                if(res[j+1] == getNum('k')) ans = true;

/*                for(int k = j+1; k < L*X; k++){
                    if(k == j+1) pre3 = in[j+1];
                    else pre3 = mul(pre3, in[k]);
                }

                if(pre3 == getNum('k')) ans = true;*/
            }
        }
        printf("Case #%d: %s\n", ++cnt, (ans?"YES":"NO"));
    }
    return 0;
}
