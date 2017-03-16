//
//  main.cpp
//  pancakes
//
//  Created by Estelle :) on 9/4/16.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ", i);
        char pan[105];
        scanf("%s", pan);
        int flip = 1;
        for (int j=1; j<strlen(pan); j++) {
            if (pan[j]!=pan[j-1]) flip++;
        }
        if (pan[strlen(pan)-1]=='+') flip--;
        printf("%d\n", flip);
    }
}
