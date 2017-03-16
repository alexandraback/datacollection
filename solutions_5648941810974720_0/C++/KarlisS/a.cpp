#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

string digits[]={
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

struct Desc {
    int i;
    char c;
    int n;
};

Desc desc[10]= {
    {0, 'Z', 1},
    {2, 'W', 1},
    {4, 'U', 1},
    {6, 'X', 1},
    {8, 'G', 1},
    {7, 'S', 1},
    {5, 'V', 1},
    {3, 'T', 1},
    {9, 'I', 1},
    {1, 'O', 1},
};
int main()
{
    map<char, int> cnt[10];
    int i=0;
    for (auto& digit : digits)
    {
        for (auto c : digit)
        {
            cnt[i][c]++;
        }
        i++;
    }
    /*for (int i=0; i<10; i++)
    {
        cout << i << " ";
        for (auto it : cnt[i])
        {
            cout << it.first << " "<< it.second << " "  ;
        }
        cout << "\n";
    }*/

    int t;
    cin >> t;
    for (i=1; i<=t; i++)
    {
        string line;
        cin >> line;
        int dig[128]={0};
        for (char c : line) dig[(int)c]++;
        int cntAns[10] = {0};
        for (auto descr : desc) {
            //cout << descr.i << " ";
            //for (int j=0; j<128; j++) if (dig[j]) cout << (char(j)) << " " << dig[j] << " " ;
            //cout << "\n";
            cntAns[descr.i] = dig[(int)descr.c] / descr.n;
            for (auto it : cnt[descr.i]) dig[(int)it.first] -= cntAns[descr.i] * it.second;
        }
        cout << "Case #" << i << ": ";
        for (int j=0; j<10; j++) {
            for (int k=0; k<cntAns[j]; k++) cout << j;
        }
        cout << "\n";
    }
}
