#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ifstream cin("/Users/mac/topcoder/input.txt");
  ofstream cout("/Users/mac/topcoder/output.txt");
    
    int NT;
    cin >> NT;
    
    for (int CT = 0; CT < NT; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        int x, y;
        cin >> x >> y;
        
        for (int i = 0; i < abs(x); i ++) {
            cout << ((x > 0) ? "W" : "E");
            cout << ((x > 0) ? "E" : "W");
        }
        
        for (int i = 0; i < abs(y); i ++) {
            cout << ((y > 0) ? "S" : "N");
            cout << ((y > 0) ? "N" : "S");
        }
        
        cout << endl;
    }
    
    return 0;
} 
