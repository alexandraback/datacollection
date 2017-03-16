#include<cstdio>
#include<algorithm>

using namespace std;

#define MAX_NUM 10
#define MAX_VALUE_NUM 101

class Coins
{
public:
    int Input()
    {
        scanf("%d %d %d", &C, &D, &V);
        for(int i=0; i<D; i++)
            scanf("%d", coins+i);

        sort(coins, coins+D);
        return 0;
    }
    int getMin()
    {
        for(int i=0; i<=V; i++)
            value[i] = false;

        value[0] = true;

        for(int i=0; i<D; i++)
        {
            for(int v = V; v >= coins[i]; v--)
            {
                if(value[v-coins[i]])
                {
                    value[v] = true;
                }
            }
        }

        int needCoins = 0;

        for(int v = 1; v<=V; v++)
        {
            if(!value[v])
            {
                needCoins++;

                int newCoin = v;
                for(int nv = V; nv >= newCoin; nv--)
                {
                    if(value[nv-newCoin])
                        value[nv] = true;
                }
            }
        }

        return needCoins;
    }
private:
    int coins[MAX_NUM];
    bool value[MAX_VALUE_NUM];
    int C, D, V;
};

int main(int argc, char* argv[])
{
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        Coins testObj;
        testObj.Input();

        printf("Case #%d: %d\n", i+1, testObj.getMin());

    }
    return 0;
}

