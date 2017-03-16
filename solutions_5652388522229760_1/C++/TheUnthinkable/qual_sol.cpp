/*
  Name:         qual_sol.cpp
  Author:       Dean Hirsch
  Date:         April 9th, 2016
  Description:  Solution to Google Code Jam's 2016 qualification round
*/

#include <iostream>
#include <fstream>

using namespace std;

#define INPUT_FILENAME      "A-large.in"
#define OUTPUT_FILENAME     "output.out"

int compute(int n);

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
        int curr_test;
        fin >> curr_test;
        int ret = compute(curr_test);

        cout << "Case #" << line_num << ": ";
        fout << "Case #" << line_num << ": ";
        if(ret < 0){
            cout << "INSOMNIA\n";
            fout << "INSOMNIA\n";
        }
        else{
            cout << ret << "\n";
            fout << ret << "\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}

#define BASE 10
// return -1 if impossible
int compute(int n){
    if(n==0){
        return -1; // easy to prove that it is impossible iff n==0
    }
    bool is_seen[BASE];
    int i;
    for(i=0; i < BASE; i++){
        is_seen[i] = false;
    }

    int curr = n, temp;
    while(true){
        temp = curr;
        do{
            is_seen[temp%BASE] = true;
            temp /= BASE;
        }while(temp);

        for(i=0; i < BASE; i++){
            if(!is_seen[i]){
                break;
            }
        }
        if(i == BASE){
            break;
        }

        curr += n;
    }

    return curr;
}
