#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	ifstream fin ("A-small-attempt2.in");
	ofstream fout ("A-output.txt");
	int T, l, k;
	unsigned long long N, b, x;
	fin >> T;
	for(int c = 1; c<=T; c++){
        fin >> N;
        if(N<10){
            fout << "Case #" << c << ": " << N << '\n';
            continue;
        }
        k = -1;
        if(N%10==0){
            N--;
            k++;
        }
        l = log10(N)+1;
        //cout << l << '\n';
        b = 0;
        for(int i = 1; i<l; i++){
            k += round(pow(10, ceil(i/2.0)));
            k += round(pow(10, floor(i/2.0))) - 1;
        }
        //cout << k << ' ' << N % x << '\n';
        x = round(pow(10, ceil(l/2.0)));
        k += N % x;
        //cout << N << ' ';
        N /= x;
        //cout << k << "\n\n";
        k++;
        for(int i = floor(l/2.0)-1; i>=0; i--){
            b += (N%10)*(unsigned long long) round(pow(10, i));
            N /= 10;
        }
        if(b==1) b--;
        //cout << b << '\n';
        fout << "Case #" << c << ": " << k+b << '\n';
	}
}
