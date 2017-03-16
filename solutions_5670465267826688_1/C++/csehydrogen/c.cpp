#include <cstdio>

const int NMAX = 11111;

char a[NMAX];
int b[NMAX];

int sign(int x){
    return x < 0 ? -1 : 1;
}

int product(int x, int y){
    int sx = sign(x);
    x *= sx;
    int sy = sign(y);
    y *= sy;
    int ret;
    switch(x){
        case 1: ret = y; break;
        case 2:
            switch(y){
                case 1: ret = 2; break;
                case 2: ret = -1; break;
                case 3: ret = 4; break;
                case 4: ret = -3; break;
            }
            break;
        case 3:
            switch(y){
                case 1: ret = 3; break;
                case 2: ret = -4; break;
                case 3: ret = -1; break;
                case 4: ret = 2; break;
            }
            break;
        case 4:
            switch(y){
                case 1: ret = 4; break;
                case 2: ret = 3; break;
                case 3: ret = -2; break;
                case 4: ret = -1; break;
            }
            break;
    }
    return ret * sx * sy;
}

int power(int x, int p){
    int ret = 1;
    for(int i = 0; i < p % 4; ++i){
        ret = product(ret, x);
    }
    return ret;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ++ti){
        printf("Case #%d: ", ti);
        int l, x;
        scanf("%d%d%s", &l, &x, a);
        for(int i = 0; i < l; ++i){
            b[i] = a[i] == 'i' ? 2 : (a[i] == 'j' ? 3 : 4);
        }

        int tot = 1;
        for(int i = 0; i < l; ++i){
            tot = product(tot, b[i]);
        }
        if(power(tot, x) != -1){
            printf("NO\n");
            continue;
        }

        int cur;
        long long li = 1e17, ri = -1e17;

        cur = 1;
        for(int i = 0; i < l * 4; ++i){
            cur = product(cur, b[i % l]);
            if(cur == 2){
                li = i;
                break;
            }
        }

        cur = 1;
        for(int i = -1; i >= -l * 4; --i){
            cur = product(b[(l * 4 + i) % l], cur);
            if(cur == 4){
                ri = i;
                break;
            }
        }

        if(li < (long long)l * x + ri){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
