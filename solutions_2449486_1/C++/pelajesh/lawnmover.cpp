#include <fstream>
#include <vector>
using namespace std;

ifstream sf("lawnmower.in");
ofstream vf("lawnmower.out");

int n;
vector<vector<int> > dat;

int main () {
    sf >> n;
    for (int i = 1; i <= n; i++) {
        vf << "Case #" << i << ": ";
        int x, y;
        sf >> x >> y;
        dat.resize(x);
        for (int j = 0; j < x; j++) {
            dat[j].resize(y);
            for (int k = 0; k < y; k++) {
                sf >> dat[j][k];   
            }   
        }   
        bool next = false; 
        for (int j = 0; j < x && !next; j++) {
            for (int k = 0; k < y && !next; k++) {
                bool donex = false;
                bool doney = false;
                for (int l = 0; l < x; l++) {
                    if (dat[l][k] > dat[j][k]) {
                        donex = true;
                        break;
                    } 
                }
                for (int l = 0; l < y; l++) {
                    if (dat[j][l] > dat[j][k]) {
                        doney = true;
                        break;
                    } 
                }
                if (donex && doney) {
                    vf << "NO" << endl;
                    next = true;
                }
            }   
        }
        if (!next) vf << "YES" << endl;
    }        
}
