#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;

int kol[256] = {};
int phone[10] = {};
string number[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void remove_number(int n)
{
    for(int i = 0; i < number[n].size(); ++i)
    {
        --kol[number[n][i]];
    }
}

int order[10] = {0, 6, 8, 2, 7, 5, 4, 3, 1, 9};
int main_char[10] = {'Z', 'X', 'G', 'W', 'S', 'V', 'F', 'R', 'O', 'E'};


int main()
{
    ifstream f1("A-small-attempt0(2).in");
    ofstream f2("A-small-attempt0(2).out");
    int T;
    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ": ";
        memset(kol, 0, sizeof kol);
        memset(phone, 0, sizeof phone);
        string s;
        f1 >> s;
        for(int i = 0; i < s.size(); ++i)
        {
            ++kol[s[i]];
        }
        for(int i = 0; i < 10; ++i)
        {
            while(kol[main_char[i]])
            {
                remove_number(order[i]);
                ++phone[order[i]];
            }
        }
        for(int i = 0; i < 10; ++i)
            for(int j = 0; j < phone[i]; ++j)
                f2 << i;
        f2 << endl;
    }
    return 0;
}

