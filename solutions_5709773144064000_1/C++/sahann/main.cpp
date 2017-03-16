
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;
int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        double C,F,X;
        cin >> C >> F >> X;
 
        int maxiter = 500;
        double bst = X/2.0;
        int curFarms = 0;
        double org = 0;
        while(true){
            double tm = C/(2.0+F*curFarms);
        
            //time needed to get an additional farm
            double cand = org+tm+X/(2.0+F*(curFarms+1));
            bst = min(cand,bst);
            curFarms++;
            org+= tm;
            if(org>bst) break;
        }
        cout << "Case #" << t+1 << ": " <<fixed << setprecision(9) << bst << endl;
    }
    

    return 0;
}

