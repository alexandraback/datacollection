#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

int numDigits(int x) {
    if (x >= 10000) {
        if (x >= 10000000) {
            if (x >= 100000000) {
                if (x >= 1000000000)
                    return 10;
                return 9;
            }
            return 8;
        }
        if (x >= 100000) {
            if (x >= 1000000)
                return 7;
            return 6;
        }
        return 5;
    }
    if (x >= 100) {
        if (x >= 1000)
            return 4;
        return 3;
    }
    if (x >= 10)
        return 2;
    return 1;
}

int pow(int x, int y) {
    if(y == 0)
        return 1;
    else return x * pow(x, y-1);
}

int main(void) {
    ifstream infile("QC.in");
    ofstream outfile("QC.out");
    
    string line;
    int i = 0;
    int a;
    int b;
    while(infile.good()) {
        getline(infile, line);
        stringstream strstr(line);
        i++;
        if(i == 1)
            continue;
        
        string word = "";
        int j = 0;
        while(getline(strstr, word, ' ')) {
            if(j == 0)
                a = atoi(word.c_str());
            else
                b = atoi(word.c_str());
            j++;
        }
        
        int q = 1;
        int q2 = 10;
        int n = 0;
        
        for(int j = a; j <= b; j++) {
            int t = j;
            int l = numDigits(t);
            if(j >= q2) {
                q = pow(10, l-1);
                q2 = pow(10, l);
            }
            int u = -1;
            for(int k = 1; k < l; k++) {
                if(k != 1 && u == j)
                    continue;
                
                t = (int)floor(t/10) + (t % 10) * q;
                u = t;
                if(u > j && u <= b) {
                    n++;
                }
            }
        }
        cout << "Case #" << (i-1) << ": " << n << "\n";
        outfile << "Case #" << (i-1) << ": " << n << "\n";
    }
    
    system("pause");
    return 0;
}
