#include <algorithm>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define INF 1000000010
#define MAXN 1000

#define SUBMI 0 /// CHANGE TO SUBMIT
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

using namespace std;

ifstream fin("B-small.in");
ofstream fout("B-small.out");

/// L : size of target
/// K : size of keyboard
/// S : size of resulting string

int T, K, L, S;
string dict, target;
int freq[26];
double sum, all;
int max_words;

bool check(int i, int j, string now) {
    for (int c=i, n=0; c<=j; c++, n++)
        if (now[c] != target[n])
            return false;
    return true;
}

double occurences(string now) {
    double retVal = 0.0;
    for (int i=0; i<=S-L; i++) {
        if (check(i, i+L-1, now))
            retVal += 1.0;
    }
    return retVal;
}

void write(string now) {
    if (now.size() == S) {
        sum += (double)((double)max_words - occurences(now));
        all += 1.0;
        return;
    }

    for (int i=0; i<K; i++)
        write(now+dict[i]);
}

int main()
{
    fin >> T;

    for (int test=1; test<=T; test ++) {
        fin >> K >> L >> S;
        fin >> dict >> target;

        for (int i=0; i<26; i++)
            freq[i] = 0;

        for (int i=0; i<dict.size(); i++)
            freq[dict[i]-'A'] ++;

        int max_prefix = 0;
        for (int i=1; i<L; i++) {
            int add = 1;
            for (int j=0; j<=i; j++)
                if (target[j] != target[j+L-i-1])
                    add = 0;
            max_prefix += add;
        }

        max_words = (S-L)/(L-max_prefix) + 1;

        bool ok = false;

        for (int i=0; i<target.size(); i++)
            if (freq[target[i]-'A'] == 0) {
                fout << "Case #" << test << ": 0.0000000\n";
                ok = true;
                break;
            }

        if (!ok) {
            all = 0.0;
            sum = 0.0;

            write("");

            double result = (double)sum/(double)all;

            fout << "Case #" << test << ": ";
            fout << fixed << setprecision(7) << result << endl;
        }
    }

    return 0;
}

