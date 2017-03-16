//
//  main.cpp
//  Rank and File
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
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> tc;
    for(int i = 0; i < tc; i++){
        int N;
        fin >> N;
        int tmp[200][200];
        for(int j = 0; j < 2*N-1; j++){
            for(int k = 0; k < N; k++){
                fin >> tmp[j][k];
            }
        }
        int height[3000] = {0, };
        
        for(int j = 0; j < 2*N-1; j++){
            for(int k = 0; k < N; k++){
                height[tmp[j][k]]++;
            }
        }
        vector<int> res;
        for(int j = 0; j < 3000; j++){
            if(height[j] % 2 != 0){
                res.push_back(j);
            }
        }
        fout << "Case #" << i+1 << ": ";
        int min = res[0];
        for(int j = 0; j < res.size(); j++){
            for(int k = 0; k < res.size(); k++){
                if(min <= res[k]){
                    fout << res[k] << " ";
                    min = res[k]+1;
                    break;
                }
            }
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
