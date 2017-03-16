#include <fstream>
#define MAXN 1000
using namespace std;

    int mat[MAXN][MAXN];
    int maxY[MAXN] = {}, maxX[MAXN] = {};
int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n;
    in >> n;
    for (int i = 0; i < n; i++)  {
        int x, y;
        in >> y >> x;
        
        for (int j = 0; j < y; j++) maxY[j] = 0;
        for (int j = 0; j < x; j++) maxX[j] = 0;
        for (int j = 0; j < y; j++)
            for (int k = 0; k < x; k++) {
                in >> mat[j][k];
                if (maxY[j] < mat[j][k]) maxY[j] = mat[j][k];
                if (maxX[k] < mat[j][k]) maxX[k] = mat[j][k];
            }
        bool t = true;
        for (int j = 0; j < y; j++)
            for (int k = 0; k < x; k++) {
                t = t && ((maxY[j] == mat[j][k]) || (maxX[k] == mat[j][k]));
            }
        if (t) {
            out << "Case #" << (i+1) << ": YES" << endl;
        }
        else {
            out << "Case #" << (i+1) << ": NO" << endl;
        }
    }

        

    return 0;

}