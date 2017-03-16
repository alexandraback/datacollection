#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

int T, N;
long A, m[100];
int dloss=0, iloss;

int main() {
    fin >> T;
    for(int it =1; it<=T; it++) {
        fin >> A >> N;
        for(int i=0; i<N; i++) fin >> m[i];
        sort(m, m+N);
        int mincount=N;
        int count = 0;
        
        for(int i=0; i<N; ) {
            if(m[i] < A) {
                A += m[i];
                i++;
            }
            else {
                if(mincount > count+N-i) mincount = count+N-i;
                count++;
                A += A-1;                 
            } 
            if(count > mincount) break;           
        }
        if(mincount > count) mincount = count;
        
        fout << "Case #" << it << ": " << mincount << endl;
    }
}
