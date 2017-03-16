#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int solve(vector<int>::iterator b, vector<int>::iterator e, int A) {
    int result = 0;
    for(vector<int>::iterator it=b;it<e;it++) {
        if(*it<A) {
            A += *it;
        }else {
            int oldA = A;
            int r1 = 0;
            while(A <= *it) {
                r1++;
                A = A*2-1;
                if(A == oldA) {
                    r1 = e-b+1;
                    break;
                }
            }
            A += *it;
            r1 += solve(it+1, e, A);
            int r2 = 1 + solve(it+1, e, oldA);
            return min(r1,r2);
        }
    }
    return result;
}

int main()
{
    int test_cases=0;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++) {
        int A, N;
        cin >> A >> N;
        vector<int> vec(N,0);
        for(int i=0;i<N;i++) {
            cin >> vec[i];
        }
        sort(vec.begin(),vec.end());
        int result = solve(vec.begin(),vec.end(), A);
        cout << "Case #" << test_case << ": " << result << endl;
    }
    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
