#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define LL long long

using namespace std;

int main()
{
    /*double T,t,R,C,W,answer;

    cin >> T;
    for(t=1;t<=T;t++)
    {
        cin >> R >> C >> W;
        answer = (ceil((R*C)/W) + (W-1));
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0; small*/
    double T,t,R,C,W,answer;

    cin >> T;
    for(t=1;t<=T;t++)
    {
        cin >> R >> C >> W;
        answer = (ceil(C/W)*R + (W-1));
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
