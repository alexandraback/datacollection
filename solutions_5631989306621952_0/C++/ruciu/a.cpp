#include<iostream>
#include<string>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for(int n=0;n<tests;++n) {
        string letters;
        cin >> letters;
        string anwser = "";
        anwser += letters[0];
        for(int k=1;k<letters.length();k++) {
            if((int)letters[k]>=(int)anwser[0]) {
                anwser = letters[k] + anwser;
            } else {
                anwser += letters[k];
            }
        }
        cout << "Case #" << n+1 << ": " << anwser << endl;
    }
}