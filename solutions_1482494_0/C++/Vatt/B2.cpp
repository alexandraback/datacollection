#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int t;
int n,a[1005][2];
int mark[1100000][25];
int r;
int save[1100000][25];
int re(int bit,int star)
{
        if(mark[bit][star]==r) return save[bit][star];
        mark[bit][star]=r;
        if(star==2*n) { save[bit][star]=0; return 0; }
        save[bit][star]=100;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<2;j++)
                {
                        if(a[i][j]<=star)
                        {
                                int ch=((bit>>(2*i))&3);
                                if(ch>=j+1) continue;
                                //printf("%d %d CH %d %d\n",bit,star,bit-(ch<<(2*i))+((j+1)<<(2*i)),star+(j+1-ch));
                                //printf("%d %d %d %d %d %d %d %d\n",bit,star,i,j,ch,bit-(ch<<(2*i))+((j+1)<<(2*i)),star+(j+1-ch),re(bit-(ch<<(2*i))+((j+1)<<(2*i)),star+(j+1-ch))+1);
                                if(ch<j+1 && re(bit-(ch<<(2*i))+((j+1)<<(2*i)),star+(j+1-ch))+1<save[bit][star])
                                {
                                        save[bit][star]=re(bit-(ch<<(2*i))+((j+1)<<(2*i)),star+(j+1-ch))+1;
                                        //printf("CH\n");
                                }
                        }
                }
        }
        //printf("RET %d %d %d\n",bit,star,save[bit][star]);
        return save[bit][star];
}
int main()
{
        freopen("Bin.txt","r",stdin);
        freopen("Bout.txt","w",stdout);
        scanf("%d",&t);
        for(r=1;r<=t;r++) {
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                        scanf("%d %d",&a[i][0],&a[i][1]);
                }
                //printf("%d\n",re(0,0));              
                
                printf("Case #%d: ",r);  
                if(re(0,0)==100) {
                        printf("Too Bad\n");
                }
                else {
                        printf("%d\n",re(0,0));
                }
                // 
        }
        //system("pause");
}
