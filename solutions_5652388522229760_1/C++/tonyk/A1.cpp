#include <iostream>
#include <string>

using namespace std;

int main(){
    int i;
    int t;
    long long n;
    
    cin >> t;
    for (i = 0; i < t; i++){
        cin >> n;
        
        if (n == 0) {
            cout << "Case #" << i+1 << ": " << "INSOMNIA" << endl;
            continue;
        }
        
        int a[10] = {0};
        long long nn = 0;
        long long tmp;
        bool stop;
        
        while (true) {
            nn += n;
            tmp = nn;
            while (tmp > 0) {
                a[tmp % 10] = 1;
                tmp /= 10;
            }
            
            stop = true;
            for (int j = 0; j < 10; j++) {
                if (a[j] == 0) {
                    stop = false;
                    break;
                }
            }
            
            if (stop) break;
        }
        
        cout << "Case #" << i+1 << ": " << nn << endl;
    }
    
    return 0;
}
