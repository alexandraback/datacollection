#include <iostream>
#include <iomanip>

static inline double time_to_win (double goal, double farm_cost, double farm_payout, double flow) {
    
    double time_no_farm = goal / flow;
    double time_to_farm = farm_cost / flow;
    double time_with_farm = goal / (flow + farm_payout);

    if (time_no_farm <= time_to_farm + time_with_farm)
        return time_no_farm;

    return farm_cost / flow + time_to_win(goal, farm_cost, farm_payout, flow + farm_payout);
}

static inline void play (size_t caseidx) {
    double c, f, x;
    std::cin >> c >> f >> x;

    // x - the goal
    // c - farm cost 
    // f - farm payout

    std::cout << "Case #" << caseidx << ": " << time_to_win(x, c, f, 2.0) << std::endl;
}

int main () {
    size_t cases;
    std::cin >> cases;

    std::cout << std::fixed << std::setprecision(7);

    for (size_t i=1; i<=cases; ++i)
        play(i);
    return 0;
}
