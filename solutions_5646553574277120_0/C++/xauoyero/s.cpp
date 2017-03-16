#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int solve(int C, int V, vector<int> &ds)
{
    int D = ds.size();
    //ans <= V
    int ans = 0;
    vector<bool> all(V + 1, false);
    vector<bool> d(V + 1, false);
    for(int i = 0; i < D; i++){
        d[ds[i]] = true;
    }
    for(int i = 1; i <= V; i++){
        if(d[i] == true){
            //insert i and update all
            for(int j = 1; j < i; j++){
                if((all[j] == true) && (i + j <= V)){
                    all[j + i] = true;
                }
            }
            all[i] = true;
        }
        if(all[i] == false){
            //insert i
            ans ++;
            for(int j = 1; j < i; j++){
                if((all[j] == true) && (i + j <= V)){
                    all[j + i] = true;
                }
            }
            all[i] = true;
        }
    }
    return ans;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    //[1, 100]
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        //C = 1, D[1, 5] V[1, 30]
        int C, D, V;
        cin >> C >> D >> V;
        //ds[i] <= V, in ascending order
        vector<int> ds(D);
        for(int i = 0; i < D; i++){
            cin >> ds[i];
        }
        cout << "Case #" << cas << ": " << solve(C, V, ds) << endl;
    }
    return 0;
}
