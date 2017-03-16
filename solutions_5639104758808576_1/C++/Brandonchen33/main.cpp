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
        int hi_l;
        int res = 0;
        int extra = 0;
        cin >> hi_l;
        for(int j = 0; j < hi_l; j++) {
            char num;
            cin >> num;
            num = num - '0';
            if(num == 0){
                if(extra > 0)
                    extra -= 1;
                else
                    res++; 
            }
            else if(num > 0) {
                extra += num - 1;
            }
        }
        int tmp; cin >> tmp;
        cout << "Case #" << i+1 << ": "; 
        cout << res << endl;
    }
   
    return 0;
}
 
