#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <math.h>
using namespace std;

int debug = 0;
int V[10];
int E, R, N;
int max_result;

void recur(int index, int gain, int curr_energy) {
    // cout << index << " " << gain << " " << curr_energy << endl;
    if (index == N) {
        if (gain > max_result) {
            max_result = gain; 
        }
        return;
    }

    for (int i = 0; i <= curr_energy; i++) {
        int next_energy = curr_energy-i+R; 
        if (next_energy > E) next_energy = E; 
        recur(index+1, V[index]*i + gain, next_energy); 
    }

}

void get_result() {
    /* cout << E << " " << R << " " << N << endl; 
    for (int v = 0; v < N; v++) {
        cout << V[v] << " "; 
    }
    cout << endl; */
                
    max_result = 0;
    recur(0, 0, E);
    cout << max_result << endl; 
}

int main() { 
    int T; 
    string str;

    cin >> T;
    getline(cin, str);
    for (int cnum = 1; cnum <= T; cnum++) {
        cin >> E >> R >> N; 
        getline(cin, str);
        for (int v = 0; v < N; v++) {
            cin >> V[v];
        }
        getline(cin, str);
        cout << "Case #" << cnum << ": ";
        get_result();
    }
} 
