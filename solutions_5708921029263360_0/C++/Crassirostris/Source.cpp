#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdint>

#define ld long double
#define ll long long

const int MAX_S = 10;
const int MAX_STATES = MAX_S * MAX_S * MAX_S;

int jackets_count, pants_count, shirts_count, restriction, states_count;
std::vector<std::tuple<int, int, int>> states, answer;

int taken;
bool used[MAX_STATES];
int js[MAX_S][MAX_S], jp[MAX_S][MAX_S], ps[MAX_S][MAX_S];


int64_t readInt64() {
    ll x;
    std::cin >> x;
    return x;
}

int readInt32() {
    int x;
    std::cin >> x;
    return x;
}

void read() {
    jackets_count = readInt32();
    pants_count = readInt32();
    shirts_count = readInt32();
    restriction = readInt32();

    states_count = jackets_count * pants_count * shirts_count;
    states.resize(states_count);
    for (int i = 0; i < jackets_count; ++i) {
        for (int j = 0; j < pants_count; ++j) {
            for (int k = 0; k < shirts_count; ++k) {
                auto state_no = i * (pants_count * shirts_count) + j * shirts_count + k;
                used[state_no] = false;
                states[state_no] = std::make_tuple(i, j, k);
                jp[i][j] = 0;
                js[i][k] = 0;
                ps[j][k] = 0;
            }
        }
    }

    answer.clear();

    taken = 0;
}

int bits_count(int mask) {
    int count = 0;
    while (mask > 0) {
        if (mask & 1) {
            ++count;
        }
        mask >>= 1;
    }
    return count;
}

bool is_valid_pairs(std::map<std::pair<int, int>, int> &pairs) {
    for (auto &p : pairs) {
        if (p.second > restriction) {
            return false;
        }
    }
    return true;
}

bool is_valid(int mask) {
    std::map<std::pair<int, int>, int> jp, js, ps;
    for (int i = 0; i < states_count; ++i, mask >>= 1) {
        if (mask & 1) {
            int jacket, pants, shirt;
            std::tie(jacket, pants, shirt) = states[i];
            ++jp[std::make_pair(jacket, pants)];
            ++js[std::make_pair(jacket, shirt)];
            ++ps[std::make_pair(shirt, pants)];
        }
    }
    return is_valid_pairs(jp) && is_valid_pairs(js) && is_valid_pairs(ps);
}

void make_new_answer() {
    answer.clear();
    for (int i = 0; i < states_count; ++i) {
        if (used[i]) {
            answer.push_back(states[i]);
        }
    }
}

void try_solve(int cur) {
    if (cur == states_count) {
        if (taken > answer.size()) {
            make_new_answer();
        }
        return;
    }

    int jacket, pants, shirt;
    std::tie(jacket, pants, shirt) = states[cur];
    if (jp[jacket][pants] < restriction && js[jacket][shirt] < restriction && ps[pants][shirt] < restriction) {
        used[cur] = true;
        ++taken;
        ++jp[jacket][pants];
        ++js[jacket][shirt];
        ++ps[pants][shirt];

        try_solve(cur + 1);

        --ps[pants][shirt];
        --js[jacket][shirt];
        --jp[jacket][pants];
        --taken;
        used[cur] = false;
    }

    if (states_count - cur - 1 + taken > answer.size()) {
        try_solve(cur + 1);
    }
}

void solve() {
    try_solve(0);
}

void print() {
    std::cout << answer.size() << std::endl;
    for (auto &t : answer) {
        int jacket, pants, shirt;
        std::tie(jacket, pants, shirt) = t;
        std::cout << jacket + 1 << ' ' << pants + 1 << ' ' << shirt + 1 << std::endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        read();
        solve();
        std::cout << "Case #" << i + 1 << ": ";
        print();

        std::cerr << i << std::endl;
    }

    return 0;
}