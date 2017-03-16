#include <iostream>
using namespace std;

int T;
int K, L, S;
string board;
int freq[26];
string target;

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> K >> L >> S >> board >> target;

        int most = S / L;

        for(int o=1; o<L; o++){
            if(target.substr(L-o) != target.substr(0, o))
                continue;
            most = 1 + (S - L) / (L - o);
        }

        memset(freq, 0, sizeof(freq));
        for(char c : board)
            freq[c-'A']++;

        double ev = S - L + 1;

        for(char c : target){
            if(!freq[c-'A'])    
                most = 0;
            ev *= freq[c-'A'] / double(K);
        }

        cout.precision(20);
        cout << "Case #" << t << ": " << most - ev << endl;
    }
}
