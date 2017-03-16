#include <stdio.h>
#include <string.h>

struct heap_node_t
{
    int val, num;
}heap1[1100], heap2[1100];
int star1[1100], star2[1100];
int tot1, tot2;

int smaller(struct heap_node_t a, struct heap_node_t b, int extra)
{
    if(extra) return a.val<b.val || (a.val==b.val && star2[a.num]>star2[b.num]);
    else return a.val<b.val;
}

void getup(struct heap_node_t *heap, int x, int *tot, int extra)
{
    int i=x, j=x/2;
    struct heap_node_t k=heap[x];
    while(i>1)
    {
        j=i/2;
        if(smaller(k, heap[j], extra))
        {
            heap[i]=heap[j];
            i=j;
        }else break;
    }
    heap[i]=k;
}

void sink(struct heap_node_t *heap, int x, int *tot, int extra)
{
    int i=x, j=x*2;
    struct heap_node_t k=heap[x];
    while(i*2<=*tot)
    {
        j=i*2;
        if(j+1<=*tot && smaller(heap[j+1], heap[j], extra)) j++;
        if(smaller(heap[j], k, extra))
        {
            heap[i]=heap[j];
            i=j;
        }else break;
    }
    heap[i]=k;
}

void heap_push(struct heap_node_t val, struct heap_node_t *heap, int *tot, int extra)
{
    heap[++(*tot)]=val;
    getup(heap, *tot, tot, extra);
}

struct heap_node_t heap_pop(struct heap_node_t *heap, int *tot, int extra)
{
    struct heap_node_t ans=heap[1];
    heap[1]=heap[(*tot)--];
    sink(heap, 1, tot, extra);
    return ans;
}

int finish2[1100];
int finish1[1100];

int main()
{
    int T;
    int Tcnt=0;
    for(scanf("%d", &T); Tcnt<T; Tcnt++)
    {
        int N;
        int i;
        int stars=0, ans=0;
        int fail=0;
        memset(finish2, 0, sizeof(finish2));
        memset(finish1, 0, sizeof(finish1));
        tot1=tot2=0;
        scanf("%d", &N);
        for(i=0; i<N; i++)
        {
            struct heap_node_t tmp={0,i};
            scanf("%d%d", star1+i, star2+i);
            tmp.val=star1[i];
            heap_push(tmp, heap1, &tot1, 1);
            tmp.val=star2[i];
            heap_push(tmp, heap2, &tot2, 0);
        }
        while(tot2)
        {
            if(tot2 && finish2[heap2[1].num])
            {
                heap_pop(heap2, &tot2, 0);
                continue;
            }
            if(tot1 && (finish2[heap1[1].num] || finish1[heap1[1].num]))
            {
                heap_pop(heap1, &tot1, 1);
                continue;
            }
            if(stars>=heap2[1].val)
            {
                struct heap_node_t top=heap_pop(heap2, &tot2, 0);
                if(finish1[top.num]) stars++;
                else stars+=2;
                finish2[top.num]=1;
                ans++;
                continue;
            }
            else
            {
                struct heap_node_t top;
                if(!tot1 || stars<heap1[1].val)
                {
                    fail=1; break;
                }
                top=heap_pop(heap1, &tot1, 1);
                finish1[top.num]=1;
                stars++;
                ans++;
                continue;
            }
        }
        printf("Case #%d: ", Tcnt+1);
        if(fail) puts("Too Bad");
        else printf("%d\n", ans);
    }
    return 0;
}
