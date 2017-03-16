#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        string s;
        cin >> s;
        string p;
        for(auto c : s){
            string p1 = c + p;
            string p2 = p + c;
            p = max(p1, p2);
        }

        cout << "Case #" << tc << ": " << p << endl;
    }
}
