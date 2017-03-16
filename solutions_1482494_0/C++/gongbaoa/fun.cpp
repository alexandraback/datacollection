#include<cstdio>
#include<cstring>
bool conq[1000][2];
int a[1000][2];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int n;
        scanf("%d",&n);
        memset(conq,0,sizeof(conq));
        for (int i=0; i<n; i++)
            scanf("%d%d",&a[i][0],&a[i][1]);
        int star=0,ans=0;
        while (1)
        {
            bool flag=0;
            for (int i=0; i<n; i++)
                if (!conq[i][1] && a[i][1]<=star)
                {
                    ans++;
                    star+=2-conq[i][0];
                    conq[i][0]=conq[i][1]=1;
                    flag=1;
                    break;
                }
            if (flag)
                continue;
            int maxi=-1,idx=-1;
            for (int i=0; i<n; i++)
                if (!conq[i][0] && a[i][0]<=star && a[i][1]>maxi)
                {
                    idx=i;
                    maxi=a[i][1];
                    flag=1;
                }
            if (!flag)
                break;
            star++;
            conq[idx][0]=1;
            ans++;
        }
        bool flag=1;
        for (int i=0; i<n && flag; i++)
            flag=conq[i][1];
        printf("Case #%d: ",cas);
        if (!flag)
            puts("Too Bad");
        else
            printf("%d\n",ans);
    }
    return 0;
}
