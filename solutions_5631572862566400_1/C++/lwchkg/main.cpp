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
        std::cout << "Case #" << case_no << ": ";

        int n;
        cin >> n;

        std::vector<int> bf;
        std::vector<int> iscycle(n);
        std::vector<int> cyclelength(n);
        std::vector<int> branchlen_to(n);
        //int maxcircle = 0;
        //std::vector<std::vector<int>> nextto(n);
        for (int i = 0; i < n; i++) {
            int currno;
            cin >> currno;
            currno--;
            bf.push_back(currno);
        }
        
        for (int i = 0; i < n; i++) {
            if (iscycle[i]) continue;

            // locate cycle
            int currno = i;
            vector<bool> is_used(n);
            while (!is_used[bf[currno]] && !iscycle[bf[currno]]) {
                currno = bf[currno];
                is_used[currno] = true;
            }
            // if an existing cycle is met, skip because no extra cycle is found
            if (iscycle[bf[currno]]) continue;

            // set iscycle for cycle
            int cyclestart = currno;
            int cln = 1;
            iscycle[currno] = true;
            while (bf[currno] != cyclestart) {
                currno = bf[currno];
                cln++;
            }

            // set cyclelength for cycle
            currno = cyclestart;
            cyclelength[currno] = cln;
            while (bf[currno] != cyclestart) {
                currno = bf[currno];
                iscycle[currno] = true;
                cyclelength[currno] = cln;
            }
        }

        for (int i = 0; i < n; i++) {
            if (iscycle[i]) continue;
            int currno = i;
            int branchlen = 1;
            while (!iscycle[bf[currno]]) {
                branchlen++;
                currno = bf[currno];
            }
            branchlen_to[bf[currno]] = max(branchlen_to[bf[currno]], branchlen);
        }

        int maxlength = 0;
        int cycle2length = 0;
        for (int i = 0; i < n; i++) {
            //cerr << "\n" << bf[i] << '-' << iscycle[i] << ':' << cyclelength[i] << ':' << branchlen_to[i]; 
            if (iscycle[i]) {
                if (cyclelength[i] == 2) {
                    cycle2length += cyclelength[i] + branchlen_to[i] + branchlen_to[bf[i]];
                } else {
                    maxlength = max(maxlength, cyclelength[i]);
                }
            }
        }
        maxlength = max(maxlength, cycle2length / 2);
        cout << maxlength << '\n';
    }

    return 0;
}

