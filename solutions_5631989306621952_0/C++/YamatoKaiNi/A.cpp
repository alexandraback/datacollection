#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++){
        string word;
        cin >> word;
        vector<string> words;
        words.push_back("");
        for (int i = 0; i < word.size(); i++){
            vector<string> new_words;
            for (int j = 0; j < words.size(); j++){
                new_words.push_back(word[i] + words[j]);
                new_words.push_back(words[j] + word[i]);
            }
            words = new_words;
        }
        sort(words.begin(), words.end());
        printf("Case #%d: %s\n", test, words.back().c_str());
    }
    return 0;
}
