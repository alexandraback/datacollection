#include<stdio.h>
#include<stdlib.h>
#define M 1000

struct mytuple{
    long long int num;
    long long int strs;
    long long int strsoth;
};

typedef struct mytuple tuple;

long long int check[M];
tuple a[M], b[M];

int compare(const void *x, const void *y){
    const tuple * ix = (const tuple *) x;
    const tuple * iy = (const tuple *) y;

    if (ix->strs == iy->strs)
        return iy->strsoth - ix->strsoth;
    return ix->strs - iy->strs;
}

int main(){
    long long int res = 0, stars = 0, levelcompl = 0;
    long long int T, N, i, j, k, l;

    scanf("%lld", &T);
    for( i = 0; i < T; i++ ){
        scanf("%lld", &N);
        for( j = 0; j < N; j++ ){
            scanf("%lld %lld", &l, &k);
            a[j].num = j;
            a[j].strs = l;
            a[j].strsoth = k;
            b[j].num = j;
            b[j].strs = k;
            b[j].strsoth = l;
            check[j] = 0;
        }

        qsort(a, N, sizeof(tuple), compare);
        qsort(b, N, sizeof(tuple), compare);

        j = 0;
        k = 0;
        res = 0;
        levelcompl = 0;
        stars = 0;
        while ( (levelcompl >= 0) && (levelcompl < N) ){
            while ( (stars >= b[j].strs) && (levelcompl < N) && (levelcompl >= 0) ){
                ++levelcompl;
                stars += 2 - check[b[j].num];
                check[b[j].num] = 2;
                ++j;
                ++res;
                //printf("Stars have : %lld, Stars want : %lld\n", stars, b[j].strs);
                //printf("Play 2stars for level : %lld\n", b[j].num);
            }
            while ( (stars >= a[k].strs) && (stars < b[j].strs) && (levelcompl < N) && (levelcompl >= 0) ){
                if (check[a[k].num] > 0){
                    ++k;
                }
                else {
                    ++stars;
                    check[a[k].num] = 1;
                    ++k;
                    ++res;
                    //printf("Stars have : %lld, Stars want : %lld\n", stars, a[k].strs);
                    //printf("Play 1stars for level : %lld\n", a[k].num);
                }
            }
            if ( (stars < a[k].strs) && (stars < b[j].strs) ){
                //printf("%lld %lld %lld\n", stars, a[0].strs, b[j].num);
                levelcompl = -1;
            }
        }

        if (levelcompl < 0){
            printf("Case #%lld: Too Bad\n", i + 1);
        }
        else {
            printf("Case #%lld: %lld\n", i + 1, res);
        }
    }

    return 0;
}
