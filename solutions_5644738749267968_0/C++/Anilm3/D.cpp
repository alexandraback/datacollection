#include <iostream>
#include <iomanip>
#include <deque>
#include <cfloat>
#include <algorithm>

int PlayWar(std::deque<double> & Naomi, std::deque<double> Ken)
{
    int points = 0;

    for (int i = 0; i < Naomi.size(); i++)
    {
        double KenSmallest = DBL_MAX;
        int KenSmallestIdx = -1;
        bool NaomiPoint = true;


        for (int j = 0; j < Ken.size(); j++)
        {
            if (Ken[j] < -1) continue;

            if (Ken[j] < KenSmallest)
            {
                KenSmallest = Ken[j];
                KenSmallestIdx = j;
            }

            if (Naomi[i] < Ken[j])
            {
                Ken[j] = -20;
                NaomiPoint = false;
                break;
            }
        }
        if (NaomiPoint)
        {

            Ken[KenSmallestIdx] = -20;
            ++points;
        }
    }

    return points;
}

int PlayDeceivingWar(std::deque<double> & Naomi, std::deque<double> Ken)
{
    int points = 0;

    for (int i = 0; i < Naomi.size(); i++)
    {
        double KenSmallest = DBL_MAX;
        int KenSmallestIdx = -1;
        bool NaomiPoint = true;

        if (Naomi[i] <= Ken[0])
        {
            Ken.pop_back();
        }
        else if (Naomi[i] > Ken[0])
        {
            Ken.pop_front();
            points++;
        }
    }

    return points;
}

int main()
{
    int T;

    std::cin >> T;


    for (int idx = 1; idx <= T; idx ++)
    {
        int N;
        std::deque<double> Blocks_Naomi, Blocks_Ken;

        std::cin >> N;

        for (int i = 0; i < N; i++)
        {
            double block;
            std::cin >> block;
            Blocks_Naomi.push_back(block);
        }

        for (int i = 0; i < N; i++)
        {
            double block;
            std::cin >> block;
            Blocks_Ken.push_back(block);
        }

        sort(Blocks_Naomi.begin(), Blocks_Naomi.end());
        sort(Blocks_Ken.begin(), Blocks_Ken.end());


        // for (int i = 0 ; i < Blocks_Naomi.size(); i++) std::cout << Blocks_Naomi[i] << " ";
        //     std::cout << std::endl;
        // for (int i = 0 ; i < Blocks_Ken.size(); i++) std::cout << Blocks_Ken[i] << " ";
        //     std::cout << std::endl;


        std::cout << "Case #" << idx << ": " 
                  << PlayDeceivingWar(Blocks_Naomi, Blocks_Ken) << " " 
                  << PlayWar(Blocks_Naomi, Blocks_Ken) << std::endl;
    }

    return 0;
}