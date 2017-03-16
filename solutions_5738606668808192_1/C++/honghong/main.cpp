//
//  main.cpp
//  Coin Jam
//
//  Created by Hong Eunpyeong on 2016. 4. 9..
//  Copyright © 2016년  Hong Eunpyeong. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

struct counter{
    bool c[30] = {0, };
    void up(){
        int i = 0;
        while(true){
            if(c[i]>0){
                c[i] = 0;
                i++;
            } else {
                c[i] = 1;
                break;
            }
        }
    }
    void init(){
        for(int i = 0; i < 30; i++) c[i] = 0;
    }
    int head(){
        int i = 29;
        while(true){
            if(c[i])
                return i+1;
            i--;
        }
    }
};


void print_coin(bool* coin, int N, int c){
    int g = 1;
    int r;
    for(int i = 1; i < N; i++){
        if(coin[i]){
            g = i;
            break;
        }
    }
    for(int i = 0; i < N; i++){
        cout << coin[i];
    }
    cout << " ";
    int tmp;
    for(int i = 2; i <= 10; i++){
        r = i;
        tmp = r;
        for(int j = 1; j < g; j++) r *= tmp;
        cout << 1+r << " ";
    }
    cout << endl;
}

void recur(bool* coin, int i, int g, int N, int* c){
    if(i+1+g >= N-1-g) return;
    for(int j = i+1; j < N; j++){
        if(coin[j+g]) break;
        coin[j] = 1;
        coin[j+g] = 1;
        print_coin(coin, N, (*c)++);
        coin[j] = 0;
        coin[j+g] = 0;
    }
    if(i-g != 0){
        coin[i] = 0;
        coin[i-g] = 0;
        coin[i] = 1;
        coin[i+g] = 1;
        recur(coin, i+g, g, N, c);
    } else{
        coin[i+1] = 1;
        coin[i+g+1] = 1;
        recur(coin, i+g+1, g, N, c);
    }
}

int main(int argc, const char * argv[]) {
    int tc, N, J;
    cin >> tc;
    cin >> N >> J;
    int c = 1;;
    bool coin[50] = {0, };
    counter count;
    int m = 0;
    coin[0] = 1;
    coin[N-1] = 1;
    for(int i = 1; i < N/2; i++){
        coin[i] = coin[N-1-i] = 1;
        print_coin(coin, N, c++);
        recur(coin, i, i, N, &c);
        for(int k = 1; k < N-1; k++) coin[k] = 0;
       
        
        
        //coin[i] = coin[N-1-i] = 0;
    }
    return 0;
}
