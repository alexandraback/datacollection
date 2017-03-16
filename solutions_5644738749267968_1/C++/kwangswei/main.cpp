#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int get_point_of_war(vector<double> naomi, vector<double> ken) {
    int small = 0;
    int big = ken.size() - 1;

    int naomi_win = 0;

    for (int i = naomi.size() - 1; i >= 0; i--) {
        if (naomi[i] > ken[big]) {
            naomi_win++;
            small++;
        }
        else {
            big--;
        }
    }

    return naomi_win;
}

int get_point_of_deceitful_war(vector<double> naomi, vector<double> ken) {
    int small = 0;
    int big = ken.size() - 1;

    int naomi_win = 0;

    for (int i = 0; i < naomi.size(); ++i) {
        if (naomi[i] < ken[small]) {
            big--;
        }
        else {
            small++;
            naomi_win++;
        }
    }

    return naomi_win;
}

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int cnt;
        cin >> cnt;

        auto naomi = vector<double>(cnt);
        for (int i = 0; i < cnt; ++i)
            cin >> naomi[i];

        auto ken = vector<double>(cnt);
        for (int i = 0; i < cnt; ++i)
            cin >> ken[i];
        
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());

        int war = get_point_of_war(naomi, ken);
        int deceitful_war = get_point_of_deceitful_war(naomi, ken);

        printf("Case #%d: %d %d\n", test, deceitful_war, war);
    }

    return 0;
}
