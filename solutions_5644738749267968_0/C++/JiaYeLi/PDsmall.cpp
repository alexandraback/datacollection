#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>

using namespace std;

int PlayDW(double naomi[], double ken[],int N)
{
    int k_max_i = N-1;
    int k_min_i = 0;
    int naomi_point = 0;
    for(int i=0; i<N; i++)
    {
        if(ken[k_min_i]<naomi[i])//送敦
        {
            k_min_i++;
            naomi_point++;
        }
        else//耍笨 浪費大牌
        {
            k_max_i--;
        }

    }
    return naomi_point;
}

int PlayWar(double naomi[], double ken[],int N)
{
    map<double,int> bst_ken;
    for(int i=0; i<N; i++)
    {
        std::map<double, int>:: iterator it;
        it = bst_ken.find(ken[i]);
        if(it==bst_ken.end())
        {
            bst_ken[ken[i]]=1;
        }
        else//怕重複
        {
            it->second++;
        }
    }

    int ken_min_i = 0;
    int naomi_point = 0;
    for(int i=0; i<N; i++)
    {
        const double choseNaomi = naomi[i];
        std::map<double, int>:: iterator it;
        //upper bound
        it = bst_ken.upper_bound(choseNaomi);

        if(it==bst_ken.end())//全部都小 upper bound不存在  出小牌
        {



            naomi_point++;
            //刪除

            it = bst_ken.find(ken[ken_min_i]);
            if(it->second==1)
            {
                bst_ken.erase(it);
            }
            else
            {
                it->second--;
            }

            ken_min_i++;
        }
        else
        {//Ken吃點點
            if(it->second==1)
            {
                bst_ken.erase(it);
            }
            else
            {
                it->second--;
            }
        }
    }

    return naomi_point;
}

int main()
{
    int T;

    cin >> T;
    for(int c=0; c<T; c++)
    {
        int N=1;

        cin >> N;

        double blockNaomi[N];
        for(int i=0; i<N; i++)
            cin >> blockNaomi[i];

        double blockKen[N];
        for(int i=0; i<N; i++)
            cin >> blockKen[i];

        sort(blockNaomi, blockNaomi+N);
        sort(blockKen, blockKen+N);

        int DW_p = PlayDW(blockNaomi, blockKen, N);
        int War_p = PlayWar(blockNaomi, blockKen, N);

        printf("Case #%d: %d %d\n", c+1, DW_p, War_p);
    }

    return 0;
}
