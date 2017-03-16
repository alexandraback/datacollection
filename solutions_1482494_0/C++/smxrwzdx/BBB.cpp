#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int a,b;
    bool jud,ju;
}K[100010];
int N;
bool bcmp(node a,node b){if(a.b==b.b) return a.a>b.a;return a.b<b.b;}
int main()
{
    freopen("B.in","r",stdin);
    freopen("BB.out","w",stdout);
    int i,j,k;
    int a,b,s;
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {tt++;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d%d",&K[i].a,&K[i].b);
            K[i].jud=false;K[i].ju=false;
        }
        sort(K,K+N,bcmp);
        s=0;int t=0;
        for(i=0;i<N;i++)
        {
            if(s>=K[i].b)
            {
                if(!K[i].jud) s+=2;
                else s+=1;
                K[i].ju=true;
                t++;
            }
            else
            {
                while(s<K[i].b)
                {
                    for(j=N-1;j>=i;j--)
                    {
                        if(!K[j].jud&&s>=K[j].a)
                        {
                            s++;K[j].jud=true;t++;break;
                        }
                    }
                    if(j<i) break;
                }
                if(s>=K[i].b)
                {
                    if(!K[i].jud) s+=2;
                    else s+=1;
                    t++;
                }
                else break;
            }
        }
        if(i==N) printf("Case #%d: %d\n",tt,t);
        else printf("Case #%d: Too Bad\n",tt);
    }
    return 0;
}
