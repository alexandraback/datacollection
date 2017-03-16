#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> read_array()
{
    int n;
    cin >> n;

    vector<int> ret(n);
    for (int i = 0;i < n; ++i)
        cin >> ret[i];
    return ret;
}

bool can_be_split(const vector<int>& plates, int upper_limit, int es)
{
    int need = 0;
    for (auto p : plates) {
        need += (p - 1) / upper_limit;
    }

    return need <= es;
}

int get_optimal_split(const vector<int>& plates, int es)
{
    int ret = 1;
    while (!can_be_split(plates, ret, es))
        ret += 30;
    while (ret > 1 && can_be_split(plates, ret - 1, es))
        ret --;
    return ret;
}

int min_eating_time(const vector<int>& plates, int es)
{
    return es + get_optimal_split(plates, es);
}

int main(int argc, char **argv)
{
    int num_cases;
    cin >> num_cases;

    for (int cas = 1;cas <= num_cases; ++cas) {
        vector<int> plates = read_array();
        int ret = 1002;
        for (int es = 0;es < ret;es ++) {
            ret = min(ret, min_eating_time(plates, es));
        }

        cout << "Case #" << cas << ": " << ret << endl;
    }

    return 0;
}
