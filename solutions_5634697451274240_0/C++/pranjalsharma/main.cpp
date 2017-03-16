#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("B-small-attempt0.in");
    ofstream fout("outputsmall.txt");
    int T, n;
    char s0, s1;
    fin >> T;
    fin.get();
    //cout << "T input : " << T;
    for(int i = 0; i < T; i++) {
        //cout << "\nin Loop : iteration = " << i+1 ;
        n = 0;
        s0 = fin.get();
        s1 = fin.get();
        //cout << "\nInitial s0 = " << s0 << " and s1 = " << s1;
        //getchar();
        while(s1 != '\n') {
                //cout << "\ninside inner loop";
            if(s1 != s0) n++;
            s0 = s1;
            s1 = fin.get();
        }
        if(s0 == '-') n++;
        fout << "Case #" << i+1 << ": " << n <<"\n";
    }
    return 0;
}
