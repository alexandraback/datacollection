#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <string>

using namespace std;


int cpt[256];
char digits[20] = "0123456789\n";
int nbDigit[10];


int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);


    int nbT;
    cin >> nbT;



    for (int t = 1; t <= nbT; t++)
    {
        string s;
        for (int i = 0; i < 256; i++)
            cpt[i] = 0;
        for (int i = 0; i< 10; i++)
            nbDigit[i] = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            cpt[s[i]]++;

        nbDigit[0] = cpt['Z'];
        nbDigit[2] = cpt['W'];
        nbDigit[4] = cpt['U'];
        nbDigit[5] = cpt['F'] - nbDigit[4];
        nbDigit[6] = cpt['X'];
        nbDigit[7] = cpt['V']-nbDigit[5];
        nbDigit[1] = cpt['O']-nbDigit[0]-nbDigit[2]-nbDigit[4];
        nbDigit[8] = cpt['G'];
        nbDigit[3] = cpt['H']-nbDigit[8];
        nbDigit[9] = cpt['I']-nbDigit[6]-nbDigit[5]-nbDigit[8];

        string rep;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < nbDigit[i]; j++)
                rep.push_back(i+'0');
        }



        cout << "Case #" << t << ": " << rep << '\n';
    }


    return 0;
}
