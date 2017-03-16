#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
int J, P, S, K;
int XX[10];
void decode(int nr, int &j, int &p, int& s)
{
    j = nr % J;
    p = (nr-j)/J % P;
    s = nr /(P*J);
}
void solve3(int testi){
    scanf("%d%d%d%d",&J,&P,&S,&K);

    vector<int> sols;
    int histjp[10][10] = {0};
        int histjs[10][10] = {0};
        int histps[10][10] = {0};
        for(int j=0; j<J; j++){
            for(int s=0; s<S; s++){
                    for(int p=0; p<P; p++){
                            if (histjp[j][p]<K && histjs[j][s]<K && histps[p][s]<K){
                                 histjp[j][p]++;
                            histjs[j][s]++;
                                histps[p][s]++;
                                sols.push_back(j*100+p*10+s);
                            }
                    }
            }
        }
    printf("Case #%d: %d\n",testi, sols.size());
    for(int x : sols){
        printf("%d %d %d\n", x/100+1, (x/10)%10+1, x%10+1);
    }
   // printf("\n");
}
void solve2(int testi)
{
    scanf("%d%d%d%d",&J,&P,&S,&K);
    int nr = J*P*S;
    int sol = 0, soli = 0;
    for(int i=0; i<1ll<<nr; i++)
    {
        int histjp[10][10] = {0};
        int histjs[10][10] = {0};
        int histps[10][10] = {0};
        int pp = 0;
        for(int k=0; k<nr; k++)
        {
            if (1ll<<k & i)
            {
                int j,p,s;
                pp++;
                decode(k, j, p, s);
                histjp[j][p]++;
                histjs[j][s]++;
                histps[p][s]++;
            }
        }

        bool good = 1;
        for(int i=0; i<10 && good; i++)
        {
            for(int j=0; j<10 && good; j++)
            {
                if (histjp[i][j] > K || histjs[i][j] > K || histps[i][j] > K)
                    good = 0;
            }
        }

        if (good && pp>sol)
        {
            sol = pp;
            soli = i;
        }
    }
    printf("Case #%d: %d\n",testi, sol);
    for(int k=0; k<nr; k++)
    {
        if (1ll<<k & soli)
        {
            int j,p,s;
            decode(k,j,p,s);
            printf("%d %d %d\n",j+1,p+1,s+1);
        }
    }


}
void solvesmall(int testi)
{
    scanf("%d%d%d%d",&J,&P,&S,&K);

    int nr = J*P*S;

    int X[10];
    for(int k=0; k<nr; k++)
        X[k] = -1;

    int sol = 0;
    int k = 0;
    while(k>=0)
    {
        while(X[k]<nr-1)
        {
            X[k]++;
            bool good = 1;
            for(int i=0; i<k && good; i++)
                if (X[i]==X[k])
                    good = 0;
            if (!good)
                continue;

            if (k==nr-1)
            {
                int histjp[10][10] = {0};
                int histjs[10][10] = {0};
                int histps[10][10] = {0};
                int i=0;
                for(i=0; i<=k; i++)
                {
                    int j, p, s;
                    decode(X[i], j, p, s);
                    histjp[j][p]++;
                    histjs[j][s]++;
                    histps[p][s]++;
                    if (histjp[j][p]>K || histjs[j][s]>K || histps[p][s]>K)
                    {
                        break;
                        i--;
                    }
                }
                if (i>sol)
                {
                    sol = i;
                    memcpy(XX, X, 10*4);
                }
            }
            else
            {
                k++;
                X[k]=-1;
            }
        }
        X[k] = -1;
        k--;
    }
    printf("Case #%d: %d\n",testi, sol);
    for(int i=0; i<sol; i++)
    {
        int j,p,s;
        decode(XX[i],j,p,s);
        printf("%d %d %d\n",j+1,p+1,s+1);
    }
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
        solve3(i);
    }
    return 0;
}
