/*
  Name:         Fractiles.cpp
  Author:       Dean Hirsch
  Date:         April 9th, 2016
  Description:  Solution to Google Code Jam's 2016 qualification round
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INPUT_FILENAME      "D-large.in"
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
            for(unsigned i=0; i < ret.size(); i++){
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


/**
 * Algorithm:
 *
 * It can be seen that we only need to consider
 * the starting positions with only a single G.
 *
 * If a single G started in position p, when positions
 * are numbered from 0 to (K-1), then it is seen that
 * the tiles in complexity C that will be G are exactly
 * those with p as one of their digits in base-K representation,
 * with leading zeros to make them C-digits long.
 *
 * Therefore we need to find a subset of the K^C numbers representing
 * the positions in complexity C so that any digit appears in
 * on of the numbers, in base-K representation.
 *
 * So we take the numbers (in base K):
 * first:     0 1 2 3 .. (C-1)
 * second:    C C+1 C+2 .. (2C-1)
 * ...
 * nth:       (n-1)C (n-1)C+1 .. (nC-1)
 *
 * up until n = ceil(K/C), and when we run out of
 * digits we simply pad with more (K-1) digits.
 *
 * Therefore it is impossible if and only if S < ceil(K/C)
 */
vector<u64> compute(u64 K, u64 C, u64 S)
{
    vector<u64> ret;
    if(S < (K+C-1)/C){
        return ret; // IMPOSSIBLE (return empty vector)
    }
    bool done=false;

    for(unsigned i=0; !done;){
        u64 val=0;
        for(unsigned j=0; j < C; j++){
            val = (val*K)+i;
            if(i<K-1){
                i++;
            } else{
                done = true;
            }
        }
        ret.push_back(val+1);
    }
    return ret;
}


