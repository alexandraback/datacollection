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
        int x, r ,c;
        bool res = true;
        cin >> x; cin >> r; cin >> c;

        if (x >= 7) {
            res = false;
        }
        else if (x > r*c) {
            res = false;
        }
        else if ((r*c) % x != 0) {
            res = false;
        }
        else if (x > r && x > c) {
            res = false;
        }
        else if ((x+1)/2 > r || (x+1)/2 > c) {
            res = false;
        }
        else if (x == 4 && min(r,c)<=2){
            res = false;
        }
        else if (x == 5 && r*c == 15) {
            res = false;
        }
        else if (x == 6 && min(r,c) <=3) {
            res = false;
        }
    
        cout << "Case #" << i+1 << ": "; 
        if (res)
            cout << "GABRIEL" << endl;
        else    
            cout << "RICHARD" << endl;
    }
   
    return 0;
}
 
