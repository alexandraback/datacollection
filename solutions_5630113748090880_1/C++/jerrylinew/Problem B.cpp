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
    
    ifstream fin("Blarge.in");
    ofstream fout("Blarge.out");
    
    int t, grid_size, value;
    fin >> t;
    
    vector<int> vect(2501, 0);
    
    for(int i = 0; i < t; i++){
        fin >> grid_size;
        
        for(int j = 0; j < grid_size * grid_size * 2 - grid_size; j++){
            fin >> value;
            vect[value]++;
        }
        
        fout << "Case #" << i + 1 << ": ";
        
        for(int j = 1; j < 2501; j++){
            if(vect[j] % 2 != 0)
                fout << j << ' ';
        }
        fout << endl;
        
        vect.clear();
        vect.resize(2501, 0);
    }
    
    return 0;
}

