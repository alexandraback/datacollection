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

        bool digits[10] = {};
        u64 startNumber; in >> startNumber;
        u64 number = startNumber;

        if(number == 0)
        {
            out << " INSOMNIA" << '\n';
            continue;
        }

        bool done = false;
        while(!done)
        {
            u64 test = number;
            while(test > 0)
            {
                int digit = test % 10;
                digits[digit] = true;
                test /= 10;
            }

            done = true;
            for(int i = 0; i < 10; ++i)
            {
                if(!digits[i])
                {
                    done = false;
                    break;
                }
            }
            if(done) break;
            number += startNumber;
        }

        out << " " << number << '\n';
    }

    return 0;
}
