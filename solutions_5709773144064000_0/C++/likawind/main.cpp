//
//  main.cpp
//  B
//
//  Created by Zhou Sun on 4/11/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[])
{
    freopen("myfile1.txt","r",stdin);

    freopen("myfile.txt","w",stdout);
    int ts;
    cin>>ts;
    
    for (int tt=0; tt<ts; tt++) {
        double x,c,f;
        cin>>c>>f>>x; 
        double cur=0;
        double mi=1e10;
        double r=2;
        while (cur + x/r< mi) {
            if (cur + x/r< mi) {
                mi=cur+x/r;
            }
            cur+=c/r;
            r+=f;
        }
        printf("Case #%d: %.7f\n",tt+1, mi);

    }
    return 0;
}

