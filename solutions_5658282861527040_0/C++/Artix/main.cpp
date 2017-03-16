#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int A,B,K;
int dyn[32][2][2][2];

void reset()
{
    for(int i = 0; i < 32; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                    dyn[i][j][k][l]=0;
}

int getDig(int nb, int pos)
{
    while(pos > 0)
    {
        nb/=2;
        pos--;
    }
    return nb%2;
}

int howMany(int pos, int smThanA, int smThanB, int smThanK)
{
    if(pos==-1)
        return smThanA && smThanB && smThanK;
    int& vc = dyn[pos][smThanA][smThanB][smThanK];

    if(!vc)
    {
        for(int digA = 0; digA <= 1; digA++)
        {
            for(int digB= 0; digB <= 1; digB++)
            {
                int digK=digA&digB;

                if((!smThanA && digA > getDig(A, pos)) || (!smThanB && digB > getDig(B,pos)) || (!smThanK && digK > getDig(K, pos)))
                    continue;

                vc += howMany(pos-1, smThanA || (digA < getDig(A, pos)), smThanB || (digB < getDig(B,pos)), smThanK || (digK < getDig(K, pos)));
            }
            //if((!smThanA && dig > getDig(A, pos)) || (!smThanB && dig > getDig(B,pos)) || (!smThanK && dig > getDig(K, pos)))
            //    break;
            //vc += howMany(pos-1, smThanA || (dig < getDig(A, pos)), smThanB || (dig < getDig(B,pos)), smThanK || (dig < getDig(K, pos)));
        }
    }

    return vc;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d%d",&A,&B,&K);

        reset();
        printf("Case #%d: %d\n", t, howMany(31,0,0,0));
    }

    return 0;
}
