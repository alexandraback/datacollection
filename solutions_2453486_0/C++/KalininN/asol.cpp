#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

char p[10][10];
int cntO, cntX;

void add(char x)
{
    if (x == 'T')
    {
        cntO++;
        cntX++;
    }
    if (x == 'X') cntX++;
    if (x == 'O') cntO++;
}

int main()
{
    int NT=0;
    scanf("%d",&NT);
    for (int T=1;T<=NT;T++)
    {
        for (int i = 0; i < 4; i++) scanf("%s", p[i]);
        bool Owon = false;
        bool Xwon = false;
        for (int i = 0; i < 4; i++)
        {
            cntO = 0;
            cntX = 0;
            for (int j = 0; j < 4; j++) add(p[i][j]);
            Owon = Owon || cntO == 4;
            Xwon = Xwon || cntX == 4;
        }
        for (int i = 0; i < 4; i++)
        {
            cntO = 0;
            cntX = 0;
            for (int j = 0; j < 4; j++) add(p[j][i]);
            Owon = Owon || cntO == 4;
            Xwon = Xwon || cntX == 4;
        }
        cntO = 0;
        cntX = 0;
        for (int j = 0; j < 4; j++) add(p[j][j]);
        Owon = Owon || cntO == 4;
        Xwon = Xwon || cntX == 4;
        cntO = 0;
        cntX = 0;
        for (int j = 0; j < 4; j++) add(p[j][4 - j - 1]);
        Owon = Owon || cntO == 4;
        Xwon = Xwon || cntX == 4;
        
        bool isempty = false;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++) if (p[i][j] == '.') isempty = true;
        }
        
        printf("Case #%d: ", T);
        assert((!Owon) || (!Xwon));
        if (Owon) printf("O won\n");
        else if (Xwon) printf("X won\n");
        else if (isempty) printf("Game has not completed\n");
        else printf("Draw\n");
        fprintf(stderr, "%d/%d done\n", T, NT);
    }
    return 0;
}
