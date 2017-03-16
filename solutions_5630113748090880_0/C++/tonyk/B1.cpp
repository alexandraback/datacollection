#include <iostream>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        int heights[2600] = {0};
        int h;
        for (int j = 0; j < 2*n-1; j++) {
            for (int k = 0; k < n; k++) {
                cin >> h;
                heights[h]++;
            }
        }
        
        cout << "Case #" << i+1 << ":";
        for (int j = 1; j <= 2500; j++) {
            if (heights[j] % 2 == 1) {
                cout << " " << j;
            }
        }
        cout << endl;
    }
    return 0;
}
