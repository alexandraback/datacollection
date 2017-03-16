#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;

char a[10][10];
char s[10];

bool dot = false;

bool checkc(char c, int y, int x)
{
    return a[y][x] == c || a[y][x] == 'T';
}

bool check(char c)
{
    for (int i = 0; i < 4; ++i)
    {
        bool b = true;
        for (int j = 0; j < 4; ++j)
           b = b && checkc(c, i, j);
        if (b) return true;
        b = true;
        for (int j = 0; j < 4; ++j)
            b = b && checkc(c, j, i);
        if (b) return true;        
    }
    bool b = true;
    for (int i = 0; i < 4; ++i)
        b = b && checkc(c, i, i);
    if (b) return true;
    b = true;
    for (int i = 0; i < 4; ++i)
        b = b && checkc(c, i, 3 - i);
    if (b) return true;
    return false;
}

int main()
{
    scanf("%d", &T);
    
    for (int t = 0; t < T; ++t)
    {
        dot = false;
        gets(s);
        for (int i = 0; i < 4; ++i)
            gets(a[i]);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (a[i][j] == '.') dot = true;
        string ans = "";
        if ( check('X') )
            ans = "X won";
        else if ( check('O') )
            ans = "O won";
        else if (dot)
            ans = "Game has not completed";
        else ans = "Draw";
        printf("Case #%d: %s\n", t + 1, ans.c_str());
    }
    return 0;
}
