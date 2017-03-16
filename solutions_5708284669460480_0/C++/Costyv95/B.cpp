#include <cstdio>
#include <algorithm>
using namespace std;

char a[100],b[100];

int st[8];
int k,l,s,T;
int mxb,sumb;

void verif()
{
    int i,j,w,sum=0,cnt;

    for (i=1;i<=s;i++)
    {
        cnt = 0;
        for (j=i,w=0;j<=s && w<l && a[st[j]] == b[w];cnt++,j++,w++);
        if (cnt == l) sum++;
    }

    mxb = max(mxb,sum);
    sumb += sum;
}



int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char c;

    scanf("%d",&T);

    for (int q=1;q<=T;q++)
    {
        scanf("%d%d%d",&k,&l,&s);

        scanf("%c",&c);
        scanf("%s",a);

        scanf("%c",&c);
        scanf("%s",b);

        int ind = 1;
        st[ind] = -1;

        mxb = 0; sumb = 0;

        while (ind>0)
        {
            if (st[ind]<k-1)
            {
                st[ind]++;

                if (ind == s)
                {
                    verif();
                }
                else
                    st[++ind] = -1;
            }
            else
                ind--;
        }

        double res = sumb;
        for (int i=1;i<=s;i++)
            res = (double)res/k;

        printf("Case #%d: %lf\n",q,(double)mxb-res);
    }

    return 0;
}
