#include <iostream> 
#include <fstream> 

using namespace std ; 
ifstream fin("D-small-attempt0.in"); 
ofstream fout("A-small-attempt0.out"); 
int main() {
    int T ; 
    fin >> T ; 
    for (int num = 1; num < T+1; ++num) {
        int n ; 
        float naomi[1000], ken[1000] ; 
        fin >> n ; 
        for (int i = 0; i < n; ++i) 
            fin >> naomi[i] ; 
        for (int i = 0; i < n; ++i) 
            fin >> ken[i] ; 
        
        float t ; 
        for (int i = 0; i < n-1; ++i) 
            for (int j = n-1; j > i; --j)
                if (naomi[j] < naomi[j-1]) {
                    t = naomi[j] ; 
                    naomi[j] = naomi[j-1] ; 
                    naomi[j-1] = t ; 
                }
        for (int i = 0; i < n-1; ++i) 
            for (int j = n-1; j > i; --j)
                if (ken[j] < ken[j-1]) {
                    t = ken[j] ; 
                    ken[j] = ken[j-1] ; 
                    ken[j-1] = t ; 
                }

        // play deceitful war 
        int i = n-1 ; 
        int j = n-1 ;
        int ans1 ; 
        while (1) {
            if (naomi[i] > ken[j]) {
                --i ; 
                --j ; 
            }
            else 
                --j ; 
            if (j == -1) 
                break ; 
        }
        ans1 = n-i-1 ; 

        // play war 
        i = 0 ; 
        j = 0 ;
        int ans2 ; 
        while (1) {
            if (naomi[i] < ken[j]) {
                ++i ; 
                ++j ; 
            }
            else 
                ++j ; 
            if (j == n) 
                break ; 
        }
        ans2 = n-i ; 

        fout << "Case #" << num << ": " << ans1 << " " << ans2 << endl;  
    }
    return 0 ; 
}
