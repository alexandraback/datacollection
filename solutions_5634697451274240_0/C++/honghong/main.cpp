//
//  main.cpp
//  Revenge of Pancakes
//
//  Created by Hong Eunpyeong on 2016. 4. 9..
//  Copyright © 2016년  Hong Eunpyeong. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;


int recur(bool* stack, int n, bool a, int r){
    bool first = stack[n];
    
    for(int j = n-1; j >= 0; j--){
        if(stack[j] != first){
            if(first == a){
                return recur(stack, j, a, r);
            } else{
                return 1+recur(stack, j, !a, r);
            }
        }
    }
    if(first == a) return 0;
    else{
        for(int j = n-1; j >= 0; j--){
            stack[j] = a;
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    int tc;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> tc;
    
    bool stack[150];
    string str;
    for(int i = 0; i < tc; i++){
        fin >> str;
        int n, r;
        n = (int)str.length();
        for(int j = 0; j < n; j++){
            if(str[j] == '+') stack[j] = true;
            else stack[j] = false;
        }
        
        
        r = recur(stack, n-1, true, 0);
        fout << "Case #" << i+1 << ": ";
        fout << r << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
