#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile;
    std::ofstream outfile;
    infile.open("in1s.txt");
    outfile.open("out1s.txt");
    int t, len;
    infile >> t;
    std::string s1, s2="";
    for(int i = 0; i < t; i++) {
        s2 = "";
        infile >> s1;
        len = s1.length();
        s2 += s1[0];
        for(int j = 1; j < len; j++) {
            if(s1[j] >= s2[0]) {
                s2 = s1[j] + s2;
            }
            else
                s2 = s2 + s1[j];
        }
        outfile << "Case #" << i+1 << ": " << s2 << "\n";
    }
    return 0;
}
