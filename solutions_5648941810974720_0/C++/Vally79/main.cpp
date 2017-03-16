#include <fstream>
#include <vector>
using namespace std;
ifstream ka("A-small-attempt0.in");
ofstream ki("ceva.out");
int t;
string s;
vector <string> numere;
int ap[31], sol[10];
int main()
{
    ka >> t;
    numere.push_back("ZERO");
    numere.push_back("ONE");
    numere.push_back("TWO");
    numere.push_back("THREE");
    numere.push_back("FOUR");
    numere.push_back("FIVE");
    numere.push_back("SIX");
    numere.push_back("SEVEN");
    numere.push_back("EIGHT");
    numere.push_back("NINE");
    ka.get();
    for(int i = 1; i <= t; i++)
    {
        getline(ka, s);
        for(char c = 'A'; c <= 'Z'; c++)
            ap[c - 'A'] = 0;
        for(int j = 0; j < s.size(); j++)
            ap[s[j] - 'A']++;
        for(int j = 0; j <= 8; j += 2)
        {
            int minim = 0x7fffffff;
            for(int k = 0; k < numere[j].size(); k++)
                if(ap[numere[j][k] - 'A'] < minim)
                    minim = ap[numere[j][k] - 'A'];
            for(int k = 0; k < numere[j].size(); k++)
                ap[numere[j][k] - 'A'] -= minim;
            sol[j] = minim;
        }
        for(int j = 1; j <= 7; j += 2)
        {
            int minim = 0x7fffffff;
            for(int k = 0; k < numere[j].size(); k++)
                if(ap[numere[j][k] - 'A'] < minim)
                    minim = ap[numere[j][k] - 'A'];
            for(int k = 0; k < numere[j].size(); k++)
                ap[numere[j][k] - 'A'] -= minim;
            sol[j] = minim;
        }
        int minim = 0x7fffffff;
        for(int k = 0; k < numere[9].size(); k++)
            if(ap[numere[9][k] - 'A'] < minim)
                minim = ap[numere[9][k] - 'A'];
        for(int k = 0; k < numere[9].size(); k++)
            ap[numere[9][k] - 'A'] -= minim;
        sol[9] = minim;
        ki << "Case #" << i << ": ";
        for(int j = 0; j <= 9; j++)
            if(sol[j])
            {
                for(int k = 1; k <= sol[j]; k++)
                    ki << j;
            }
        ki << '\n';
    }
}
