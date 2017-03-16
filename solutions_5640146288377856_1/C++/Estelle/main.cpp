//
//  main.cpp
//  battleship
//
//  Created by Estelle :) on 10/5/15.
//  Copyright (c) 2015 AWESOMENESS. All rights reserved.
//

#include <iostream>
using namespace std;
int t,r,c,w;

int main() {
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        scanf("%d%d%d", &r, &c, &w);
        int ans=0;
        for (int j=w-1; j<c; j+=w) {
            int g=(j+1)/w;
            if (j+1>=c||j-1<0) ans=max(ans,g+w-1);
            else ans=max(ans,g+w);
        }
        printf("Case #%d: %d\n", i+1, ans+(c/w)*(r-1));
    }
}
