#include <iostream>     //  |-------------------------------------|
#include <cmath>        //  |Danger! Too many bags! HadronWave (c)|
#include <queue>        //  |-------------------------------------|     
#include <set>                          
#include <map>                          
#include <algorithm>
#include <vector>
#include <deque>
#include <functional>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const ll mod19 = 1000000009;
const ll mod17 = 1000000007;


vector<int> arr;



int main(){
    
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int T,A,N;
    cin >> T;

    for(int i=1;i<=T;++i){
        cout << "Case #" << i << ": ";
        cin >> A >> N;
        arr.resize(N);
        for(int j=0;j<N;++j) cin >> arr[j];
        sort(arr.begin(),arr.end());
        int ans = N;
        if(A==1){
            cout << ans << endl;
        }else{
            int t = A,res = 0;
            for(int j=0;j<N;++j){
                if(t>arr[j]) {
					t+=arr[j];
					ans = min(ans,res + N-j-1);
				}
                else {
					--j; 
                    t += t-1;
                    ++res;
                }
            }
            cout << ans << endl;
        }
        

    }



    // Goodbye and good luck!
    return 0;

}