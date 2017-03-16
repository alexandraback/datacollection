/*
 ID: szhu0081
 LANG: C++
 TASK: butter
 */

#include <iostream>
#include <list>
#include <cstring>
#include <numeric>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef set<vi> svi;

long long T, D;

int P[1005];

int main(){
    
    ifstream ins("B-large.in");
    ofstream ofs("B-large-out.txt");
    
    ins >> T;
    
    for (int cse = 1; cse <= T; cse ++){
        int ans = 1000000000;
        ins >> D;
        for (int i = 0; i < D; i++)
            ins >> P[i];
        for (int k = 1; k <= 1000; k++){
            int sum = k;
            for (int i = 0; i < D; i++){
                sum += (P[i]-1)/k;
            }
            ans = min(ans, sum);
        }
        
        ofs << "Case #" << cse << ": " << ans << endl;
    }


    return 0;
}


