#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int t;
int nowstar;
int n,a[1005][2];
int already[1005];
int maxx,p1,p2;
bool mark,mark2;
int nub,p;
int main()
{
        freopen("Bin.txt","r",stdin);
        freopen("Bout.txt","w",stdout);
        scanf("%d",&t);
        int r;
        for(r=1;r<=t;r++) {
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                        scanf("%d %d",&a[i][0],&a[i][1]);
                       // printf("%d %d\n",a[i][0],a[i][1]);
                        already[i]=0;
                }
                nowstar=0;
                mark=0;
                nub=0;
                while(nowstar!=2*n)
                {
                       // printf("%d\n",nub);
                        mark2=0;
                        for(int i=0;i<n;i++)
                        {
                                //printf("CH 1 %d %d %d\n",i,already[i],a[i][1]);
                                if(already[i]!=2 && nowstar>=a[i][1])
                                {
                                        //printf("1 %d %d\n",nowstar,i);
                                        nowstar+=2-already[i];
                                        already[i]=2;
                                        mark2=1;
                                        break;
                                }
                        }
                        if(!mark2)
                        {
                                maxx=-1;
                                p=0;
                                for(int i=0;i<n;i++)
                                {
                                        if(already[i]==0 && nowstar>=a[i][0])
                                        {
                                                if(maxx<a[i][1])
                                                {
                                                        maxx=a[i][1];
                                                        p=i;
                                                }
                                        }
                                }
                                if(maxx!=-1)
                                {
                                        nowstar++;
                                        already[p]=1;
                                        mark2=1;
                                }       
                        }
                        if(!mark2)
                        {
                                mark=1;
                                break;
                        }
                        nub++;
                        //system("pause");
                }
                
                printf("Case #%d: ",r);  
                if(mark) {
                        printf("Too Bad\n");
                }
                else {
                        printf("%d\n",nub);
                }
                
                //if(r==10) system("pause");
                // 
        }
        //system("pause");
}
