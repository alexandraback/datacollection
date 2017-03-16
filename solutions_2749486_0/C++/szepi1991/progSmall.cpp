#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
    
    unsigned cases;
    cin >> cases;
    
    int X, Y;
    for (unsigned ca = 1; ca <= cases; ++ca) {
        // like subset sum.. can we use (1, 2, 3, .. i) to get to (X,Y)?
        cin >> X >> Y;
        
        // can always move by 1 each time!!
        string seq = "";
        int curX = 0, curY = 0;
        while (curX != X) {
            if (curX < X) {
                // jump left, then right;
                seq += "W";
                seq += "E";
                curX++;
            } else {
                // jump right, then left;
                seq += "E";
                seq += "W";
                curX--;
            }
        }
        
        while (curY != Y) {
            if (curY < Y) {
                // jump down, then up;
                seq += "S";
                seq += "N";
                curY++;
            } else {
                // jump up, then down;
                seq += "N";
                seq += "S";
                curY--;
            }
        }
        
        curX = 0;
        curY = 0;
        for (unsigned i = 1; i <= seq.length(); ++i) {
            switch (seq[i-1]) {
                case 'W': curX -= i; break;
                case 'E': curX += i; break;
                case 'S': curY -= i; break;
                case 'N': curY += i; break;
            }
        }
        if (curX != X || curY != Y) cerr << "nnnnnnnnnnNN!!!!!!! " << curX << "," << curY << endl;
        
        cout << "Case #" << ca << ": " << seq << endl;      
    }    
    
    return 0;
}

