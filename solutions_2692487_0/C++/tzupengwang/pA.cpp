#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int st,num;
int a[1000];
int b[1000];

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int amm,cnt=0;
    scanf("%d",&amm);
    while (amm--)
    {
        cnt++;
        scanf("%d%d",&st,&num);
        for (int i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+num);

        if (st==1)
        {
            printf("Case #%d: %d\n",cnt,num);
            continue;
        }
        int temp=st;
        memset(b,-1,sizeof b);
        for (int i=0;i<num;i++)
        {
            while (temp<=a[i])
            {
                temp+=(temp-1);
                b[i]++;
            }
            temp+=a[i];
        }
        int ans=num;
        temp=num;
        for (int i=0;i<num;i++)
        {
            temp+=b[i];
            if (temp<ans)ans=temp;
        }
        printf("Case #%d: %d\n",cnt,ans);
    }


    return 0;
}
