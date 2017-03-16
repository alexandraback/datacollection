#include <iostream>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        
        int jps[11][11][11] = {0};
        int jp[11][11] = {0};
        int ps[11][11] = {0};
        int js[11][11] = {0};
        
        int sol = 0;
        
        for (int ij = 1; ij <= j; ij++) {
            for (int ip = 1; ip <= p; ip++) {
                for (int is = 1; is <= s; is++) {
                    if (jp[ij][ip] < k && ps[ip][is] < k && js[ij][is] < k) {
                        jps[ij][ip][is] = 1;
                        sol ++;
                        jp[ij][ip]++;
                        ps[ip][is]++;
                        js[ij][is]++;
                    }
                }
            }
        }
        
        cout << "Case #" << i+1 << ": " << sol << endl;
        
        for (int ij = 1; ij <= j; ij++) {
            for (int ip = 1; ip <= p; ip++) {
                for (int is = 1; is <= s; is++) {
                    if (jps[ij][ip][is] == 1) {
                        cout << ij << " " << ip << " " << is << endl;
                    }
                }
            }
        }

    }
    return 0;
}
