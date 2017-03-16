#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxms = 1024*1024;
const int maxn = 20;

int a[maxn];
int m[maxn];
int main(){
#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        int n,v,i,j;

        int t;
        scanf("%d",&t);
        for(int I=1;I<=t;I++){
            scanf("%d",&n);
            for(i=0;i<n;i++)
                scanf("%d",a+i);

            int mask,ms=0;
            int r;
            bool p=0;
            printf("Case #%d:\n",I);
            for(ms=0;ms<maxms && !p;ms++){
                mask=ms;
                r=0;
                for(i=0;i<n;i++,mask>>=1)
                    if(mask&1)
                        m[r++]=a[i];
                int k=1<<r;
                int sum=0;
                for(int ms2=0;ms2<k && !p;ms2++){
                    sum=0;
                    for(mask=ms2,j=0;j<r;mask>>=1,j++)
                        sum+=m[j]*((mask&1)==0 ? 1 : -1);
                    if(sum==0 && r){
                        for(mask=ms2,j=0;j<r;mask>>=1,j++)
                           if(mask&1)
                               printf("%d ",m[j]);
                        putchar('\n');
                        for(mask=ms2,j=0;j<r;mask>>=1,j++)
                           if(!(mask&1))
                               printf("%d ",m[j]);
                        putchar('\n');
                        p=1;
                    }
                }
            }
            if(!p)
                puts("Impossible");
        }
}

