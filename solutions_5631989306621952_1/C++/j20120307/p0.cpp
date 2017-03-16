#include <iostream>
#include <unordered_set>
#include "string"

using namespace std;

string lastword(string word) {
    if (word.size() == 1)   return word;
    string result;
    result.push_back(word[0]);
    for (int i=1; i!=word.size(); i++) {
        if (word[i]<result[0])
            result.push_back(word[i]);
        else
            result.insert(0,1,word[i]);
    }
    return result;
}

int main(){
    int T, id = 1;
    string word;
    cin >> T;
    while (T--) {
        cout << "Case #" << id << ": ";
        cin >> word;
		id++;
        cout << lastword(word) << endl;
    }
    
    return 0;
}