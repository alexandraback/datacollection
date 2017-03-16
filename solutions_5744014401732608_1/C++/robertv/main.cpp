#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
ll B,M;
void decode(int k, int& x, int &y){
    x = 0; y = 0;
    while(x+k>B-1){
        k -= (B-x+1);
        x++;
    }
    y = x+k;
}
void solvesmall(int testi){
    scanf("%I64d%I64d",&B,&M);

    printf("Case #%d: ",testi);

    for(int i=0; i<1ll<<(B*(B-1)/2); i++){
        int x,y;
        bool A[100][100] = {0};
        for(int k=0; k<(B*(B-1)/2); k++){
            if (i & 1ll<<k){
                decode(k+1,x,y);
                A[x][y] = 1;
            }
        }

        int cnt[50] = {0};
        cnt[0] = 1;
        for(int i=0; i<B; i++){
            for(int j=0; j<B; j++){
                if (A[i][j])
                    cnt[j] += cnt[i];
            }
        }

        if (cnt[B-1]==M){
            printf("POSSIBLE\n");
            for(int i=0; i<B; i++)
            {
                for(int j=0; j<B; j++)
                {
                    if (A[i][j])
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n");
            }
            return;
        }
    }
    printf("IMPOSSIBLE\n");
}
void solve(int testi)
{
    scanf("%I64d%I64d",&B,&M);
    printf("Case #%d: ",testi);
    if (testi == 63){
       // printf("asdasd");
    }
    if (M < (1ll << (B-2)) )
    {
        printf("POSSIBLE\n");
        bool A[100][100] = {0};

        for(int i=0; i<B-2; i++)
        {
            for(int j=i+1; j<B-1; j++)
            {
                A[i][j] = 1;
            }
        }

        int k = 1;
        int maxk = 1;
        while(M)
        {
            if (M%2){
                A[k][B-1] = 1;
                maxk = max(maxk, k);
            }
            M /= 2;
            k++;
        }


        for(int i=0; i<B; i++)
        {
            for(int j=0; j<B; j++)
            {
                if (A[i][j] && ((i<=maxk && j<=maxk) || j==B-1) )
                    printf("1");
                else
                    printf("0");
            }
            printf("\n");
        }
    }
    else if (M == (1ll << (B-2) ))
    {
        printf("POSSIBLE\n");
        for(int i=0; i<B; i++)
        {
            for(int j=0; j<B; j++)
            {
                if (j>i)
                    printf("1");
                else
                    printf("0");
            }
            printf("\n");
        }
    }
    else
        printf("IMPOSSIBLE\n");

}

int main()
{
#ifdef LOCAL_PROJECT
    freopen("d:\\src\\CppProjects\\stdin","r",stdin);
    freopen("d:\\src\\CppProjects\\stdout","w",stdout);
#endif

    scanf("%d\n",&T);
    for(int i=1; i<=T; i++)
    {
        cerr << i << endl;
        solve(i);
    }
    return 0;
}
