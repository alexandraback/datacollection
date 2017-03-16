#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream fin("Q2.in");
    ofstream fout("Q2.out");
    fout.precision(7);
    int T;
    double C, F, X;
    double ret, time, rate, newret;
    fin >> T;
    for(int i = 0; i < T; i++){
        fin >> C; fin.ignore();
        fin >> F; fin.ignore();
        fin >> X; fin.ignore();
        
        rate = 2.0;
        ret = X/rate;
        time = 0;
        
        while(1){
            time += C/rate;
            rate += F;
            newret = time + X/rate;
            
            if(newret < ret) ret = newret;
            else{
                fout << "Case #" << i+1 << ": ";
                fout << ret << endl;
                break;
            }
        }
    }
    
    getchar();
    return 0;
}
