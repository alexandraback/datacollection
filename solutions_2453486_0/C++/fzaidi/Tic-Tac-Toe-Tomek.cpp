#define ENABLE_MAIN 1
#if ENABLE_MAIN


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <list>
#include <queue>
#include <numeric>
#include <iomanip>
#include <fstream>


using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<ll, ll> PLL;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

const ll oo = 1LL << 60;
const int kNumMoves = 4;
const int kMoves[kNumMoves][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

#define FOR(i, n) for (int i = 0; i < int(n); ++i)
#define FORI(i, s, n) for (int i = s; i < int(n); ++i)
#define FORD(i, n) for (int i = n - 1; i >= 0; --i)
#define VALID(i, mx) (i >= 0 && i < mx)

string PrintCase(int i)
{     
    ostringstream os;
    os << "Case #" << (i + 1) << ": ";
    return os.str();
}

const string kDraw = "Draw";
const string kIncomplete = "Game has not completed";
const string kOWon = "O won";
const string kXWon = "X won";

bool HasWon(vector<string>& board, char c)
{
    int diagTLBR = 0;
    int diagBLTR = 0;
    FOR(i, 4)
    {
        int cntR = 0;
        int cntC = 0;
        FOR(j, 4)
        {
            if (board[i][j] == c || board[i][j] == 'T') ++cntR;
            if (board[j][i] == c || board[j][i] == 'T') ++cntC;
            if (i == j) { if (board[j][i] == c || board[j][i] == 'T') ++diagTLBR; }
            if (i + j == 3) { if (board[j][i] == c || board[j][i] == 'T') ++diagBLTR; }
        }
        if ((cntR == 4) || (cntC == 4))
            return true;
    }


    if ((diagTLBR == 4) || (diagBLTR == 4))
        return true;

    return false;
}

bool IsIncomplete(vector<string>& board)
{
    FOR(i, 4)
    {
        FOR(j, 4)
        {
            if (board[i][j] == '.') return true;
        }
    }

    return false;
}

int main()
{
    ofstream cout ("A-small-attempt0.out");
    ifstream cin ("A-small-attempt0.in");

    int n;

    cin >> n;

    vector<string> board(4);


    FOR(i, n)
    {
        FOR(j, 4)
            cin >> board[j];

        if (HasWon(board, 'O')) { cout << PrintCase(i) << kOWon << endl; continue; }
        if (HasWon(board, 'X')) { cout << PrintCase(i) << kXWon << endl; continue; }
        if (IsIncomplete(board)) { cout << PrintCase(i) << kIncomplete << endl; continue; }
        cout << PrintCase(i) << kDraw << endl;
    }

    return 0;
}
#endif