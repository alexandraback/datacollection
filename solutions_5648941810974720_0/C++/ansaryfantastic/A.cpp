#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string ids[] = {"Z", "ENO", "W", "HR", "U", "F", "X", "S", "G", "I"};

int count(string s, int len, int k){
    if (k == 3) return 0;

    string id = ids[k];
    int count = 0;
    if (k != 1)
    for (int i = 0; i < len; i++){
        if (s[i] == id[0]) count++;
    }
    else{
        for (int i = 0; i < len; i++){
            if (s[i] == 'O'){
                for (int j = 0; j < len; j++){
                    if (s[j] == 'N'){
                        for (int k = 0; k < len; k++){
                            if (s[k] == 'E'){
                                s[j] = s[k] = '.';
                                count++;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    return count;
}

string answer(string s){
    int len = s.length();
    string zero = "";
    string two = "";
    string ansG3 = "";

    int t  = -1;

    for (int i = 0; i < 10; i++){
        if (i == 3 || i == 1) continue;

        int c = count(s, len, i);
        for (int j = 0; j < c; j++){
            if (i == 0) zero += '0' + i;
            else if (i == 2) two += '0' + i;
            else ansG3 += '0' + i;

            int l2 = numbers[i].length();
            for (int k = 0; k < l2; k++){
                for (int l = 0; l < len; l++){
                    if (s[l] == numbers[i][k]){
                        s[l] = '.';
                        break;
                    }
                }
            }
        }

    }

    int threes = 0;
    int ones = 0;

    for (int i = 0; i < len; i++){
        if (s[i] == 'H') threes++;
        if (s[i] == 'N') ones++;
    }

    string ansOne = "";
    string ansThree = "";
    for (int i = 0; i < ones; i++){
            ansOne += '0' + 1;
    }
    for (int i = 0; i < threes; i++){
        ansThree += '0' + 3;
    }

    return zero + ansOne + two + ansThree + ansG3;
}


int main(){
    ifstream cin("input.txt");
    ofstream cout ("output.txt");

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        cout << "Case #" << (i+1) << ": " << answer(s) << endl;
    }
    return 0;
}
