//
//  main.cpp
//  Fractiles
//
//  Created by Hong Eunpyeong on 2016. 4. 9..
//  Copyright © 2016년  Hong Eunpyeong. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int sq(int b, int e){
    int tmp = b;
    for(int i = 0; i < e; i++){
        b = tmp * e;
    }
    return b;
}

long bot(long from, long top, long K, long C){
    long lev = 1;
    long r = from;
    
    while(lev < C){
        r = (r-1)*K;
        from++;
        if(from > top) from = top;
        r += from;
        lev++;
    }
    
    return r;
}

int main(int argc, const char * argv[]) {
    long tc, K, C, S;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> tc;
    long res[100];
    
    for(int i = 0; i < tc; i++){
        fin >> K >> C >> S;
        
        for(int j = 0; j < K; j++) res[j] = 0;
        
        long top;
        if(C > K) top = K;
        else top = C;
        long from = 1;
        int k = 0;
        int s = 0;
        while(true){
            if(top >= K) {
                top = K;
                res[k++] = bot(from, top, K, C);
                s++;
                break;
            } else {
                res[k++] = bot(from, top, K, C);
                from = top+1;
                top += C;
                s++;
            }
            
        }
        fout << "Case #" << i+1 << ": ";
        if(s > S) fout << "IMPOSSIBLE\n";
        else{
            for(int j = 0; j < s; j++){
                fout << res[j] << " ";
            }
            fout << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
