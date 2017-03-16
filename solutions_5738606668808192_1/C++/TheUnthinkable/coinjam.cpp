/*
  Name:         coinjam.cpp
  Author:       Dean Hirsch
  Date:         April 9th, 2016
  Description:  Solution to Google Code Jam's 2016 qualification round
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define OUTPUT_FILENAME     "output.out"

#define N 32
#define J 500

bool advance(string& s);
void init(string& s);

int main()
{
    ofstream fout;
    fout.open(OUTPUT_FILENAME, ios::trunc);
    if(!fout.is_open()){
        cout << "Error: failed to open output file\n";
        return 1;
    }

    cout << "Case #1:\n";
    fout << "Case #1:\n";

    string s;
    init(s);
    unsigned i;
    for(i=0; i < J; i++){
        cout << s << " 3 4 5 6 7 8 9 10 11\n";
        fout << s << " 3 4 5 6 7 8 9 10 11\n";
        if(!advance(s)){
            if(i==J-1){
                cout << "Error: not enough!!\n";
                fout << "Error: not enough!!\n";
            }
        }
    }

    fout.close();
    return 0;
}


bool advance(string& s){
    unsigned i;
    for(i=2; i < N-2; i++){
        if(s[i]=='1' && s[i+1]=='0'){
            s[i+1]='1';
            s[i-1]='0';
            return true;
        }
    }
    unsigned count=0;
    for(i=2; i < N-2; i++){
        count += (s[i]=='1');
    }
    if(count >= N-5)
        return false;

    for(i=2; i < N-2; i++){
        s[i] = (i-2 < count+2 ? '1':'0');
    }
    return true;
}


void init(string& s){
    s = string(N,'0');
    s[0] = s[1] = s[N-2] = s[N-1] = '1';
}

