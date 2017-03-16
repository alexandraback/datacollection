/*
  Author:       Dean Hirsch
  Date:         April 30th, 2016
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define DO(n) for(int i=0; i < n; i++)

using namespace std;

#define INPUT_FILENAME      "A-large.in"
#define OUTPUT_FILENAME     "output.out"

typedef unsigned long long int u64;

string compute(string letters);

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open(INPUT_FILENAME);
    if(!fin.is_open()){
        cout << "Error: failed to open input file\n";
        return 1;
    }
    fout.open(OUTPUT_FILENAME, ios::trunc);
    if(!fout.is_open()){
        cout << "Error: failed to open output file\n";
        return 1;
    }

    int T;
    fin >> T;
    for(int line_num=1; line_num<=T; line_num++){
        if(fin.eof()){
            cout << "Error: fewer lines than what was promised!\n";
            fout << "Error: fewer lines than what was promised!\n";
            break;
        }
        string letters;
        fin >> letters;
        string ret = compute(letters);
        cout << "Case #" << line_num << ": ";
        fout << "Case #" << line_num << ": ";

        cout << ret;
        fout << ret;

        cout << "\n";
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}

string compute(string letters)
{
    int digits[10];
    int let_count[300];

    DO(10){
        digits[i] = 0;
    }
    DO(300){
        let_count[i] = 0;
    }
    DO(letters.size()){
        let_count[(int)letters[i]]++;
    }
    //"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    // "ONE", "NINE"
    digits[0] = let_count['Z'];
    let_count['Z'] -= digits[0];
    let_count['E'] -= digits[0];
    let_count['R'] -= digits[0];
    let_count['O'] -= digits[0];

    digits[6] = let_count['X'];
    let_count['S'] -= digits[6];
    let_count['I'] -= digits[6];
    let_count['X'] -= digits[6];

    digits[2] = let_count['W'];
    let_count['T'] -= digits[2];
    let_count['W'] -= digits[2];
    let_count['O'] -= digits[2];

    digits[8] = let_count['G'];
    let_count['E'] -= digits[8];
    let_count['I'] -= digits[8];
    let_count['G'] -= digits[8];
    let_count['H'] -= digits[8];
    let_count['T'] -= digits[8];

    digits[3] = let_count['H'];
    let_count['T'] -= digits[3];
    let_count['H'] -= digits[3];
    let_count['R'] -= digits[3];
    let_count['E'] -= digits[3];
    let_count['E'] -= digits[3];

    digits[7] = let_count['S'];
    let_count['S'] -= digits[7];
    let_count['E'] -= digits[7];
    let_count['V'] -= digits[7];
    let_count['E'] -= digits[7];
    let_count['N'] -= digits[7];

    digits[5] = let_count['V'];
    let_count['F'] -= digits[5];
    let_count['I'] -= digits[5];
    let_count['V'] -= digits[5];
    let_count['E'] -= digits[5];

    digits[4] = let_count['F'];
    let_count['F'] -= digits[4];
    let_count['O'] -= digits[4];
    let_count['U'] -= digits[4];
    let_count['R'] -= digits[4];

    digits[1] = let_count['O'];
    let_count['O'] -= digits[1];
    let_count['N'] -= digits[1];
    let_count['E'] -= digits[1];

    digits[9] = let_count['I'];


    string ret = "";
    DO(10){
        ret += string(digits[i], i+'0');
    }
    return ret;
}


