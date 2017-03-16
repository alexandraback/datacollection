#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
    ifstream in ("2.in");
    ofstream out ("2.out");
    int testcases;
    in >> testcases;
    string str;
    getline (in, str);
    for (int t = 1; t <= testcases; ++t) {
        out << "Case #" << t <<": ";
        string str;
        getline (in, str);
        int pm=0,mp=0;
        for (int i=0; i < str.size() - 1; i++) {
            if (str[i]=='+' && str[i+1]=='-')
                pm++;
        }
        if (str[0]=='-') mp++;
        out << 2*pm + mp << endl;
    }
}

