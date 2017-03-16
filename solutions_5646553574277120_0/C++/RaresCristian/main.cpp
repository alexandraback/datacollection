
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;

#define MAX 100
int coins[MAX];
bool possible[MAX];


int C, D, V;

void calc_values (int cur, int n) {
    
    if (n >= D)
        return;
    if (cur > V)
        return;
    
    for (int i = 0; i <= 1; i++) {
        if (i == 0) {
            possible[coins[n] + cur] = true;
            cur += coins[n];
        }
        
        n++;
        calc_values(cur, n);
        n--;
        
        if (i == 0)
            cur -= coins[n];
        //if (i == 0)
        //    possible[coins[i] + cur] = false;
    }
}

int main() {
    
    ofstream fout ("ans.txt");
    ifstream fin ("input.txt");
    
    int T;
    fin >> T;
    // TEST CASES
    for (int t = 0; t < T; t++) {
        int ans = 0;
        
        for (int i = 0; i < MAX; i++)
            possible[i] = false, coins[i] = 0;
        
        fin >> C >> D >> V;
        for (int i = 0; i < D; i++) {
            fin >> coins[i];
            possible[coins[i]] = true;
        }
        sort(coins, coins+D);
        
        calc_values(0, 0);
    
        for (int i = 1; i <= V; i++)
            if (possible[i] == false) {
                ans++, D++;
                coins[D-1] = i;
                calc_values(0, 0);
            }
        
        fout << "Case #" << t+1 << ": " << ans << "\n";
    }
    
    
    return 0;
}


