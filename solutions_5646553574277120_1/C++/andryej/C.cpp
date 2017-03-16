#include <cstdio>
#include <vector>

#define INF 1000000000000LL

typedef unsigned long long ULL;
typedef long int LI;

LI C,D,V,R;

LI getNext(int *a, int& idx)
{
    return idx<D ? a[idx++] : INF;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        R = 0;
        scanf("%ld %ld %ld",&C, &D, &V);
        int a[D];
        for(int i = 0;i<D;++i)scanf("%d",&a[i]);
        LI Mu = C;
        int it = 1;
        if (a[0]!=1) {
            R+=1;
            it = 0;
        }
        while(Mu<V)
        {
            //printf("I CAN %ld\n",Mu);
            LI next = getNext(a, it);
            //printf("NEXT VAL : %ld\n",next);
            if (Mu + 1 < next) {
                Mu += C*(Mu+1);
                //printf("\t ADDING %ld\n",Mu+1);
                R++;
                it -= next != INF ? 1 : 0;
            }
            else {
                Mu += C*next;
            }
            //printf("\t NO I CAN %ld\n",Mu);
        }
        printf("Case #%d: %ld\n",i,R);
    }
    return 0;
}
