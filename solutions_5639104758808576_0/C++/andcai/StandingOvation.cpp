#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin ("inputA.txt");
    ofstream fout ("outputA.txt");
    int T, smax;
    char sarray[1000];
    int sum, n;
    fin >> T;
    for(int x = 0; x < T; x++){
        fin >> smax;
        sum = 0;
        n = 0;
        for(int i = 0; i <= smax; i++){
            fin >> sarray[i];
            if(i > sum + n) n = i - sum;
            sum += sarray[i] - '0';
        }
        fout << "Case #" << x+1 << ": " << n << '\n';
    }
}
