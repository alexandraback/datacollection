#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    //1 100
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cout << "Case #" << cas << ": ";
        //small 1 16 large 1 1e3
        int N;
        cin >> N;
        set<string> word1s, word2s;
        for(int i = 0; i < N; i++){
            string word1, word2;
            cin >> word1 >> word2;
            word1s.insert(word1);
            word2s.insert(word2);
        }
        int m = max(word1s.size(), word2s.size());
        if(m < N){
            cout << N - m << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
