#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

#define esta(x,c) ((c).find(x) != (c).end())

typedef long long tint;

const int UNO = 0, I = 1, J = 2, K = 3;
#define menos(x) ((x)+4)
const int TARGET = 8 * 2 + K;
const int AFD_SIZE = 25;
const int START = 24;

const int tabla[4][4] = { {UNO,I,J,K},
                          {I,menos(UNO),K,menos(J)},
                          {J,menos(K),menos(UNO),I},
                          {K,J,menos(I),menos(UNO)}
                        };

int afd[32][4];

void buildAFD()
{
    forn(capa, 3)
    forn(x, 4)
    forn(signo, 2)
    {
        const int ID = 8 * capa + x + 4 * signo;
        forsn(symbol,1, 4)
        {
            const int result = (tabla[x][symbol] ^ (4 * signo));
            afd[ID][symbol] = 8 * capa + result;
            if ((capa == 0 && x == I && signo == 0) ||
                (capa == 1 && x == J && signo == 0))
            {
                afd[ID][symbol] = 8 * (capa+1) + symbol;
            }
        }
    }
    afd[START][I] = I;
    afd[START][J] = J;
    afd[START][K] = K;
}

const char *answer[2] = {"NO", "YES"};

int transicionPorString[32];

int main()
{
    buildAFD();
    int TT; cin >> TT;
    forn(tt,TT)
    {
        tint L,X; cin >> L >> X;
        string s; cin >> s;
        forn(startState, AFD_SIZE)
        {
            int state = startState;
            for (auto c : s)
            {
                int symbol;
                if (c == 'i') symbol = I;
                else if (c == 'j') symbol = J;
                else symbol = K;
                state = afd[state][symbol];
            }
            transicionPorString[startState] = state;
        }
        int state = START;
        map<int , int> visited;
        tint cycleLen = 0;
        while (!esta(state, visited))
        {
            visited[state] = cycleLen++;
            state = transicionPorString[state];
            cycleLen++;
        }
        tint cycleStart = visited[state];
        cycleLen -= cycleStart;
        if (X > cycleStart)
            X = cycleStart + (X - cycleStart) % cycleLen;
        state = START;
        forn(i, X) state = transicionPorString[state];
        bool ret = state == TARGET;
        cout << "Case #" << tt+1 << ": " << answer[ret] << endl;
    }
    return 0;
}
