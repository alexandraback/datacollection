#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");
    
    fp >> T;

    for(int k = 1; k <= T; k++) {
        long long res = 0, r, c, w;
        fp >> r >> c >> w;
        res = (c / w) * r + (w - 1);
        if (c % w != 0)
            res++;
        
        ofp << "Case #" << k << ": " << res << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
