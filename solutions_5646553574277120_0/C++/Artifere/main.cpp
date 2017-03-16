#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
string letters, target;
vector<int> coinList;
bool exists[31];
int C, D, V;
int bestMin;
vector<int> curNbs(50);


void explore(int nbPris, int curPos)
{
    if (nbPris >= bestMin)
        return;
    if (curPos == V)
    {
        //      cout << curWord << "=>";
        bool isOk = true;
        int last = 0;
        int idExist = 0;
       // curNbs[nbPris] = 10000000;
        //  cout << "aa" << last << "====>";
        for (int i = 0; i < nbPris; i++)
        {
            // cout << last << "=>";
            while (coinList[idExist] <= last+1)
            {
                last = max(last, 2*coinList[idExist]-1);
                //  cout << last << "a=>";
                idExist++;
            }
            if (curNbs[i] <= last+1)
            {

                last = max(last, 2*curNbs[i]-1);


            }



        }
        while (coinList[idExist] <= last+1)
        {
            last = max(last, 2*coinList[idExist]-1);
            // cout << last << "t=>";
            idExist++;
        }
         /*cout << last << "VVVSSS" << V;
         cout << endl;*/

        if (last >= V)
        {
            bestMin = min(bestMin, nbPris);
            //exit(0);
        }


    }

    else
    {
        explore(nbPris, curPos+1);
        curNbs[nbPris] = curPos;
        explore(nbPris+1, curPos+1);
        //curNbs.pop_back();
    }
}

int main()
{

    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int nbT;

    cin >> nbT;
    //cout << nbT << endl;

    for (int t = 1; t <= nbT; t++)
    {
//cout << "li" << endl;
        cout << "Case #" << t << ": ";
        cin >> C >> D >> V;
        // cout << C << ' ' << D << ' ' << V << "uuuu" << endl;
        for (int i = 0; i <= V; i++)
        {
            exists[i] = false;
        }

        coinList.resize(D);
        for (int i = 0; i < D; i++)
            cin >> coinList[i];

        coinList.push_back(10000000);

        sort(coinList.begin(), coinList.end());





        bestMin = V;

        explore(0, 1);

        cout << bestMin << '\n';
    }

    return 0;
}
