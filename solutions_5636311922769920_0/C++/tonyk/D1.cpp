#include <iostream>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k, c, s;
        cin >> k >> c >> s;
        
        
        cout << "Case #" << i+1 << ":";
        for (int j = 0; j < s; j++) {
            cout << " " << j+1;
        }
        cout << endl;
    }
    
    return 0;
}
