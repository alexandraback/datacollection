#include <cstdio>

bool seenAll(bool *v){
    for(int i=0;i<10;i++)
        if( !v[i] )
            return false;

    return true;
}

void init(bool *s){
    for(int i=0;i<10;i++)
        s[i] = false;
}

void mark(int v, bool *s){
    while( v > 0 ){
        s[v%10] = true;
        v = v/10;
    }
}

int main(){
    int T, N, num;
    bool seen[10];

    scanf("%d", &T);
    for(int caso=1;caso<=T;caso++){
        scanf("%d", &N);

        if( N == 0 ){
            printf("Case #%d: INSOMNIA\n", caso);
            continue;
        }

        init(seen);
        mark(N, seen);
        num = N;

        while( !seenAll(seen) ){
            num += N;
            mark(num, seen);
        }

        printf("Case #%d: %d\n", caso, num);
    }
}
