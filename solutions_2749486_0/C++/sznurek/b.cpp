#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <vector>

using namespace std;

const int DUZO = 512;
const int MAX_MOVES = 32;

map<pair<int, pair<int, int> >, char> mem;
vector<char> find_ans(int x, int y);
pair<int, int> eval(vector<char>& v);

char cango(int x, int y, int n);

int main() {
    int t;

    scanf("%d", &t);
    
    for(int c = 1; c <= t; c++) {
        int x, y;

        scanf("%d %d", &x, &y);
        printf("Case #%d: ", c);
        vector<char> ans = find_ans(x, y);
        for(int i = ans.size() - 1; i >= 0; i--) {
            printf("%c", ans[i]);
        }

        printf("\n");
    }
    return 0;
}

vector<char> find_ans(int x, int y) {
    int moves;
    for(moves = 0; moves < MAX_MOVES; moves++) {
        if(cango(x, y, moves) != 'X')
            break;
    }

    vector<char> ans;
    while(moves) {
        char c = cango(x, y, moves);
        ans.push_back(c);
        if(c == 'N')
            y -= moves;
        if(c == 'S')
            y += moves;
        if(c == 'E')
            x -= moves;
        if(c == 'W')
            x += moves;

        moves--;
    }

    return ans;
}

char cango(int x, int y, int n) {
    if(n == 0) {
        if(x == 0 && y == 0)
            return 'O';
        return 'X';
    }

    if(mem.find(make_pair(n, make_pair(x, y))) != mem.end())
        return mem[make_pair(n, make_pair(x, y))];

    char can_do = 'X';
    if(abs(x + n) <= DUZO) {
        char c = cango(x + n, y, n - 1);
        if(c != 'X')
            can_do = 'W';
    }

    if(can_do == 'X' && abs(x - n) <= DUZO) {
        char c = cango(x - n, y, n - 1);
        if(c != 'X')
            can_do = 'E';
    }
    if(can_do == 'X' && abs(y - n) <= DUZO) {
        char c = cango(x, y - n, n - 1);
        if(c != 'X')
            can_do = 'N';
    }
    if(can_do == 'X' && abs(y + n) <= DUZO) {
        char c = cango(x, y + n, n - 1);
        if(c != 'X')
            can_do = 'S';
    }

    mem[make_pair(n, make_pair(x, y))] = can_do;
    //printf("ANS (%d, %d) n = %d -> %c\n", x, y, n, can_do);
    return can_do;
}

pair<int, int> eval(vector<char>& v) {
    pair<int, int> p = make_pair(0, 0);
    int n = 1;
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i] == 'N')
            p.second += n;
        if(v[i] == 'S')
            p.second -= n;
        if(v[i] == 'E')
            p.first += n;
        if(v[i] == 'W')
            p.first -= n;
        n++;
    }

    return p;
}
