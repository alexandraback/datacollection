//
//  LAwnmower
//
//
//  Created by Laszlo Majer
//
//


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

typedef unsigned long long UInt64;
typedef long long Int64;

bool IsVowel(char test)
{
    switch (test)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }

    return false;
}


int main()
{
    int T = 0;
    
    cin >> T;
    for (int caseNumber = 0; caseNumber < T; ++caseNumber)
    {
        UInt64 n = 0;
        string name = "";
        cin >> name;
        cin >> n;

        bool addOne = false; // for adding an extra value for the whole world
        UInt64 result = 0;
        Int64 firstIndex = 0;
        Int64 prevFound = -1;
        for (Int64 i = 0; i < name.length(); ++i)
        {
            if (IsVowel(name[i]))
            {
                firstIndex = i + 1;
                continue;
            }

            if (i - firstIndex < n - 1)
                continue;

            if (i == name.length() - 1 && firstIndex == 0)
            {
                ++result;
                continue; // this could be break also
            }

            addOne = true;
            
            Int64 first = firstIndex - (prevFound + 1);
            Int64 last = ((name.length() - i) - 1);
            result += first + last;
            result += first * last;
            ++result;

            prevFound = firstIndex;
            firstIndex = firstIndex + 1;
        }
        
        cout << "Case #" << caseNumber + 1 << ": " << result << endl;
    }
}
