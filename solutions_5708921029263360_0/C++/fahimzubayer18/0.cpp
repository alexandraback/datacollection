#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A,B,C,N;

int cnt[3][4][4];
int ans[30][3];

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t,n;



    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);

        scanf("%d %d %d %d",&A,&B,&C,&N);

        if(N>=3)
        {
            printf("%d\n",A*B*C);
            for(a=1;a<=A;a++)
            {
                for(b=1;b<=B;b++)
                {
                    for(c=1;c<=C;c++)
                    {
                        printf("%d %d %d\n",a,b,c);
                    }
                }
            }
            continue;
        }

        for(a=0;a<3;a++)
        {
            for(b=1;b<=3;b++)
            {
                for(c=1;c<=3;c++) cnt[a][b][c]=0;
            }
        }

        z=0;

        for(a=1;a<=A;a++)
        {
            for(b=1;b<=B;b++)
            {
                for(c=1;c<=C;c++)
                {
                    if(cnt[0][a][b]<N && cnt[1][a][c]<N && cnt[2][b][c]<N)
                    {
                        ans[z][0]=a;
                        ans[z][1]=b;
                        ans[z][2]=c;
                        z++;
                        cnt[0][a][b]++;
                        cnt[1][a][c]++;
                        cnt[2][b][c]++;
                    }
                }
            }
        }

        cout<<z<<endl;

        for(a=0;a<z;a++) cout<<ans[a][0]<<" "<<ans[a][1]<<" "<<ans[a][2]<<endl;

    }


    return 0;
}
