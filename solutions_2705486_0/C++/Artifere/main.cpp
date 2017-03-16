#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>


using namespace std;


string dico[521196];
int dyn[4000];
string code;
const int nbMots = 521196;
int S;



bool check(string toCheck, int pos)
{
    if (pos+toCheck.size() > S)
        return false;


    for (int i = 0; i < toCheck.size(); i++)
    {
        if (toCheck[i]!=code[pos+i])
        {
            if (abs(toCheck[i] - code[pos+i]) < 5)
                return false;
        }
    }
    return true;
}

inline int nbDiff(string toCheck, int pos)
{
    int nbDiff=0;
    for (int i = 0; i < toCheck.size(); i++)
    {
        if (toCheck[i]!=code[pos+i])
        {
            nbDiff++;
        }
    }
    return nbDiff;
}




int rec(int pos)
{
    if (pos > S)
        return 1000000;

    if (dyn[pos] == -1)
    {
        dyn[pos] = 1000000;
        //dyn[pos] = 1000000;
        for(int i = 0; i < nbMots; i++)
        {
            if (check(dico[i], pos))
                dyn[pos] = min(dyn[pos], nbDiff(dico[i], pos)+rec(pos+dico[i].size()));
        }
    }

    return dyn[pos];
}



int main()
{
    freopen("small.out", "w", stdout);
    freopen("dicto.txt", "r", stdin);



    int t = 1, nbT;
    for (int i = 0; i < nbMots; i++)
    {
        cin >> dico[i];
    }



    freopen("small.in", "r", stdin);

    cin >> nbT;
    while (t <= nbT)
    {
        cin >> code;
        S = code.size();
        for (int i = 0; i < S; i++)
            dyn[i] = -1;
        dyn[S] = 0;


        cout << "Case #" << t << ": " << rec(0) << "\n";
        t++;
    }






    return 0;
}
