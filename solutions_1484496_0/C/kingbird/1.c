#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000001
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int set[22];
int state[22];
int cons[MAX];
int find,n,flag;
void dfs(int lv,int sum)
{
    if(lv >= n || find)return;
    //printf("%d %d\n",lv,sum);
    if(sum && cons[sum] >= 2)
    {
        find = sum;
        return;
    }
    cons[sum+set[lv]]++;
    if(cons[sum+set[lv]] >= 2)
    {
        find = sum+set[lv];
        return;
    }
    if(!find)dfs(lv+1,sum);
    if(!find)dfs(lv+1,sum+set[lv]);
}
void search(int lv,int sum)
{
    int i,j;
    if(sum < 0 || lv >= n || flag>=2) return;
    if(sum == 0)
    {
        j = 0;
        for(i = 0; i< n;i++)
        {
            if(state[i] == 1)
            {
                if(j!=0)printf(" ");
                j = 1;
                printf("%d",set[i]);
            }
        }
        printf("\n");
        flag++;
        return;
    }
    if(flag<2 && state[lv] == 0 && set[lv]){
        state[lv] = 1;
        search(lv+1,sum-set[lv]);
    }
    if(flag<2 && state[lv] == 1)
    {
        state[lv] = 0;
        search(lv+1,sum);
    }
    return;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int cases,case_index;
    int i;
    scanf("%d", &cases);
    for(case_index = 1; case_index <= cases; case_index++)
    {
        scanf("%d", &n);
        for(i = 0; i< n; i++)
        {
            scanf("%d", &set[i]);
        }
        memset(cons,0,sizeof(cons));
        find = 0;
        dfs(0,0);
        //printf("%d",find);
        printf("Case #%d:\n", case_index);
        memset(state,0,sizeof(state));
        flag = 0;
        search(0,find);
    }
    return 0;
}
