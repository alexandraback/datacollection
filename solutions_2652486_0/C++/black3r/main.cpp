#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;
vector<int> cards;
vector<int> input;

int R, N, M, K;

void gen_cards() {
    cards.clear();
    for (int i = 0; i < N; i++) {
        int t = rand() % (M-2+1);
        t += 2;
        cards.push_back(t);
    }
}

bool valid() {
    set<int> products;
    int a = cards[0];
    int b = cards[1];
    int c = cards[2];
    products.insert(a);
    products.insert(b);
    products.insert(a*b);
    products.insert(a*c);
    products.insert(b*c);
    products.insert(a*b*c);
    products.insert(c);
    products.insert(1);

    bool cor = true;
    for (int i = 0; i < input.size(); i++) {
        if (products.find(input[i]) == products.end()) {
            cor = false;
        }
    }
    return cor;
}


int main()
{
    cout << "Case #1:" << endl;
    int x; cin >> x;
    cin >> R >> N >> M >> K;
    while (R--) {
        input.clear();
        for (int i = 0; i < K; i++) {
            int t; cin >> t;
            input.push_back(t);
        }
        bool solution = false;
        int maxm = 10000;
        int j = 0;
        while (!solution) {
            j++;
            if (j > maxm) break;
            gen_cards();
            solution = valid();
        }
        for (int j = 0; j < cards.size(); j++) {
            cout << cards[j];
        }
        cout << endl;
    }

    return 0;
}

