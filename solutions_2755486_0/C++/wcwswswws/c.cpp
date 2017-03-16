#include<stdio.h>
#include<string.h>
struct node
{
    int d,n,w,e,s,delta_d,delta_p,delta_s;
};

node heap[1000];
int h[10000];
int n,tt,tot;
int q[100],l[100],r[100],s[100];

void up(int o)
{
    if (o==1) return;
    int p=o/2;
    if (heap[o].d<heap[p].d)
    {
        node tmp=heap[o];heap[o]=heap[p];heap[p]=tmp;
        up(p);
    }
}

void down(int o)
{
    int p=o*2;
    if (p>tot) return;
    if ((p+1<=tot)&&(heap[p+1].d<heap[p].d)) p++;
    if (heap[p].d<heap[o].d)
    {
        node tmp=heap[o];heap[o]=heap[p];heap[p]=tmp;
        down(p);
    }
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        memset(h,0,sizeof(h));
        int ans=0;
        tot=0;
        scanf("%d",&n);
        while (n--)
        {
            tot++;
            scanf("%d%d%d%d%d%d%d%d",&heap[tot].d,&heap[tot].n
                                    ,&heap[tot].w,&heap[tot].e
                                    ,&heap[tot].s,&heap[tot].delta_d
                                    ,&heap[tot].delta_p,&heap[tot].delta_s);
            heap[tot].e--;
            up(tot);
        }
        while (heap[1].d!=1e9)
        {
            l[0]=0;
            int o=heap[1].d;
            while (heap[1].d==o)
            {
                bool check=true;
                for (int i=heap[1].w+500;i<=heap[1].e+500;i++) if (h[i]<heap[1].s) check=false;
                if (!check) ans++;
                l[0]++;
                l[l[0]]=heap[1].w;
                r[l[0]]=heap[1].e;
                s[l[0]]=heap[1].s;
                heap[1].n--;
                heap[1].d+=heap[1].delta_d;
                heap[1].s+=heap[1].delta_s;
                heap[1].w+=heap[1].delta_p;
                heap[1].e+=heap[1].delta_p;
                if (heap[1].n==0) heap[1].d=1e9;
                down(1);
            }
            for (int i=1;i<=l[0];i++)
              for (int j=l[i]+500;j<=r[i]+500;j++) if (h[j]<s[i]) h[j]=s[i];
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
