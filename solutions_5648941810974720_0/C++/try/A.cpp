#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const char digs[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
const int lens[10]={4,3,4,3,5,5,4,5,3,4};
const char keys[11]="ZWUXGRFVOI";
const char ords[11]="0246835719";
int cnt[1<<8],ans[11];
char str[1<<11];
int n;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int c,t,i,j,k,l;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++)
        {
            cnt[str[i]]++;
        }
        memset(ans,0,sizeof(ans));
        for(i=0;i<10;i++)
        {
            l=(int)(ords[i]-'0');
            ans[l]=cnt[keys[i]];
            for(j=0;j<lens[i];j++)
            {
                for(k=0;k<ans[l];k++)
                {
                    cnt[digs[l][j]]--;
                }
            }
        }
        printf("Case #%d: ",c+1);
        for(i=0;i<10;i++)
        {
            for(j=0;j<ans[i];j++)
            {
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
