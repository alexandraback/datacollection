#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float r32;
typedef double r64;

#define minimum(a, b) ((a < b) ? (a) : (b))
#define maximum(a, b) ((a > b) ? (a) : (b))

void flip(s64 n, string &s)
{
    string newS = s;
    for(s64 i = 0; i < n; ++i)
    {
        if(s[n-1-i] == '+') newS[i] = '-';
        else newS[i] = '+';
    }
    s = newS;
}

int main()
{
    ifstream in("in");
    ofstream out("out");

    int T;
    in >> T;

    for(int caseNum = 1; caseNum <= T; ++caseNum)
    {
        cout << "Case #" << caseNum << endl;
        out << "Case #" << caseNum << ":";

        string s; in >> s;

        int answer = 0;
        for(;;)
        {
            s64 firstNeg = -1;
            for(s64 i = s.size()-1; i >= 0; --i)
            {
                if(s[i] == '-')
                {
                    firstNeg = i;
                    break;
                }
            }
            if(firstNeg == -1) break;

            int flipCount = 0;
            for(s64 i = 0; i < s.size(); ++i)
            {
                if(s[i] == '+') ++flipCount;
                else break;
            }

            if(flipCount > 0)
            {
                flip(flipCount, s);
                ++answer;
            }
            flip(firstNeg+1, s);
            ++answer;
        }

        out << " " << answer << '\n';
    }

    return 0;
}
