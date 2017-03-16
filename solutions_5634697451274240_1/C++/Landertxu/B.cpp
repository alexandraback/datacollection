#include <iostream>

using namespace std;

int solve(){
    string pancakes;
    cin >> pancakes;
    
    pancakes += '+';
    int flips = 0;
    for (int i = 0; i < pancakes.size()-1; i++)
        if (pancakes[i] != pancakes[i+1])
            flips ++;
        
    return flips;
}

int main(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}