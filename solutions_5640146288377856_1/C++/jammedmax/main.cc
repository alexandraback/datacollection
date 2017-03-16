#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <list>

using namespace std;

void solve(int testcase);

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; ++i)
        solve(i+1);
}

void solve(int testcase) {
    size_t R,C,W;
    cin >> R >> C >> W;
    size_t ans = 0;
    ans = R*(C/W);
    if(C%W == 0)
    	ans += W-1;
    else
	    ans += W ;
    cout << "Case #" << testcase << ": " << ans << endl;
}
