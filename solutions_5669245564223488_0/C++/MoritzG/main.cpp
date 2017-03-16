#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int mod = 1000000007;

struct Train {
    Train() {
        used = vector<bool>(26, false);
        previous = '0';
    }
    vector<bool> used;
    char previous;
};

long long trains(vector<string> cars, Train train) {
    if(cars.size() == 0) return 1;
    long long res = 0;
    for(int i(0); i != cars.size(); ++i) {
        string car = cars[i];
        Train new_train(train);
        new_train.used = train.used;
        new_train.previous = train.previous;
        int j(0);
        for(; j != car.size(); ++j) {
            if(new_train.previous != car[j] && new_train.used[car[j] - 'a']) break;
            new_train.used[car[j] - 'a'] = true;
            new_train.previous = car[j];     
        }
        if(j != car.size()) continue;
        vector<string> new_cars(cars);
        new_cars.erase(new_cars.begin() + i);            
        res += trains(new_cars, new_train);
        res = res % mod;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for(int testcase(0); testcase != t; ++testcase) {
        cout << "Case #" << testcase + 1 << ": ";
        int n;
        cin >> n;
        vector<string> cars;
        for(int i(0); i != n; ++i) {
            string car;
            cin >> car;
            cars.push_back(car);
        }
        cout << trains(cars, Train()) << endl;
    }
}
