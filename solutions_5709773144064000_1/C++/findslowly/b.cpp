#include <iostream> 
#include <fstream> 
#include <iomanip>
using namespace std; 
ifstream fin("B-large.in"); 
ofstream fout("A-small-attempt0.out"); 
int main() {
    int T ; 
    fin >> T ; 
    for (int num = 1; num < T+1; ++num) {
        double c,f,x ; 
        fin >> c >> f >> x ; 
        double rate = 2.0 ; 
        double time = 0 ; 

        double t1,t2 ; 
        while (1) {
            t1 = x / rate ; 
            t2 = c / rate + x / (rate+f) ; 
            if (t1 > t2) {
                time += c / rate ; 
                rate += f ; 
            }
            else {
                time += t1 ; 
                break ; 
            }
        }
        fout << "Case #" << num << ": " ; 
        fout << setiosflags(ios::fixed) << setprecision(7) << time << endl ; 
    }
    return 0 ; 
}
