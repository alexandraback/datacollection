#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int calc(int A, int v[], int N)
{
    int i;
    int ret;

    if (A == 1)
        return 10000;

    ret = 0;
    i = 0;
    for(i=0;i<N;i++) {
        while (A <= v[i]) {
            ret++;
            A = 2*A-1;
        }
        A += v[i];
    }
    return ret;
}

int
main(void)
{
    int T;
    int i, j, ret;
    int A, N;
    int v[200];

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> A >> N;
        for(j=0;j<N;j++) {
            cin >> v[j];
        }
        sort(&v[0], &v[N]);
        
        ret = N;
        for(j=0;j<=N;j++) {
            ret = min(ret, calc(A, v, j)+(N-j));
            // cout << "ret= " << ret << endl;
        }
        
        cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
