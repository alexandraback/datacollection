#include <deque>
#include <iostream>

using namespace std;

/*
 * return score of Naomi.
 * Assuming both players following his/her own optimal strategy.
 */
int play_war(const int N, deque<double> naomi, deque<double> ken) {
    // both deques are sorted
    int score = 0;
    for (int i = 0;i < N;++i) {
        if (naomi.front() < ken.front()) {
            naomi.pop_front();
        } else {
            auto it = upper_bound(ken.begin(), ken.end(), naomi.front(), less<double>());
            if (it == ken.end()) {
                ken.pop_front();
                ++score;
            } else {
                ken.erase(it);
            }
            naomi.pop_front();
        }
    }

    return score;
}

int play_deceitful_war(const int N, deque<double> naomi, deque<double> ken) {
    // both deques are sorted
    int score = 0;
    for (int i = 0;i < N;++i) {
        if (naomi.front() < ken.front()) {
            // Shhhhhhh.. Naomi cheats!
            naomi.pop_front();
            ken.pop_back();
        } else {
            if (naomi.back() > ken.back()) {
                ++score;
                naomi.pop_front();
                ken.pop_front();
            } else {
                // Shhhhhhh.. Naomi cheats!
                naomi.pop_front();
                ken.pop_back();
            }
        }
    }

    return score;
}

void read_weights(deque<double> &iv, const int N) {
    double num;
    for (int i = 0;i < N;++i) {
        cin >> num;
        iv.push_back(num);
    }

    sort(iv.begin(), iv.end());
}

int main() {
    int T;
    cout.precision(7);
    cin >> T;

    for (int i = 0;i < T;++i) {
        int N;
        cin >> N;
        deque<double> naomi, ken;

        read_weights(naomi, N);
        read_weights(ken, N);

        cout << "Case #" << (i+1) << ": ";
        cout << play_deceitful_war(N, naomi, ken) << ' ';
        cout << play_war(N, naomi, ken);
        cout << endl;
    }
}
