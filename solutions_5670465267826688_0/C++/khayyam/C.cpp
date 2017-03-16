#include <stdio.h>
#define LL long long
#define SIGN(x) (((x)<0)?(-1):(1))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define MIN(a, b) ((a)<(b)?(a):(b)) 
#define I 2
#define J 3
#define K 4
int T[5][5]={
    {0, 0,  0,  0,  0},
    {0, 1,  I,  J,  K},
    {0, I, -1,  K, -J},
    {0, J, -K, -1,  I},
    {0, K,  J, -I, -1}
};

int get_quaternion(char c){
    switch(c){
        case 'i':
            return I;
        case 'j':
            return J;
        case 'k':
            return K;
    }
    return 0;
}

int prod(int a, int b){
    return SIGN(a)*SIGN(b)*T[ABS(a)][ABS(b)];
}

char Q[10001];
LL L, X;

bool is_feasible(){
    int rep=MIN(X, 10);
    int current=1;
    int q=1;
    bool found_i = false;
    bool found_j = false;
    for(int r=0; (r < rep) && (!found_j); ++r){
        for(int i=0;i<L;++i){
            if(r==0){
                q = prod(q, Q[i]);
            }
            current = prod(current, Q[i]);
            if(current == I){
                found_i = true;
            }
            if((current == K) && found_i){
                found_j = true;
            }
            
        }
    }
    if((!found_i) || (!found_j)){
        return false;
    }
    if(q == 1){
        return false;
    }
    if(q == -1){
        return ((X%2) == 1);
    }
    if((X%2) == 1){
        return false;
    }
    X/=2;
    return (X%2) == 1;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1;c<=T;++c){
        scanf("%lld%lld", &L, &X);
        scanf("%s", Q);
        for(int i=0;i<L;++i){
            Q[i] = get_quaternion(Q[i]);
        }
        bool feasible = is_feasible();
        if(feasible){
            printf("Case #%d: YES\n", c);
        }else{
            printf("Case #%d: NO\n", c);
        }
    }
    return 0;
}
