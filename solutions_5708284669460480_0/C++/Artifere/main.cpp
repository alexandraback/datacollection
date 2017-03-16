#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
string letters, target;
char curWord[1000];
int K, L, S;

int nbWays;
int maxi;

int explore(int curSize, int curPos)
{
    if (curSize == S)
    {
  //      cout << curWord << "=>";
        int curNbWays = 0;
        for (int i1 = 0; i1 <= S-L; i1++)
        {
            int cpt = 0;
            while (curWord[i1+cpt] == target[cpt] && cpt < L)
            {
                cpt++;
            }

            if (cpt == L)
                curNbWays++;
        }
        maxi = max(maxi, curNbWays);
        nbWays += curNbWays;
      //  cout << curNbWays << endl;
    }

    else
    {
      //  cout << "lol" << endl;
        for (char c : letters)
        {
            curWord[curSize] = c;
            explore(curSize+1, curPos+1);
        }
    }
}

int main()
{

    freopen("small.in", "r", stdin);
    //freopen("small.out", "w", stdout);
    int nbT;

    cin >> nbT;
    //cout << nbT << endl;

    for (int t = 1; t <= nbT; t++)
    {
//cout << "li" << endl;
        cout << "Case #" << t << ": ";
        nbWays = 0;
        maxi = 0;
        cin >> K >> L >> S;
        cin >> letters >> target;
        curWord[S] = 0;

        explore(0, 0);
        std::cout << std::fixed;
        std::cout << std::setprecision(7);

        long double ans = (long double)(pow(K,S)*maxi-nbWays)/(long double)pow(K,S);

        cout << ans << '\n';
    }

    return 0;
}
