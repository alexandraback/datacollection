#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T;
vector<int> number(10);
vector<int> letter(26);
vector<string> s(10);
string ss;

int get(string s){
    int count = 20000;
    vector<int> lets(26);
    for(int i = 0; i < 26; i++)
        lets[i] = 0;

    for(int i = 0; i < s.length(); i++)
        lets[(int)s[i] - (int)'A']++;

    for(int i = 0; i < 26; i++){
        if (lets[i] != 0 && letter[i]/lets[i] < count)
            count = letter[i]/lets[i];
    }
    for(int i = 0; i < 26; i++)
        letter[i] -= lets[i]*count;
    return count;
}

int main() {
    ifstream in("A-small.in");
    ofstream out("output.out");

    in >> T;

    s[0] = "ZERO";
    s[1] = "ONE";
    s[2] = "TWO";
    s[3] = "THREE";
    s[4] = "FOUR";
    s[5] = "FIVE";
    s[6] = "SIX";
    s[7] = "SEVEN";
    s[8] = "EIGHT";
    s[9] = "NINE";
    getline(in,ss);
    for(int cases = 1; cases <=T; cases++){
        getline(in,ss);
        for(int i = 0; i < 26; i++)
            letter[i] = 0;
        for(int i = 0; i < ss.length(); i++)
            letter[(int)ss[i]-(int)'A']++;
        number[0] = get(s[0]);
        number[2] = get(s[2]);
        number[6] = get(s[6]);
        number[8] = get(s[8]);
        number[4] = get(s[4]);
        number[1] = get(s[1]);
        number[3] = get(s[3]);
        number[5] = get(s[5]);
        number[7] = get(s[7]);
        number[9] = get(s[9]);
        out << "Case #" << cases << ": ";
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < number[i]; j++)
                out << i;
        }
        out << endl;
    }

    in.close();
    out.close();
}