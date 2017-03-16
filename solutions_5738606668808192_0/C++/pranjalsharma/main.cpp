#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    //ifstream fin("C.txt");
    ofstream fout("output.txt");
    const int n = 16, j = 50;
    int k, l, c = 0;
    long divs[9];
    char coin[n];
    fout << "Case #1:\n";
    for(int h = 1; (h < n/2)&&(c < j); h++){
        for(int i = 0; i < n; i++){
            coin[i] = '0';
        }
        coin[n - 1] = '1';
        coin[0] = '1';
        coin[h] = '1';
        coin[n - 1 - h] = '1';

        for(int i = 2; i < 11; i++){
            long power = 1;
            for(int t = 0; t < h; t++){
                power *= i;
            }
            divs[i - 2] = power + 1;
        }

        for(int i = n - 1; i >= 0; i--){
            fout << coin[i];
        }
        for(int i = 0; i < 9; i++){
            fout << " " << divs[i];
        }
        fout << "\n";
        c++;
        for(k = 1 + h; (k < n - 1)&&(c < j); k++){
            for(l = k; (l < (n - (1 + 2*h)))&&(c < j); l += (h + 1)){
                coin[l] = '1';
                coin[l + h] = '1';
                for(int m = n - 1; m >= 0; m--){
                    fout << coin[m];
                }
                for(int i = 0; i < 9; i++){
                    fout << " " << divs[i];
                }
                fout << "\n";
                c++;
            }
            for(int f = k; f < n - h - 1; f++) {
                coin[f] = '0';
            }
        }
    }
    cout << c;


    return 0;
}
