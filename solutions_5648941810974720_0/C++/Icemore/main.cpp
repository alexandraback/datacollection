#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <memory.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

int chcount[256];

string names[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[] = {0, 6, 2, 7, 5, 4, 1, 9, 8, 3};

bool have_num(int n)
{
    forv(i, names[n])
    {
        if(chcount[(int)names[n][i]] == 0)
            return false;
    }
    return true;
}

void sub_num(int n)
{
    forv(i, names[n])
    {
        chcount[(int)names[n][i]]--;
    }
}

string solve(string str)
{
    memset(chcount, 0, sizeof(chcount));
    forv(i, str)
    {
        chcount[(int)str[i]]++;
    }

    stringstream ss;
    forn(i, 10)
    {
        int n = order[i];
        while(have_num(n))
        {
            ss << n;
            sub_num(n);
        }
    }

    string ans = ss.str();
    sort(ans.begin(), ans.end());

    return ans;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        string str;
        cin >> str;

        auto res = solve(str);

        std::cout << "Case #" << tc + 1 << ": " << res << endl;
    }
    
    return 0;
}
