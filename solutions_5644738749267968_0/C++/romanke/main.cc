#include <iostream>
#include <vector>
#include <algorithm>

double ken_play (std::vector<double> &ken, double naomi) {
    // return minimal element which is greater than naomi's, otherwise smallest one
    std::vector<double>::iterator it = std::upper_bound(ken.begin(), ken.end(), naomi);
    if (it == ken.end())
        it = ken.begin();

    double ret = *it;
    ken.erase(it);
    return ret;
}

static inline size_t dwar (const std::vector<double> &naomi, const std::vector<double> &ken) {
    std::vector<double> k(ken);
    std::vector<double> n(naomi);

    size_t wins = 0;
    for (size_t i=0; i<naomi.size(); ++i) {
        // best if i can win
        std::vector<double>::iterator it = std::upper_bound(n.begin(), n.end(), k.front());
        if (it != n.end()) {
            ++wins;
            n.erase(it);
            k.erase(k.begin());
            continue;
        }

        // else i'm losing, so better make him lose his top one
        n.erase(n.begin());
        k.erase(k.end()-1);
    }

    return wins;
}

static inline size_t war (const std::vector<double> &naomi, const std::vector<double> &ken) {
    std::vector<double> k(ken);
    
    size_t wins = 0;
    for (size_t i=0; i<naomi.size(); ++i)
        wins += naomi[i] > ken_play(k, naomi[i]);

    return wins;
}

static inline std::vector<double> read_vec (size_t n) {
    std::vector<double> ret;
    while (n --> 0) {
        double val;
        std::cin >> val;
        ret.push_back(val);
    }
    return ret;
}

static inline void play (size_t caseidx) {
    size_t n;
    std::cin >> n;
    std::vector<double> naomi(read_vec(n));
    std::vector<double> ken(read_vec(n));

    std::sort(naomi.begin(), naomi.end());
    std::sort(ken.begin(), ken.end());

    std::cout << "Case #" << caseidx << ": " << dwar(naomi, ken)
                                        << " " << war(naomi, ken) << std::endl;
}

int main () {
    size_t cases;
    std::cin >> cases;
    for (size_t i=1; i<=cases; ++i)
        play(i);
    return 0;
}
