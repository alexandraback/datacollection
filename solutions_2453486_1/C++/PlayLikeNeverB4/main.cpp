#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

int T;
char A[5][5];

string solve() {
    for(int i = 0; i < 4; i++) {
        bool ok = true;
        for(int j = 0; j < 4; j++)
            if(A[i][j] != 'X' && A[i][j] != 'T')
                ok = false;
        if(ok)
            return "X won";
    }
    for(int j = 0; j < 4; j++) {
        bool ok = true;
        for(int i = 0; i < 4; i++)
            if(A[i][j] != 'X' && A[i][j] != 'T')
                ok = false;
        if(ok)
            return "X won";
    }
    bool ok = true;
    for(int i = 0; i < 4; i++)
        if(A[i][i] != 'X' && A[i][i] != 'T')
            ok = false;
    if(ok)
        return "X won";
    ok = true;
    for(int i = 0; i < 4; i++)
        if(A[i][3 - i] != 'X' && A[i][3 - i] != 'T')
            ok = false;
    if(ok)
        return "X won";

    // =======================

    for(int i = 0; i < 4; i++) {
        bool ok = true;
        for(int j = 0; j < 4; j++)
            if(A[i][j] != 'O' && A[i][j] != 'T')
                ok = false;
        if(ok)
            return "O won";
    }
    for(int j = 0; j < 4; j++) {
        bool ok = true;
        for(int i = 0; i < 4; i++)
            if(A[i][j] != 'O' && A[i][j] != 'T')
                ok = false;
        if(ok)
            return "O won";
    }
    ok = true;
    for(int i = 0; i < 4; i++)
        if(A[i][i] != 'O' && A[i][i] != 'T')
            ok = false;
    if(ok)
        return "O won";
    ok = true;
    for(int i = 0; i < 4; i++)
        if(A[i][3 - i] != 'O' && A[i][3 - i] != 'T')
            ok = false;
    if(ok)
        return "O won";

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(A[i][j] == '.')
                return "Game has not completed";

    return "Draw";
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

	scanf("%d\n", &T);
    for(int t = 1; t <= T; t++) {
        for(int i = 0; i < 4; i++)
            scanf("%s", A[i]);

        printf("Case #%d: %s\n", t, solve().c_str());
    }

	return 0;
}
