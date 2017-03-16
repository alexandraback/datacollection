#include<stdio.h>
#include<stdlib.h>
typedef struct box
{
    int l1,l2,id,ch;
}box;
box arr[1005],tmp[1005];
int cmp(const void *a,const void *b)
{
    if(((box*)a)->l2 == ((box*)b)->l2)
        return ((box*)a)->l1 - ((box*)b)->l1;
    else
        return ((box*)a)->l2 - ((box*)b)->l2;
}
int cmp2(const void *a,const void *b)
{
    if(((box*)a)->l1 == ((box*)b)->l1)
        return ((box*)b)->l2 - ((box*)a)->l2;
    else
        return ((box*)a)->l1 - ((box*)b)->l1;
}
int main()
{
    int a,b,c=0,t,n,st=0,count=0,ck=0;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for(a=0;a<t;a++,c=0,count=0,st=0,ck=0)
    {
        scanf("%d",&n);
        for(b=0;b<n;b++)
        {
            scanf("%d%d",&arr[b].l1,&arr[b].l2);
            arr[b].id=b;
            arr[b].ch=0;
            tmp[b].l1=arr[b].l1;
            tmp[b].l2=arr[b].l2;
        }
        qsort(arr,n,sizeof(box),cmp);
        for(b=0;b<n;b++)
            tmp[arr[b].id].id=b;
        qsort(tmp,n,sizeof(box),cmp2);
        /*
        printf("------------\n");
        for(b=0;b<n;b++)
            printf("%d %d %d\n",arr[b].l1,arr[b].l2,arr[b].id);
        printf("------------\n");
        for(b=0;b<n;b++)
            printf("%d %d %d\n",tmp[b].l1,tmp[b].l2,tmp[b].id);
        */
        for(b=0;b<n;b++)
        {
            if(st>=arr[b].l2)
            {
                if(arr[b].ch==0)
                    st+=2;
                else
                    st+=1;
                arr[b].ch=2;
                count++;
            }
            else if(st>=tmp[c].l1)
            {
                for(; (arr[tmp[c].id].ch==2 || arr[tmp[c].id].ch==1) && c<n ;c++);
                if(c==n)
                {
                    ck=1;
                    break;
                }
                if(st>=tmp[c].l1)
                {
                    st+=1;
                    arr[tmp[c].id].ch=1;
                    c++;
                    count++;
                    b--;
                }
                else
                {
                    ck=1;
                    break;
                }
            }
            else
            {
                ck=1;
                break;
            }
        }
        if(ck==0)
            printf("Case #%d: %d\n",a+1,count);
        else
            printf("Case #%d: Too Bad\n",a+1);
    }
    scanf(" ");
}
