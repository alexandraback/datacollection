// Compile with TDM-GCC-64 5.1 with c++11 features

#include <stdint.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int N;
    std::cin >> N;
    std::string str;
    std::getline(std::cin, str);

    for (int case_no = 1; case_no <= N; ++case_no) {
        std::cout << "Case #" << case_no << ":";

        int n;
        cin >> n;

        std::map<int, int> counts;
        
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int currno;
                cin >> currno;
                counts[currno] += 1;
            }
        }

        for (auto& count : counts) {
            if (count.second & 1)
                cout << " " << count.first;
        }
        cout << "\n";
    }

    return 0;
}
