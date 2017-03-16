#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int T;

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    
    fin >> T;
    
    for(int ct = 1; ct <= T; ct++) {
        int x = 0;
        int y = 0;
        fin >> x >> y;
        string xt = "";
        string yt = "";
        if(x > 0) xt = "WE";
        else xt = "EW";
        if(y > 0) yt = "SN";
        else yt = "NS";
        string rt = "";
        for(int i = 0; i < abs(x); i++) rt += xt;
        for(int i = 0; i < abs(y); i++) rt += yt;
        fout << "Case #" << ct << ": " << rt << endl;
    }
    
    
    return 0;
}
