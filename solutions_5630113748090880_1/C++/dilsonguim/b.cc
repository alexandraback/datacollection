#include <iostream>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int n;
        cin >> n;
        map<int, int> freq;
        for(int i = 0; i < 2 * n - 1; i++){
            for(int j = 0; j < n; j++){
                int h;
                cin >> h;
                freq[h]++;
            }
        }

        cout << "Case #" << tc << ':';
        for(auto& e : freq){
            if(e.second % 2){
                cout << ' ' << e.first;
            }
        }
        cout << endl;
    }
}
