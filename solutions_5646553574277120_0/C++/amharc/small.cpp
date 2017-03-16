#include <bits/stdc++.h>
using namespace std;

struct state {
    bitset<31> possible;
    set<int> remaining;
};

int limit = 30;

int V;

void backtrack(state st, int depth, int from = 0) {
    if(depth > limit)
        return;

    bool allok = true;
    for(int i = 0; i <= V; ++i)
        allok &= st.possible[i];

    if(allok) {
        limit = depth;
        return;
    }

    for(int rem : st.remaining) {
        if(rem > from) {
            state copy = st;
            copy.remaining.erase(rem);
            copy.possible |= copy.possible << rem;
            backtrack(move(copy), depth + 1, rem);
        }
    }
}

int testcase() {
    int C, D;
    cin >> C >> D >> V;

    state st;

    for(int i = 1; i <= V; ++i)
        st.remaining.insert(i);

    st.possible[0] = 1;
    for(int i = 0; i < D; ++i) {
        int val;
        cin >> val;
        st.possible |= st.possible << val;
        st.remaining.erase(val);
    }

    if(C != 1 || V > 30)
        return -1;

    limit = st.remaining.size();

    backtrack(st, 0);

    return limit;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
        cout << "Case #" << i << ": " << testcase() << endl;
}
