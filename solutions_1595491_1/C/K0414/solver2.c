#include <stdio.h>
#include <string.h>

typedef struct _Dancer {
    int total;
    int max_nosurp;
    int max_surp; 
} Dancer;

Dancer DancerList[150];

static int cmp_nosurp(const void *p1, const void *p2);
static int cmp_surp(const void *p1, const void *p2);

int calc_surp(int idx, int N);
int calc_nosurp(int N);

int main()
{
    int i, j, T, N, S, Thres;
    int Max_nosurp, Max_surp;
    int idx, idx_surp;

    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        memset(DancerList, -1, sizeof(DancerList));
        scanf("%d%d%d", &N, &S, &Thres);
        for(j = 0; j < N; j++) {
            scanf("%d", &DancerList[j].total);
        }

        calc_nosurp(N);
        qsort(DancerList, N, sizeof(Dancer), cmp_nosurp);

        Max_nosurp = 0;
        while(DancerList[Max_nosurp].max_nosurp >= Thres
                    && Max_nosurp < N)
            Max_nosurp++;

        idx_surp = Max_nosurp;
        calc_surp(idx_surp, N);
        qsort(DancerList + idx_surp, N - idx_surp, sizeof(Dancer), cmp_surp);
        idx = idx_surp;
        Max_surp = 0;
        while(DancerList[idx].max_surp >= Thres
                && Max_surp < S) {
            idx++;
            Max_surp++;
        }

        printf("Case #%d: %d\n", i + 1, Max_nosurp + Max_surp);

#if 0
        printf("\tN=%d S=%d p=%d\n", N, S, Thres);
        for(j=0; j<N; j++){
            printf("\tDancer #%d: %d %d\n", j+1, DancerList[j].max_nosurp,
                                DancerList[j].max_surp);
        }
        printf("\n");
#endif
    }

    return 0;
}

static int
cmp_surp(const void *p1, const void *p2)
{
    return ((Dancer *)p2)->max_surp - ((Dancer *)p1)->max_surp;
}

static int
cmp_nosurp(const void *p1, const void *p2)
{
    return ((Dancer *)p2)->max_nosurp - ((Dancer *)p1)->max_nosurp;
}

int calc_surp(int idx, int N)
{
    int i;
    
    for(i = idx; i < N; i++) {
        if(DancerList[i].total < 2)
            DancerList[i].max_surp = -1;
        else if((DancerList[i].total - 2) % 3 == 0)
            DancerList[i].max_surp = (DancerList[i].total - 2) / 3 + 2;
        else if((DancerList[i].total - 3) % 3 == 0)
            DancerList[i].max_surp = (DancerList[i].total - 3) / 3 + 2;
        else if((DancerList[i].total - 4) % 3 == 0)
            DancerList[i].max_surp = (DancerList[i].total - 4) / 3 + 2;
        else
            DancerList[i].max_surp = -1;
    }

    return 0;
}

int calc_nosurp(int N)
{
    int i;

    for(i = 0; i < N; i++) {
        if((DancerList[i].total - 2) % 3 == 0)
            DancerList[i].max_nosurp = (DancerList[i].total - 2) / 3 + 1;
        else if((DancerList[i].total - 1) % 3 == 0)
            DancerList[i].max_nosurp = (DancerList[i].total - 1) / 3 + 1;
        else if(DancerList[i].total % 3 == 0)
            DancerList[i].max_nosurp = DancerList[i].total / 3;
        else
            DancerList[i].max_nosurp = -1;
    }

    return 0;
}

