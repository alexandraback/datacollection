#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
int main() {
    int test_cnt;
    cin >> test_cnt;
    for(int i = 0; i < test_cnt; i++) {
        vector<int> pancakes;
        int num;
        cin >> num;
        while(num--) {
            int tmp;
            cin >> tmp;
            pancakes.push_back(tmp);
        }
        int res = *max_element(pancakes.begin(),pancakes.end());
        int cap = res;

        for(int cut = 2; cut < cap ; cut++) {
            int p_res = cut;
            int len = pancakes.size();
            for(int i = 0; i < len; i++) {
                p_res += (pancakes[i]-1)/cut;
            }
            res = min(res, p_res); 
        }
        
        cout << "Case #" << i+1 << ": "; 
        cout << res << endl;
    }
   
    return 0;
}
 
