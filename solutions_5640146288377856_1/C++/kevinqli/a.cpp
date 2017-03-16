#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int main() {
    int T;
    fin>>T;
    for(int z = 1; z <= T; z++) {
    int R, C, W;
    fin>>R>>C>>W;
    int ans = ((int)(C/W))*R + (C%W != 0) + W-1;
    fout<<"Case #"<<z<<": "<<ans<<endl;
    }
}
