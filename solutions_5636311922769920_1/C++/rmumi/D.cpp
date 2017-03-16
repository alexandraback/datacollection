#include <bits/stdc++.h>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T;
    scanf("%d",&T);
    int k,c,s;
    for(int CASE=1;CASE<=T;CASE++)
    {
        scanf("%d %d %d",&k,&c,&s);
        int pot=((k-1)/c)+1;
        if (s<pot)
        {
            printf("Case #%d: IMPOSSIBLE\n",CASE);
        }
        else
        {
            printf("Case #%d:", CASE);
            for(int i=0;i<pot;i++)
            {
                int poc=i*c;
                uint64_t index=poc;
                for(int j=0;j<c-1;j++)
                {
                    index*=k;
                    poc=min(k-1,poc+1);
                    index+=poc;
                }
                cout<<" "<<index+1;
            }
            printf("\n");
        }
    }
    return 0;
}
