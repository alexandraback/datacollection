#include <iostream>
#include <unordered_set>
#include <deque>
#include <vector>

using namespace std;

typedef unsigned long long IntType;

IntType A;
IntType B;

void read_input()
{
    cin >> A >> B;
}

vector<IntType> FAIR_SQUARE;

void init()
{
    FAIR_SQUARE.clear();
    FAIR_SQUARE.push_back(1);
    FAIR_SQUARE.push_back(4);
    FAIR_SQUARE.push_back(9);
    FAIR_SQUARE.push_back(121);
    FAIR_SQUARE.push_back(484);
    FAIR_SQUARE.push_back(10201);
    FAIR_SQUARE.push_back(12321);
    FAIR_SQUARE.push_back(14641);
    FAIR_SQUARE.push_back(40804);
    FAIR_SQUARE.push_back(44944);
    FAIR_SQUARE.push_back(1002001);
    FAIR_SQUARE.push_back(1234321);
    FAIR_SQUARE.push_back(4008004);
    FAIR_SQUARE.push_back(100020001);
    FAIR_SQUARE.push_back(102030201);
    FAIR_SQUARE.push_back(104060401);
    FAIR_SQUARE.push_back(121242121);
    FAIR_SQUARE.push_back(123454321);
    FAIR_SQUARE.push_back(125686521);
    FAIR_SQUARE.push_back(400080004);
    FAIR_SQUARE.push_back(404090404);
    FAIR_SQUARE.push_back(10000200001);
    FAIR_SQUARE.push_back(10221412201);
    FAIR_SQUARE.push_back(12102420121);
    FAIR_SQUARE.push_back(12345654321);
    FAIR_SQUARE.push_back(40000800004);
    FAIR_SQUARE.push_back(1000002000001);
    FAIR_SQUARE.push_back(1002003002001);
    FAIR_SQUARE.push_back(1004006004001);
    FAIR_SQUARE.push_back(1020304030201);
    FAIR_SQUARE.push_back(1022325232201);
    FAIR_SQUARE.push_back(1024348434201);
    FAIR_SQUARE.push_back(1210024200121);
    FAIR_SQUARE.push_back(1212225222121);
    FAIR_SQUARE.push_back(1214428244121);
    FAIR_SQUARE.push_back(1232346432321);
    FAIR_SQUARE.push_back(1234567654321);
    FAIR_SQUARE.push_back(4000008000004);
    FAIR_SQUARE.push_back(4004009004004);
}

int solve()
{
    auto it = FAIR_SQUARE.begin();
    auto it2 = FAIR_SQUARE.end();

    while (it != it2 && *it < A) {
        ++it;
    }

    int result = 0;    
    while (it != it2 && *it <= B) {
        ++it;
        ++result;
    }

    return result;
}

bool is_fair(long long p)
{
    deque<int> Q;
    while (p) {
        Q.push_back(p%10);
        p = p/10;
    }
    while (Q.size() > 1) {
        if (Q.front() != Q.back()) return false;
        Q.pop_front();
        Q.pop_back();
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /*
    for (long long i = 0; i < 100000000; ++i) {
        if (is_fair(i) && is_fair(i*i)) {
            cout << i << ' ' << i*i << endl;
        }
    }
    */
    init();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        read_input();
        int answer = solve();
        cout << "Case #" << t << ": " << answer << endl;
    }
}