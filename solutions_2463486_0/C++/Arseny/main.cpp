#include <iostream>
#include <unordered_set>

using namespace std;

int A;
int B;

void read_input()
{
    cin >> A >> B;
}


const int MAX_B = 1000;
int COUNT[1+MAX_B];

void init()
{
    unordered_set<int> fair_square;
    fair_square.insert(1);
    fair_square.insert(4);
    fair_square.insert(9);
    fair_square.insert(121);
    fair_square.insert(484);

    int p = 0;    
    for (int i = 0; i <= MAX_B; ++i) {
        if (fair_square.find(i) != fair_square.end()) {
            ++p;
        }
        COUNT[i] = p;
    }
}

int solve()
{
    return (COUNT[B] - COUNT[A-1]);
}

int main(int argc, char const *argv[])
{
    init();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        read_input();
        int answer = solve();
        cout << "Case #" << t << ": " << answer << endl;
    }
}