#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;

int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    int T,R,W,C;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> R >> C >> W;
        int cnt= (C/W)*R;
        if(C%W==0){
            cnt+=(W-1);
        } else {
            cnt+=W;
        }
        cout << "Case #" << (t+1) << ": " << cnt << endl;
    }
    return 0;
}
