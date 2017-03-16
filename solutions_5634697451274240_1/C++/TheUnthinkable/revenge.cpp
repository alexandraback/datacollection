/*
  Name:         revenge.cpp
  Author:       Dean Hirsch
  Date:         April 9th, 2016
  Description:  Solution to Google Code Jam's 2016 qualification round
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INPUT_FILENAME      "B-large.in"
#define OUTPUT_FILENAME     "output.out"

int compute(string s);

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
        string curr_test;
        fin >> curr_test;
        int ret = compute(curr_test);

        cout << "Case #" << line_num << ": " << ret << "\n";
        fout << "Case #" << line_num << ": " << ret << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}


int compute(string s){
    int ret = (s[s.size()-1] == '-');
    for(unsigned i=1; i < s.size(); i++){
        if( s[i-1] != s[i] ){
            ret++;
        }
    }
    return ret;
}

