#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;

vector<float>::iterator kenchoice(vector<float>* ken, float naomi)
{
    vector<float>::iterator it;
    for(it=ken->begin();it!=ken->end()&&*it<naomi;it++) {}
    if(it==ken->end())
    {
        it--;
    }
    return it;
}

bool naomichoice(vector<float>* ken, vector<float>* naomi)
{
    vector<float>::iterator it1, it2;

    it1 = ken->end()-1;
    it2 = naomi->end()-1;
    bool return_ = false;
    if(*it1<*it2)
    {
        return_=true;
    }
    else
    {
        it2 = naomi->begin();
    }
    ken->erase(it1);
    naomi->erase(it2);

    return return_;
}

void war()
{
    int nb_case;
    cin >> nb_case;

    int nb_block;

    vector<float> naomi, naomi2;
    vector<float> ken, ken2;

    float tmp;

    vector<float>::iterator choice;

    int score1, score2;
    for(int i=0; i<nb_case; i++)
    {
        naomi.clear();
        ken.clear();
        cin >> nb_block;

        for(int j=0;j<nb_block;j++)
        {
            cin >> tmp;
            naomi.push_back(tmp);
        }

        for(int j=0;j<nb_block;j++)
        {
            cin >> tmp;
            ken.push_back(tmp);
        }

        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());

        ken2 = ken;
        naomi2 = naomi;

        score1 = 0;
        score2 = 0;

        for(int j=0;j<nb_block;j++)
        {
            choice = kenchoice(&ken, *naomi.begin());
            if(*choice<*naomi.begin())
            {
                score1++;
            }
            ken.erase(choice);
            naomi.erase(naomi.begin());
        }

        for(int j=0;j<nb_block;j++)
        {
            if(naomichoice(&ken2, &naomi2))
            {
                   score2++;
            }
        }
        cout << "Case #" << i+1 << ": " << score2 << " " << score1 << "\n";

    }
}

int main()
{
    war();
    return 0;
}

