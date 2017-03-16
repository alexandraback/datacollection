#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        string s;
        cin >> s;
        int swaps = 0;
        char last = s[s.size()-1];
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]){
                swaps++;
            }
        }
        cout << swaps + (last == '-' ? 1 : 0) << endl;
    }
}
