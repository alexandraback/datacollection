//
//  main.cpp
//  tictactomac
//
//  Created by Nolan Miller on 4/12/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <sstream>	//string manipulation
#include <vector>	//dynamic arrays
#include <algorithm>//useful algorithms (sort) etc
#include <climits>	//data type cap info
#include <cmath>    //mathematical operations

using namespace std;


string testBoard(char b[4][4]){

    for(int i = 0;i<4;i++){
        bool x = 1;
        bool o = 1;
        for(int ii = 0;ii<4;ii++){
            if (b[i][ii] == 'O' || b[i][ii] == '.') {
                x = 0;
            }
            if (b[i][ii] == 'X' || b[i][ii] == '.') {
                o = 0;
            }
        }
        if (x) {
            return "X won";
        }
        if (o) {
            return "O won";
        }
        x = 1;
        o = 1;
        for(int ii = 0;ii<4;ii++){
            if (b[ii][i] == 'O' || b[ii][i] == '.') {
                x = 0;
            }
            if (b[ii][i] == 'X' || b[ii][i] == '.') {
                o = 0;
            }
        }
        if (x) {
            return "X won";
        }
        if (o) {
            return "O won";
        }
        x = 1;
        o = 1;
        for(int i = 0; i<4;i++){
            if(b[i][i] == 'O' || b[i][i] == '.'){
                x = 0;
            }
            if(b[i][i] == 'X' || b[i][i] == '.'){
                o = 0;
            }
        }
        if (x) {
            return "X won";
        }
        if (o) {
            return "O won";
        }
        x=1;
        o=1;
        for(int i = 0; i<4;i++){
            if(b[3-i][i] == 'O' || b[3-i][i] == '.'){
                x = 0;
            }
            if(b[3-i][i] == 'X' || b[3-i][i] == '.'){
                o = 0;
            }
        }
        if (x) {
            return "X won";
        }
        if (o) {
            return "O won";
        }
    }
    for(int i = 0; i<4; i++){
        for(int ii = 0;ii<4;ii++){
            if(b[i][ii] == '.'){
                return "Game has not completed";
            }
        }
    }
    return "Draw";
}


int main(int argc, const char * argv[])
{
    int length;
    cin>>length;
    char board[4][4];

    for (int it=0; it<length; it++) {
        for (int i=0; i<4; i++) {
            for (int ii =0; ii<4; ii++) {
                cin>>board[i][ii];
            }
        }    
        cout<<"Case #"<<it+1<<": "<< testBoard(board) <<endl;
    }
    return 0;
}


