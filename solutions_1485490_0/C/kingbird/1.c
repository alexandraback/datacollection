#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef struct{
    unsigned long long num;
    int type;
}TOY,BOX;
TOY toy[MAX];
BOX box[MAX];
unsigned long long dp[MAX][MAX];
unsigned long long dfs(int x,int y)
{
    unsigned long long val = 0,temp;
    unsigned long long temp1,temp2,temp3;
    if(x<0||y<0)return 0;
    if(dp[x][y])return dp[x][y];
    temp = 0;
    if(box[x].type == toy[y].type)
    {
        temp = min(box[x].num,toy[y].num);
        box[x].num -= temp;
        toy[y].num -= temp;
    }
    temp1 = dfs(x-1,y) + temp;
    temp2 = dfs(x,y-1) + temp;
    temp3 = dfs(x-1,y-1) + temp;
    box[x].num += temp;
    toy[y].num += temp;
    val = max(temp1, temp2);
    val = max(temp3,val);
    return (dp[x][y] = val);
}
int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("output.txt","w",stdout);
    int cases,case_index;
    int i,j,n,m;
    unsigned long long cons;
    scanf("%d", &cases);
    for(case_index = 1; case_index <= cases; case_index++)
    {
        scanf("%d%d", &n,&m);
        memset(dp,0,sizeof(dp));
        for(i= 0;i<n;i++)
        {
            scanf("%I64u%d",&(box[i].num),&(box[i].type));
        }
        for(i= 0;i<m;i++)
        {
            scanf("%I64u%d",&(toy[i].num),&(toy[i].type));
        }
        cons = dfs(n-1,m-1);
        printf("Case #%d: %I64u\n", case_index,cons);
    }
    return 0;
}
