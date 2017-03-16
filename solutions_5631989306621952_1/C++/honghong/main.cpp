//
//  main.cpp
//  The Last Word
//
//  Created by Hong Eunpyeong on 2016. 4. 16..
//  Copyright © 2016년  Hong Eunpyeong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    int tc;
    string str;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> tc;
    for(int i = 0; i < tc; i++){
        fin >> str;
        vector<char> word;
        for(int j = 0; j < str.length(); j++){
            if(j == 0) word.push_back(str[j]);
            else{
                if(word[0] <= str[j]) word.insert(word.begin(), str[j]);
                else word.push_back(str[j]);
            }
        }
        fout << "Case #" << i+1 << ": ";
        for(int j = 0; j < word.size(); j++){
            fout << word[j];
        }
        fout << endl;
    }
    
    return 0;
}
