//
//  main.cpp
//  zadA
//
//  Created by Tomasz Krzyżek on 5/12/13.
//  Copyright (c) 2013 Tomasz Krzyżek. All rights reserved.
//

#include <iostream>
#include <string>

#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char x);
bool isOK(int tab[], int begin, int end, int n);

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP(x, T){
        string name;
        cin >> name;
        int n;
        cin >> n;
        int size = name.size();
        int *word = new int[size];
        REP(i, size){
            if(isVowel(name[i])){
                word[i] = 0;
            }
            else{
                word[i] = 1;
            }
        }
        int counter = 0;
        REP(i, size){
            REP(j, size-i){
                if(isOK(word, i, i+j, n)){
                    counter++;
                }
            }
        }
        cout << "Case #" << x+1 << ": " << counter << endl;
    }
    return 0;
}

bool isVowel(char x){
    bool isV = 0;
    REP(i, 5){
        if(x == vowels[i]){
            isV = 1;
            break;
        }
    }
    return isV;
}

bool isOK(int tab[], int begin, int end, int n){
    bool ok = 0;
    int it = 0;
    while(begin <= end){
        if(tab[begin] == 1)
            it++;
        else
            it = 0;
        if(it >= n){
            ok = 1;
            break;
        }
        begin++;
    }
    return ok;
}

