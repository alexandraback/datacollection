#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for(int i=0; i<t; i++){
        int n = 0;
        cin >> n;
        vector<pair<string, string>> words;
        map<string, int> hist1;
        map<string, int> hist2;
        for(int j=0; j<n; j++){
            string word1, word2;
            cin >> word1 >> word2;
            hist1[word1]++;
            hist2[word2]++;
            words.push_back({word1, word2});
        }
        int counter = 0;
        for(int j=0; j<n; j++){
            if(hist1[words[j].first]-1 > 0 && hist2[words[j].second]-1 > 0) counter++;
        }
        cout << "Case #" << i+1 << ": " << counter << endl;
    }
    return 0;
}
