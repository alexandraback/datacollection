//
//  main4.cpp
//  CodeJam
//
//  Created by Victor Young on 4/9/16.
//  Copyright © 2016 Victor Young. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int T;

    if(freopen("/Users/Victor/Desktop/output.txt", "w", stdout) == NULL)
        fprintf(stderr,"error redirecting stdout\n");
    if(freopen("/Users/Victor/Desktop/D-small-attempt1.in", "r", stdin) == NULL)
        fprintf(stderr,"error redirecting stdin\n");
    cin >> T;
    int S,K,C;
    for (int i = 0 ; i<T; i++) {
        int visit[100];
        memset(visit, 0, 100*4);
        cin >> K >> C >> S;
        if (C*S<K) {
            cout << "Case #"<<i+1<<": IMPOSSIBLE";
            if (i!=T-1) {
                cout << endl;
            }
            continue;
        }
        int current = 0;
        cout << "Case #"<<i+1<< ":";
        while (current!=K) {

            long long choice=0;
            for (int j=0; j<C; j++) {
                if (current != K) {
                    current++;
                    //                break;
                }
                choice += (current-1)*(long long)pow(K,C-j-1);
            }
            cout << " " << choice+1;
        }

        if (i!=T-1) {
            cout << endl;
        }
    }
    

}