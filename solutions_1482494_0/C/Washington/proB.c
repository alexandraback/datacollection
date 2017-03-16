#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 10005

struct level{
    int a,b;
};
typedef struct level l;

l tab[MAXN];
char is_v[MAXN];
char is_p[MAXN];

int cmp(const void *x, const void *y)
{
    l *xx = (l *)x;
    l *yy = (l *)y;
    if(xx->b < yy->b) return 1;
    else if(xx->b > yy->b) return -1;
    else{
        if(xx->a < yy->a)
            return 1;
        else if(xx->a > yy->a)
            return -1;
        else
            return 0;
    }
}

int check(int N)
{
    int i;
    for(i=1;i<=N;i++){
        /* printf("%d ", is_p[i]); */
        if(is_p[i]<2){
            /* printf("\n");*/
            return 1;
        }
    }
    /* printf("\n"); */
    return 0;
}

void find_new(int N, int pnt)
{
    int i;
    for(i=1;i<=N;i++){
        if(tab[i].a>=pnt || tab[i].b>=pnt && is_v[i]==0)
            is_v[i] =1;
    }
}

int get_answser(int N)
{
    int i, ans = 0, pnt = 0, tempA = 0;
    for(i=1;i<=N;i++)
        if(tab[i].a==0 || tab[i].b==0)
            is_v[i] =1;
    for(i=1;i<=N;i++)
        if(is_v[i] == 1)
            break;
    if(i>N) return -1;
    
    while(check(N)){
        tempA = 0;
        for(i=1;i<=N;i++){
            if(is_v[i]==1 && is_p[i]==0){
                if(pnt >= tab[i].b){
                    pnt += 2;
                    ans ++;
                    is_p[i] |= 2;
                    find_new(N, pnt);
                    break;
                }
            }                
        }
        if(i<=N) continue;
        for(i=1;i<=N;i++){
            if(is_v[i]==1 && is_p[i]==0){
                if(pnt >= tab[i].a){
                    pnt += 1;
                    ans++;
                    is_p[i] |= 1;
                    find_new(N, pnt);
                    break;
                }
            }                
        }
        if(i<=N) continue;
        
        for(i=1;i<=N;i++){
            if(is_v[i]==1 && is_p[i]<2){
                if(pnt>=tab[i].b && is_p[i]==1){
                    pnt+=3;
                    ans++;
                    is_p[i] |= 2;
                    find_new(N, pnt);
                    break;
                }
            }
        }
        if(i<=N) continue;

        for(i=1;i<=N;i++){
            if(is_v[i]==1 && is_p[i]==2){
                if(pnt>=tab[i].a && is_p[i]==2){
                    pnt+=1;
                    ans++;
                    is_p[i] |= 1;
                    find_new(N, pnt);
                    break;
                }
            }
        }
        if(i<=N) continue;
        
        for(i=1;i<=N;i++){
            if(is_v[i]==1 && is_p[i]==1){
                pnt+=1;
                ans++;               
                find_new(N, pnt);
            }
        }
        if(i<=N) continue;
        
        for(i=1;i<=N;i++){
            if(is_v[i]==1 & tab[i].b <= pnt){
                pnt+=2;
                if(is_p[i] == 1)
                    pnt ++;
                ans++;
                find_new(N, pnt);
            }
        }
        if(i<=N) continue;
        for(i=1;i<=N;i++){
            if(is_v[i]==1 & tab[i].a <= pnt){
                pnt+=1;
                ans++;
                find_new(N, pnt);
            }
        }
    }
    return ans;
}

int main()
{
    int i,j,k,T,N;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d",&N);
        memset(tab,0,sizeof(tab));
        memset(is_v, 0, sizeof(is_v));
        memset(is_p, 0, sizeof(is_p));
        
        for(j=1;j<=N;j++){
            scanf("%d%d", &tab[j].a, &tab[j].b);           
        }
        qsort(tab+1,N,sizeof(tab[1]), cmp);
        k=get_answser(N);
        printf("Case #%d: ", i);
        if(k==-1)
            printf("Too Bad\n");
        else
            printf("%d\n", k);
    }
    return 0;
}
