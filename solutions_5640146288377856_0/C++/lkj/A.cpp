#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int tc=1; tc <= t; ++tc){
        int r,c,w;
        cin >> r >> c >> w;
        int res = c/w + w;
        if(c%w == 0)
            res--;
        cout << "Case #" << tc << ": " << res << endl;
    }
    return 0;
}
