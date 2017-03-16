#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i =0;i!=n;i++){
        string word;
        cin >> word;
        string lastWord;
        lastWord.push_back(word[0]);
        for(int j=1;j!=word.size();j++){
            if(lastWord[0] <= word[j]){
                lastWord.insert(lastWord.begin(),word[j]);
                continue;
            }
            lastWord.push_back(word[j]);
        }
        cout << "Case #" << i+1 << ": " << lastWord << endl;
    }
    return 0;
}