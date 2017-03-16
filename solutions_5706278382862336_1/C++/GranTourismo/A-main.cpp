//
//  A-main.cpp
//  Round 1C
//
//  Created by Ha Young Park on 5/11/14.
//  Copyright (c) 2014 Ha Young Park. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int cache[4096][4096];

int ancestor(long long p, long long q, int dim){
    if(dim > 40)
        return -1;
    if(q % 2)
        return -1;
    q /= 2;
    if(q < 1)
        return -1;
    
    if(p > q){
        if(ancestor(p-q, q, dim + 1) >= 0)
            return dim;
        else
            return -1;
    }
    else if(p==q)
        return dim;
    else
        return ancestor(p, q, dim + 1);
};

int main(int argc, const char * argv[])
{
    memset(cache, -1, sizeof(cache));
    ifstream fin;
    ofstream fout;
    fin.open("A-large.in");
    fout.open("A-large.out");
    int T;
    fin >> T;
    for(int i = 1; i <= T; i++){
        string Vida;
        fin >> Vida;
        
        long long P = stoll(Vida.substr(0, Vida.find("/")));
        long long Q = stoll(Vida.substr(Vida.find("/")+1));

        int ret = ancestor(P, Q, 1);
        cout << "Case #" << i << ": ";
        fout << "Case #" << i << ": ";
        
        if(ret < 0){
            cout << "impossible";
            fout << "impossible";
        }
        else{
            cout << ret;
            fout << ret;
        }
        cout << endl;
        fout << endl;
    }
    
    fout.close();
    fin.close();
    return 0;
}
