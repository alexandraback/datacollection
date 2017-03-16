//
//  main2.cpp
//  CodeJam
//
//  Created by Victor Young on 4/9/16.
//  Copyright © 2016 Victor Young. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
//    if(freopen("/Users/Victor/Desktop/output.txt", "w", stdout) == NULL)
//        fprintf(stderr,"error redirecting stdout\n");
//    if(freopen("/Users/Victor/Desktop/B-large.in", "r", stdin) == NULL)
//        fprintf(stderr,"error redirecting stdin\n");
    
    cin>>n;
    char a;
    char last;
    string line;
    getline(cin,line);
    for (int i = 0; i<n; i++) {
        getline(cin, line);
        last = line[0];
        int times = 0;
        for (int j=0; j<line.length(); j++) {
            if (last!=line[j]) {
                times++;
                last =line[j];
            }
        }
        if (line[line.length()-1]=='-') {
            times++;
        }
//        cin >>a;
//        last = a;
        cout << "Case #" << i+1 << ": "<<times;
//        cout << "    line:" << line;
        if (i!=n-1) {
            cout << endl;
        }
    }
}