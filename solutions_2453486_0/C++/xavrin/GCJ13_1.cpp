#include <cstdio>
#include <utility>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); ––x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define PII pair<int, int>

bool checkColumn (char tab[][10], char player, int num){
    bool T = false;
    int count = 0;
    for (int i = 0; i < 4; i++){
        if (tab[i][num] == player)
            count++;
        else if (tab[i][num] == 'T')
            T = true;
    }
    return (count == 4) || (count == 3 && T);
}
bool checkRow (char tab[][10], char player, int num){
    bool T = false;
    int count = 0;
    for (int i = 0; i < 4; i++){
        if (tab[num][i] == player)
            count++;
        else if (tab[num][i] == 'T')
            T = true;
    }
    return (count == 4) || (count == 3 && T);
}

bool checkDiag1 (char tab[][10], char player){
    bool T = false;
    int count = 0;
    for (int i = 0; i < 4; i++){
        if (tab[i][i] == player)
            count++;
        else if (tab[i][i] == 'T')
            T = true;
    }
    return (count == 4) || (count == 3 && T);
}
bool checkDiag2 (char tab[][10], char player){
    bool T = false;
    int count = 0;
    for (int i = 0; i < 4; i++){
        if (tab[3-i][i] == player)
            count++;
        else if (tab[3-i][i] == 'T')
            T = true;
    }
    return (count == 4) || (count == 3 && T);
}

bool filled (char tab[][10]){
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tab[i][j] == '.')
                return false;
    return true;
}

int main(){
    char tab[10][10];
    int T;
    scanf("%d", &T);
    for (int j = 0; j < T; j++){
        for (int i = 0; i < 4; i++)
            scanf("%s", tab[i]);
        bool OWon = false, XWon = false;
        for (int i = 0; i < 4; i++){
            if (checkColumn(tab, 'O', i) || checkRow(tab, 'O', i))
                OWon = true;
            if (checkColumn(tab, 'X', i) || checkRow(tab, 'X', i))
                XWon = true;
        }
        if (checkDiag1(tab, 'O') || checkDiag2(tab, 'O'))
            OWon = true;
        if (checkDiag1(tab, 'X') || checkDiag2(tab, 'X'))
            XWon = true;
        bool fi = filled(tab);
        printf("Case #%d: ", j+1);
        if (OWon) printf("O won\n");
        else if (XWon) printf("X won\n");
        else if (fi) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
