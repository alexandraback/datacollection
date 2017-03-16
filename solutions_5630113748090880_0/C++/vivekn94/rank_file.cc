#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile;
    std::ofstream outfile;
    infile.open("in2s.txt");
    outfile.open("out2s.txt");
    int T, N, a, b, c;
    infile >> T;
    for(int i = 0; i < T; i++) {
        infile >> N;
        //printf("%d\n", N);
        int arr[2500];
        for(int j = 0; j < 2500; j++)
            arr[j] = 0;
        for(int j = 0; j < 2*N-1; j++) {
            for(int k = 0; k < N; k++) {
                infile >> a;
                arr[a-1]++;
                //printf("hrllo\n");
            }
            //arr[b-1]++;
            //arr[c-1]++;
        }
        int k = 0;
        outfile << "Case #" << i+1 << ":";
        for(int j = 0; j < 2500; j++) {
            if(arr[j] % 2 != 0) {
                outfile << " " << j+1;
            }
        }
        outfile << "\n";
        delete(arr);
    }
    return 0;
}
