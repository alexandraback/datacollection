#include <string> 
#include <algorithm> 
#include <cfloat> 
#include <climits> 
#include <cmath> 
#include <complex> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <functional> 
#include <iostream> 
#include <map> 
#include <memory> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <utility> 
#include <vector> 

#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(x) (x).begin(),(x).end() 
using namespace std;
const double eps = 1e-10;

//input data
int A, B, K;

void solve(int caseNum){
    //solve problem here
    int res = 0;
    for(int i = 0; i < A; ++i)for(int j = 0; j < B; ++j){
        if((i & j) < K)
            ++res;
    }
    cout << "Case #" << caseNum << ": " << res << endl;
}

int main(){
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        //input test case here
        cin >> A >> B >> K;

        solve(t);
    }
    return 0;
}
