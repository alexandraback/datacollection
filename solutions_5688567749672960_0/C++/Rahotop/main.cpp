#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int reverseInt(int a)
{
    if(a%10 == 0)
        return a;

    int tmp(0);

    while(a != 0)
    {
        tmp *= 10;
        tmp += a%10;
        a -= a%10;
        a /=10;
    }

    return tmp;
}

void test(int nbTR, int nbSaid, int actualNb, int *minusR, vector<int> *res)
{
    if(actualNb == nbTR)
    {
        (*res).push_back(nbSaid + 1);
        if((nbSaid+1) < *minusR)
            *minusR = nbSaid+1;
    }
    else if((nbSaid+1) < *minusR)
    {
        int tmp = reverseInt(actualNb);
        if(tmp > actualNb && tmp <= nbTR)
            test(nbTR, nbSaid+1, reverseInt(actualNb), minusR, res);
        else
            test(nbTR, nbSaid+1, actualNb+1, minusR, res);
    }
}

int main()
{
    ifstream input("input.txt", ios::in);
    ofstream output("output.txt", ios::out | ios::trunc);

    if(input && output)
    {
        int nbTest;

        input >> nbTest;

        for(int i(1); i <= nbTest; i++)
        {
            int nbToReach;

            input >> nbToReach;


            vector<int> r;
            int minR = nbToReach;
            test(nbToReach, 0, 1, &minR, &r);

            int res = nbToReach;
            for(int j(0); j < r.size(); j++)
               if(r[j] < res)
                res = r[j];

            cout << "Case #" << i << ": " << res << endl;
            output << "Case #" << i << ": " << res << endl;
        }
    }


    return 0;
}
