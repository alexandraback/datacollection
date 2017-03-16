/*
  Name:         Fractiles-small.cpp
  Author:       Dean Hirsch
  Date:         April 9th, 2016
  Description:  Solution to Google Code Jam's 2016 qualification round
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INPUT_FILENAME      "D-small-attempt0.in"
#define OUTPUT_FILENAME     "output.out"

typedef unsigned long long int u64;

vector<u64> compute(u64 K, u64 C, u64 S);

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
        u64 K,C,S;
        fin >> K;
        fin >> C;
        fin >> S;
        vector<u64> ret = compute(K,C,S);
        cout << "Case #" << line_num << ": ";
        fout << "Case #" << line_num << ": ";

        if(ret.size() == 0){
            cout << "IMPOSSIBLE\n";
            fout << "IMPOSSIBLE\n";
        } else{
            for(unsigned i=0; i < S; i++){
                cout << (i==0?"":" ") << ret[i];
                fout << (i==0?"":" ") << ret[i];
            }
            cout << "\n";
            fout << "\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}



vector<u64> compute(u64 K, u64 C, u64 S)
{
    vector<u64> ret;

    u64 add, tmp;
    for(add=1, tmp=0; tmp<C-1; add *= K, tmp++); // calc add = K^(C-1)

    ret.push_back(1);

    for(unsigned i=0; i < S; i++){
        ret.push_back(ret.back() + add);
    }
    return ret;
}



