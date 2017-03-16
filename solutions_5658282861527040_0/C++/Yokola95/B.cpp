#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
int T,A,B,K;
int main()
{
    freopen("problem.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> A >> B >> K;
        long long ans = 0;
        for(int i = 0; i < A; ++i)
            for(int j = 0; j < B; ++j)
                if((i & j) < K)
                    ++ans;
        cout << "Case #" << t+1 << ": " << ans << endl;
    }


    return 0;

}
