#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;
        
long long X, Y;

int main()
{
    int test_cases=0;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++) {
        cin >> X >> Y;
        string steps;
        string s;
        if(X>0) {
            s="WE";
        }else {
            s="EW";
        }
        for(int i=0;i<abs(X);i++) {
            steps += s;
        }
        
        if(Y>0) {
            s="SN";
        }else {
            s="NS";
        }
        for(int i=0;i<abs(Y);i++) {
            steps += s;
        }
        cout << "Case #" << test_case << ": " << steps << endl;
    }
    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
