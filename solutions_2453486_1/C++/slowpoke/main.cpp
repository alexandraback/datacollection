//
//  main.cpp
//  CodeJam
//
//  Created by Janice Deceline on 2013-04-09.
//  Copyright (c) 2013 Janice Deceline. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    char p[2] = {'X','O'};
    
    int T;
    char c;
    cin >> T;
    
    for(int t=1; t<=T; ++t){
        int hor[2][4] = {};
        int ver[2][4] = {};
        int diag[2][2] = {};
        bool foundSpace = false;
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                cin >> c;
                int val[2] = {};
                if(c==p[0]){
                    val[0] = 1;
                }else if(c==p[1]){
                    val[1] = 1;
                }else if(c=='T'){
                    val[0] = val[1] = 1;
                }else if(c=='.'){
                    foundSpace = true;
                    continue;
                }
                
                hor[0][i] += val[0];
                hor[1][i] += val[1];
                ver[0][j] += val[0];
                ver[1][j] += val[1];
                
                if(i==j){
                    diag[0][0] += val[0];
                    diag[1][0] += val[1];
                }
                if(i==3-j){
                    diag[0][1] += val[0];
                    diag[1][1] += val[1];
                }
            }
        }
        
        cout << "Case #" << t << ": ";
        int result = -1;
        for(int i=0; i<2; ++i){
            for(int j=0; j<4; ++j){
                if(hor[i][j] == 4 || ver[i][j] == 4){
                    result = i;
                    break;
                }
            }
            for(int j=0; j<2; ++j){
                if(diag[i][j] == 4){
                    result = i;
                    break;
                }
            }
        }
        
        if(result > -1){
            cout << p[result] << " won" << endl;
        }else if(foundSpace){
            cout << "Game has not completed" << endl;
        }else{
            cout << "Draw" << endl;
        }
        
    }
    
    return 0;
}

