#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}
struct node{
    int val;
    int pre,next,tpre;
} no[10000005];

int t[10000005][2];
int a[5000005];

int ans1[505];
int ans2[505];
int len;
void pt(int k,int j){
    len=0;
    while(k!=1){
        ans1[len]=no[k].val-no[no[k].tpre].val;
        len++;
        k=no[k].tpre;
    }
    qsort(ans1,len,sizeof(int),cmpint);
    int i;
    for1(i,0,len-1)
     printf("%d ",ans1[i]);
    printf("%d\n",ans1[len-1]);

    k=t[j][1];
    len=1;
    ans2[0]=t[j][0]-no[k].val;
    while(k!=1){
        ans2[len]=no[k].val-no[no[k].tpre].val;
        len++;
        k=no[k].tpre;
    }
    qsort(ans2,len,sizeof(int),cmpint);
    for1(i,0,len-1)
     printf("%d ",ans2[i]);
    printf("%d\n",ans2[len-1]);
}

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&p);
    for1(o,0,p){
        scanf("%d",&n);
        for1(i,0,n)
          scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),cmpint);
        printf("Case #%d:\n",o+1);
        same(no);
        no[0].next=1;
        no[0].pre=1;
        no[1].pre=0;
        no[1].next=0;
        no[1].tpre=1;
        no[1].val=0;
        l=2;
        int fg=0;
        for1(i,0,n){
            /*
            int tk=0;
            while(no[tk].next!=0){
                tk=no[tk].next;
                printf("%d ",no[tk].val);
            }
            printf("\n");
            */
            k=0;m=0;
            while(no[k].next!=0){
                k=no[k].next;
                t[m][0]=no[k].val+a[i];
                t[m][1]=k;
                m++;
            }
            //printf("m=%d\n",m);
            k=0;
            for1(j,0,m){
               k=no[k].next;
               while(no[k].val<t[j][0]&&k!=0)
                 k=no[k].next;
               // printf("k=%d\n",k);
               if(k==0&&l<10000000){
                  // printf("test\n");
                   no[l].val=t[j][0];
                   no[no[0].pre].next=l;
                   no[l].next=0;
                   no[l].pre=no[0].pre;
                   no[0].pre=l;
                   no[l].tpre=t[j][1];
                   l++;
               }
               else if(no[k].val>t[j][0]&&l<10000000){
                   no[l].val=t[j][0];
                   no[no[k].pre].next=l;
                   no[l].next=k;
                   no[l].pre=no[k].pre;
                   no[k].pre=l;
                   no[l].tpre=t[j][1];
                   l++;
               }
               else if(no[k].val==t[j][0]){
                   pt(k,j);
                   fg=1;
                   break;
               }
               else if(l==10000000){
                  fg=2;
                  break;
               }
            }
            if(fg!=0) break;
        }
        if(fg!=1) printf("Impossible\n");
    }
    return 0;
}
