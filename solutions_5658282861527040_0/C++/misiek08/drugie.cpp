#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<cmath>
#include<cstdio>
#define MAX_N 21
using namespace std;

int T, a, b, k, result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> T;
    for(int lzd=1; lzd<=T; ++lzd)
    {
        cin >> a >> b >> k;
        result=0;
        for(int i=0; i<a; ++i)
            for(int j=0; j<b; ++j)
                if((i&j) < k) result++;
        cout << "Case #" << lzd << ": " << result << endl;
    }
    return 0;
}
