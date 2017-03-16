#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

bool isvowels(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long long n_value(string &str, int n) {
    int len = str.length();
    int *suc = new int[len];
    long long *ret = new long long[len];

    suc[len - 1] = isvowels(str[len - 1]) ? 0 : 1;
    ret[len - 1] = suc[len - 1] >= n ? 1 : 0;

    int k = 0;
    for(int i = len - 2; i >= 0; --i) {
        ret[i] = ret[i + 1];
        
        if(isvowels(str[i]))
            suc[i] = 0;
        else
            suc[i] = suc[i + 1] + 1;

        if(suc[i] >= n) {
            int j = i + n - 1;
            k = len - j;
            ret[i] += k;
        } else {
            ret[i] += k;
        }
    }
            
    long long val = ret[0];
    delete[] ret;
    delete[] suc;

    return val;
}

int main(int argc, char **argv) {
    ifstream input(argv[1], ios::in);
    ofstream output("output.txt", ios::out);

    int T;
    input>>T;
    
    for(int i = 1; i <= T; ++i) {
        string str;
        int n;
        input>>str;
        input>>n;        

        output<<"Case #"<<i<<": ";
        output<<n_value(str, n)<<endl;
    }

    return 0;
}
