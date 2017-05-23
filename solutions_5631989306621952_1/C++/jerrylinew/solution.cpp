//
//  main.cpp
//  Google Code Jam - Round 1A
//
//  Created by Jerry Li on 4/15/16.
//  Copyright © 2016 Jerry Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    
    ifstream fin("Alarge.in");
    ofstream fout("Alarge.out");
    
    int t;
    fin >> t;
    string temp;
    char c;
    string current = "";
    bool found = false;
    
    for(int i = 0; i < t; i++){
        fin >> temp;
        
        for(int k = 0; k < temp.size(); k++){
            c = temp[k];
            
            if(current.size() == 0){
                current += c;
                continue;
            }
            
            if(c < current[0])
                current += c;
            else if(c > current[0])
                current = c + current;
            else{
                found = false;
                for(int j = 1; j < current.size(); j++){
                    if(c < current[j]){
                        current += c;
                        found = true;
                        break;
                    }
                    else if(c > current[j]){
                        current = c + current;
                        found = true;
                        break;
                    }
                }
                if(!found)
                    current += c;
            }
        }
        fout << "Case #" << i + 1 << ": " << current << endl;
        current = "";
    }

    return 0;
}

