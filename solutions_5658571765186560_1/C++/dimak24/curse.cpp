#include <fstream>
#include <iostream>
using namespace std;


int main() {
    ofstream fout("qqq.txt");
    ifstream fin("D-large.in");
    int x, g, c;
    int t;
    fin >> t;
    for(int i=0; i<t; i++) {
    fin >> x >> g >> c;
    fout << "Case #" << i+1 << ": ";
    if((g*c)%x!=0) fout << "RICHARD";
    else if(x>max(g, c)) fout << "RICHARD";
    else if(x>=2*min(g, c)+1) fout << "RICHARD";
    else if(g>=3 && c>=3 && x>=8) fout << "RICHARD";
    else if(x%2==0 && x>=2*min(g, c)-1 && x>2) fout << "RICHARD";
    else fout << "GABRIEL";
    fout << "\n";
}
    return 0;
}
