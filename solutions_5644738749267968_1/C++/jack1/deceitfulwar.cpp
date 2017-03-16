#include <iostream>
#include <list>
#include <algorithm>

std::list<double> read_list(int n)
{
    std::list<double> result;
    for (int i = 0; i < n; i++)
    {
        double val;
        std::cin >> val;
        result.push_back(val);
    }
    return result;
}

template<typename List>
void print_list(const List& list)
{
    for (auto elem : list)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int compute_war(std::list<double> naomi, std::list<double> ken)
{
    const int n = naomi.size();
    naomi.sort();
    ken.sort();
    
    //debug
    //print_list(naomi);
    //print_list(ken);
    
    int score_war = 0;
    
    for (int i = 0; i < n; i++)
    {
        // Naomi plays her worst stone
        const double naomi_worst = naomi.back();
        const double ken_best = ken.back();
        naomi.pop_back();
        if (ken_best < naomi_worst)
        {
            // Ken has lost this round
            score_war++;
            ken.pop_front();
        }
        else
        {
            // Ken tries to find the lowest better
            for (auto it = ken.begin(); it != ken.end(); ++it)
            {
                if (*it > naomi_worst)
                {
                    ken.erase(it);
                    break;
                }
            }
        }
        //debug
        //print_list(naomi);
        //print_list(ken);
    }
    
    return score_war;
}

int compute_deceitful(std::list<double> naomi, std::list<double> ken)
{

    const int n = naomi.size();
    naomi.sort();
    ken.sort();
    
    //debug
    //print_list(naomi);
    //print_list(ken);
    
    int score_deceitful = 0;
    
    for (int i = 0; i < n; i++)
    {
        const double ken_worst = ken.front();

        bool success = false;
        
        // Naomi tries to sacrifice something that is just better than Ken's worst
        for (auto it = naomi.begin(); it != naomi.end(); ++it)
        {
            if (*it > ken_worst)
            {
                naomi.erase(it);
                success = true;
                break;
            }
        }
        
        if (success) // Naomi tells Ken she has a huge stone...
        {
            score_deceitful++;
            // Ken uses its worst
            ken.pop_front();
        }
        else // Naomi can't beat Ken's worst, but she will play her worst and tell Ken she has a very large stone so he will play his best
        {
            naomi.pop_front();
            ken.pop_back();
        }
        
        //debug
        //print_list(naomi);
        //print_list(ken);

    }
    
    return score_deceitful;
}

int main()
{

    int no_test_cases;
    std::cin >> no_test_cases;
    
    //debug
    //std::cout << no_test_cases << std::endl;
    
    for (int i = 1; i <= no_test_cases; i++)
    {
        int no_stones;
        std::cin >> no_stones;
        
        //debug
        //std::cout << no_stones << std::endl;
        
        std::list<double> naomi = read_list(no_stones);
        std::list<double> ken = read_list(no_stones);
        
        //debug
        //print_list(naomi);
        //print_list(ken);
        
        int score_deceitful, score_war;
        std::cout << "Case #" << i << ": " << compute_deceitful(naomi, ken) << " " << compute_war(naomi, ken) << std::endl;
    }
    
    return 0;
    
}
