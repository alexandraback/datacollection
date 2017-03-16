#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <boost\algorithm\string.hpp>

using namespace std;

bool is_2pow(int a) {
   return !(a&(a-1));
}



int main() {

    freopen("A.in", "r", stdin);
    freopen("output.txt", "w", stdout);


    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        // input
        string str;
        cin >> str;
        vector<string> numbers;
        boost::algorithm::split(numbers, str, boost::is_any_of("/"));

        int P = std::stoi(numbers[0]);
        int Q = std::stoi(numbers[1]);
        
        if (P != 1 && Q % P == 0) {
            Q /= P;
            P = 1;
        }

        if (P == 1 && Q == 1) {
            cout << "Case #" << t + 1 << ": " << 0 << endl;
        } else if (!is_2pow(Q)) {
            cout << "Case #" << t + 1 << ": " << "impossible" << endl;
        } else {
            double vich = 0.5;
            double pq = (static_cast<double>(P) / Q);
            for (int n = 1; n <= 40; ++n) {
                if (pq >= vich) {
                    cout << "Case #" << t + 1 << ": " << n << endl;
                    break;
                }
                vich /= 2;
            }
        }




        //cout << "Case #" << t + 1 << ": " <<  << endl;
    }

    

    return 0;
}