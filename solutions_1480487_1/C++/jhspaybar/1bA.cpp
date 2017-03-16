#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    int cases;
    cin >> cases;
    for(int i = 1; i <=cases; ++i) {
        int contestants;
        cin >> contestants;
        vector<int> each;
        int sum = 0;
        int max = 0;
        for(int j = 0; j < contestants; ++j) {
            int input;
            cin >> input;
            each.push_back(input);
            sum += input;
            if(max<input) {
                max = input;
            }
        }
        int doubleSum = sum*2;
        int count = each.size();
        double target = (double)doubleSum/(double)each.size();
        bool over = false;
        cout << "Case #" << i << ":";
        if(max > target) {
            over = true;
            for(vector<int>::iterator it = each.begin(); it<each.end(); ++it) {
                if(*it > target) {
                    --count;
                    doubleSum -= *it;
                }
            }
        }
        target = (double) doubleSum/((double)count);
        for(vector<int>::iterator it = each.begin(); it<each.end(); ++it) {
            double perc = ((target-*it)/sum)*100;
            if (perc < 0.0) {
                perc = 0.0;
            }
            cout << " " << fixed << setprecision(6) << perc;
        }
        cout << endl;
    }
    return 0;
}
