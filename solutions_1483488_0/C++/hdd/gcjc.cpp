#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<memory.h>
using namespace std;
int rec[105];
int snum[10];
int n;
void movetoend(int s)
{
    int num[10];
    n = 0;
    num[n++] = s%10;
    while(s/=10)
    {
        num[n++] = s%10;
    }
    for(int i=0; i<n; i++)
    {
        snum[i] = num[n-i-1];
    }
}

int main()
{
    int cas;
    freopen("C-small-attempt4.in","r",stdin);
    freopen("hdd.txt","w",stdout);
    scanf("%d",&cas);
    int A,B,ans,sum;
    int tp[10];
    for(int icas=1; icas<=cas; icas++)
    {
        map<string,bool>myMap;
        scanf("%d%d",&A,&B);
        ans = 0;
        for(int i=A; i<=B; i++)
        {
            //if(i<10)continue;
            movetoend(i);
            for(int j=1; j<n; j++)
            {
                for(int k=0; k<n; k++) tp[k] = snum[(k+j)%n];
                sum = 0;
                for(int k=0; k<n; k++) sum = sum*10+tp[k];
                if(sum>i&&sum<=B)
                {

                    char xxx[20];
                    sprintf(xxx,"%d$%d",i,sum);
                    string str = xxx;
                    if(!myMap[str])
                    {
                        ans++;
                        myMap[str] = 1;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",icas,ans);
    }

}
