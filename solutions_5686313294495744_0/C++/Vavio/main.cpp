//
//  main.cpp
//  CountingSheep
//
//  Created by TT on 09/04/2016.
//  Copyright © 2016 TT. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <unordered_set>


#define READ_FROM_CONSOLE 0
#define ULL_MAX
using namespace std;

typedef unsigned long long ull;

ifstream fin("C-small-attempt2.in");
ofstream fout("C-small.out");

int N;
string *w1, *w2;
bool *dupl;


void fMain(int t){
    if (READ_FROM_CONSOLE){
        cin >> N;
    } else {
        fin >> N;
    }
    int origN = N;
    dupl = new bool[N];
    memset(dupl, false, 0);
    w1 = new string[N];
    w2 = new string[N];
    unordered_map<string, int> words, secondWord;
    
    
    if (READ_FROM_CONSOLE){
        for (int i=0; i<N; ++i){
            cin >> w1[i] >> w2[i];
            
            words[w1[i]]++;
            words[w2[i]]++;
            secondWord[w2[i]]++;
        }
    } else {
        for (int i=0; i<N; ++i){
            fin >> w1[i] >> w2[i];
            
            words[w1[i]]++;
            words[w2[i]]++;
            secondWord[w2[i]]++;
        }
    }
    
    int newN = N;
    
    for (int i=0; i<newN; ++i){
        if (secondWord[w2[i]] == 1){
            swap(w1[i], w1[newN-1]);
            swap(w2[i], w2[newN-1]);
            
            newN--;
            i--;
        }
    }
    N = newN;
    
    for (int i=0; i<newN; ++i){
        if (words[w1[i]] == 1){
            swap(w1[i], w1[newN-1]);
            swap(w2[i], w2[newN-1]);
            
            newN--;
            i--;
        }
    }
    
    cout << newN << endl;
    for (int i=0; i<newN; ++i){
        cout << '\t' << w1[i] << " " << w2[i] << endl;
    }

    words.clear();
    secondWord.clear();
    
    for (int i = newN; i < origN; ++i){
        words[w1[i]]++;
        words[w2[i]]++;
        secondWord[w2[i]]++;
    }
    
    for (int i=0; i<newN; ++i){
        if (words[w1[i]] > 0 && secondWord[w2[i]] > 0){
            dupl[i] = true;
        }
    }
    
    int res = 0;
    for (int i=0; i<newN; ++i){
        if (dupl[i]){
            res ++;
        }
    }

    
    if (READ_FROM_CONSOLE){
        cout << "Case #" << t << ": " << res << endl;
    } else {
        fout << "Case #" << t << ": " << res << endl;
    }
}




int main(int argc, const char * argv[]) {
    int T;
    if (READ_FROM_CONSOLE){
        cin >> T;
    } else {
        fin >> T;
    }
    for (int t = 1; t <=T; ++t){
        fMain(t);
    }
    fin.close();
    fout.flush();
    fout.close();
    return 0;
}
