#include <bits/stdc++.h>

using namespace std;

const int nmax = 2009;

vector < int > solution;
string er;
int cnt[nmax];
int tests , T , i;

int main()
{
freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

cin >> tests;

for (T = 1 ; T <= tests ; ++T)
{
    cin >> er;
    solution.clear();

    for (i = 0 ; i < er.size() ; ++i)
    cnt[er[i]]++;

    while (cnt['Z'])
    {
        solution.push_back(0);
        cnt['Z']--;
        cnt['E']--;
        cnt['R']--;
        cnt['O']--;
    }

    while (cnt['W'])
    {
        solution.push_back(2);
        cnt['T']--;
        cnt['W']--;
        cnt['O']--;
    }

    while (cnt['U'])
    {
        solution.push_back(4);
        cnt['F']--;
        cnt['O']--;
        cnt['U']--;
        cnt['R']--;
    }

    while (cnt['X'])
    {
        solution.push_back(6);
        cnt['S']--;
        cnt['I']--;
        cnt['X']--;
    }

    while (cnt['G'])
    {
        solution.push_back(8);
        cnt['E']--;
        cnt['I']--;
        cnt['G']--;
        cnt['H']--;
        cnt['T']--;
    }

    while (cnt['F'])
    {
        solution.push_back(5);
        cnt['F']--;
        cnt['I']--;
        cnt['V']--;
        cnt['E']--;
    }

    while (cnt['O'])
    {
        solution.push_back(1);
        cnt['O']--;
        cnt['N']--;
        cnt['E']--;
    }

    while (cnt['S'])
    {
        solution.push_back(7);
        cnt['S']--;
        cnt['E']--;
        cnt['V']--;
        cnt['E']--;
        cnt['N']--;
    }

    while (cnt['H'])
    {
        solution.push_back(3);
        cnt['T']--;
        cnt['H']--;
        cnt['R']--;
        cnt['E']--;
        cnt['E']--;
    }

    while (cnt['I'])
    {
        solution.push_back(9);
        cnt['N']--;
        cnt['I']--;
        cnt['N']--;
        cnt['E']--;
    }

    sort(solution.begin() , solution.end());

    cout << "Case #" << T << ": ";

    for (i = 0 ; i < solution.size() ; ++i)
    cout << solution[i];

    cout << '\n';
}

return 0;
}
