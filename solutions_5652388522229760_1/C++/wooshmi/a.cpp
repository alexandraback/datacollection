#include <iostream>
#include <fstream>

using namespace std;

void process(bool* f, int x) {
    while(x) {
        f[x % 10] = true;
        x /= 10;
    }
}

bool check(bool* f) {
    for (int i = 0; i < 10; ++i)
        if (!f[i])
            return false;
    return true;
}

int main() {
    ifstream in;
    in.open("dataset.in");
    ofstream out;
    out.open("dataset.out");

    int T;
    in >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        in >> n;
        bool freq[10];
        for (int j = 0; j < 10; ++j)
            freq[j] = false;
        if (n == 0) 
            out << "Case #" << (i + 1) << ": INSOMNIA\n";
        else {
            int aux = n;
            process(freq, aux);
            while(!check(freq)) {
                aux += n;
                process(freq, aux);
            }
            out << "Case #" << (i + 1) << ": " << aux << "\n";
        }
    }
    
    in.close();
    out.close();
    return 0;
}
