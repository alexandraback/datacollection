#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    ifstream fin("B-large.in");
    ofstream fout("B-large.txt");
    int T;
    fin >> T;
    for(int i = 1; i<= T; i++) {
        int N;
        fin >> N;
        int heights[2501];
        for(int n = 0; n < 2501; n++)
            heights[n] = 0;
        for(int n = 1; n <= 2*(N)-1; n++) {
            for(int j = 0; j < N; j++) {
                int x;
                fin >>x;
                heights[x]++;
            }
        }
        fout << "Case #" << i << ": ";
        int counter = 0;
        for(int n = 1; counter < N; n++) {
            if(heights[n]%2==1 && counter < N-1) {
                fout << n << " ";
                counter ++;
            }
            else if(heights[n]%2==1 && counter == N-1) {
                fout << n;
                counter ++;
            }
        }
        fout << endl;
    }
    return 0;
}
