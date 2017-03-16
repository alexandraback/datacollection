#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    int T,case_id;
    int N,S,p,i,g,count;
    freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
    cin >> T;
    for (case_id=1;case_id<=T;case_id++) {
        cout << "Case #" << case_id << ": ";
        cin >> N >> S >> p;
        count=0;
        for (i=1;i<=N;i++) {
            cin >> g;
            if (g>=3*p-2) count++;
            else if ( (g>=3*p-4) && (g<=3*p-3) && (g>0) && (S>0) ) {
                S--;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

