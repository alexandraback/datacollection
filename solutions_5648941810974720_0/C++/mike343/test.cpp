#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<queue>
#include<bitset>
#include<assert.h>
using namespace std;


string getResult(string input) {
    vector<int> result(10, 0);
    map<char, int> content;
    map<char, string> remove;
    remove['Z'] = "ZERO";
    remove['W'] = "TWO";
    remove['U'] = "FOUR";
    remove['X'] = "SIX";
    remove['V'] = "SEVEN";
    remove['G'] = "EIGHT";
    remove['H'] = "THREE";
    remove['O'] = "ONE";
    remove['F'] = "FIVE";
    remove['N'] = "NINE";
    string seq = "ZWUXGHOFVN";
    map<char, int> convert;
    convert['Z'] = 0;
    convert['W'] = 2;
    convert['H'] = 3;
    convert['U'] = 4;
    convert['X'] = 6;
    convert['V'] = 7;
    convert['G'] = 8;
    convert['O'] = 1;
    convert['F'] = 5;
    convert['N'] = 9;
    for (char c: input) {
        content[c]++;
    }
    for (char x : seq) {
        int index = convert[x];
        while(content[x] > 0) {
            result[index]++;
            for (char c : remove[x])
                content[c]--;
        }
    }

    string ans;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < result[i]; j++) {
            ans += to_string(i);
        }
    }
    return ans;
}

int main() {

   int numCase = 1000000;
    cin >> numCase; 
    for (int i = 0; i < numCase; i++) {
        string str;
        cin >> str;
        cout <<"Case #"<<(i+1)<<": ";
        cout <<getResult(str)<< endl; 
    }
}
