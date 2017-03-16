//==============================================================================
// Qualification Round 2015
// Problem B. Infinite House of Pancakes
//
//==============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using sol_type = int;

void read_data();
sol_type find_solution();

class Diner {
public:
    Diner(int p_, int div_) : p{p_}, div{div_} {}
    int get() const {
        return ceil(p*1.0/div);
    }
    void add() {
        ++div;
    }
    bool operator<(const Diner & d) const {
        return this->get() < d.get();
    }
private:
    int p;
    int div;
};

vector<Diner> house;

int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        read_data();
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << solution << endl;
    }
    return 0;
}

void read_data(){
    house.clear();
    int num;
    cin >> num;
    for(int i=0; i<num; ++i) {
        int tmp;
        cin >> tmp;
        house.emplace_back(tmp,1);
    }
}

sol_type find_solution(){
    priority_queue<Diner> PQ (house.begin(), house.end());
    int curr = PQ.top().get();
    int time = 0;

    while(time < curr) {
        Diner d = PQ.top();
        PQ.pop();

        int left = d.get();
        curr = min(curr, time+left);

        if(left != 1) {
            while (d.get() == left) {
                d.add();
                ++time;
            }
            PQ.push(d);
        } else
            break;
    }

    return curr;
}
