//
//  main.cpp
//  code_jam_q1
//
//  Created by Nolan Miller on 4/12/14.
//  Copyright (c) 2014 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>

using namespace std;

set<int> intersection(const set<int>& s1, const set<int> &s2){
    set<int> ret;
    set<int>::iterator it;
    for (it = s1.begin(); it!=s1.end(); it++) {
        if (s2.find(*it)!=s2.end()) {
            ret.insert(*it);
        }
    }
    return ret;
}

int ** new2di(int w, int h,int val){
    int ** ret = new int*[w];
    for (int x = 0; x<w; x++) {
        ret[x] = new int[h];
        for (int y = 0; y<h; y++) {
            ret[x][y] = val;
        }
    }
    return ret;
}
char ** new2dc(int w, int h,char val){
    char ** ret = new char*[w];
    for (int x = 0; x<w; x++) {
        ret[x] = new char[h];
        for (int y = 0; y<h; y++) {
            ret[x][y] = val;
        }
    }
    return ret;
}
//doesn't handle order correctly
void add_m(char** board,int w, int h){
    int x = w-1;
    int y = h-1;
    int px = x;
    int py = y;
    while (x>=0&&y>=0&&board[x][y] == '*') {
        if (x>y){
            px = x;
            x--;
        }
        else{
            py = y;
            y--;
        }
    }
    int tx = px;
    int ty = py;
    while (ty>=0&&tx>=0&&board[tx][ty] == '*') {
        if (px>py) {
            ty--;
        }
        else{
            tx--;
        }
    }
    if (ty<0||tx<0) {
        board[x][y] = '*';
    }
    else{
        board[tx][ty] = '*';
    }
}
void print_b(char** board, int w, int h,bool rotate){
    if (!rotate) {
        for (int y = 0; y<h; y++) {
            for (int x = 0; x<w; x++) {
                cout<<board[x][y];
            }
            if (y!=h-1) {
                cout<<endl;
            }
        }
    }
    else{
        for (int x = 0; x<w; x++) {
            for (int y = 0; y<h; y++) {
                cout<<board[x][y];
            }
            if (x!=w-1) {
                cout<<endl;
            }
        }
    }
}
//bug where it will overfill (fills even if adjacent)
void flood_board(char** board,int w, int h, int x, int y){
    if (x<w && y <h && y>=0 && x>=0) {
        if (board[x][y]==0||board[x][y]=='C') {
            //can optimize to only epand down and to the right because of start.
//            flood_board(board, w, h, x+1, y-1);
            flood_board(board, w, h, x+1, y);
            flood_board(board, w, h, x+1, y+1);
//            flood_board(board, w, h, x, y-1);
            
            flood_board(board, w, h, x, y+1);
//            flood_board(board, w, h, x-1, y-1);
//            flood_board(board, w, h, x-1, y);
//            flood_board(board, w, h, x-1, y+1);
        }
        if (board[x][y]!='*'&&board[x][y]!='C'&&board[x][y]!='c') {
            board[x][y] = '.';
        }
        if (board[x][y]=='C') {
            board[x][y] = 'c';
        }

    }
}

bool board_works(char** board,int w,int h){
    flood_board(board, w, h, 0, 0);
    for (int x = 0; x<w; x++) {
        for (int y =0; y<h; y++) {
            if (board[x][y]==0) {
                return false;
            }
        }
    }
    return true;
}

bool solvable(int w, int h, int s){
    assert(w<=h);
    if (w == 1) {
        return true;
    }
    if (w == 2 && s ==2) {
        return false;
    }
    if (w==2 && s == 1) {
        return true;
    }
    if (w == 2) {
        return !(s%2);
    }
    if (s == 2 || s==3 || s==5 || s==7) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) {
        int r,c,m;
        cin>>r>>c>>m;
        int w = c;
        int h = r;
        bool rotate = false;
        if (w>h) {
            int t = w;
            w = h;
            h = t;
            rotate = true;
        }
        int s = w*h-m;
        cout<<"Case #"<<i+1<<": "<<endl;
        
        if (!solvable(w,h, s)) {
            cout<<"Impossible";
        }
        else{
            char ** ary = new2dc(w,h, 0);
            ary[0][0] = 'c';
            if (s == 1) {
                for (int x = 0; x<w; x++) {
                    for (int y = 0; y<h; y++) {
                        ary[x][y] = '*';
                    }
                }
                ary[0][0] = 'c';
            }
            else if (w == 1) {
                for (int i = 1; i<h; i++) {
                    ary[0][i] = (i<s)?'.':'*';
                }
            }
            else if (w == 2) {
                ary[1][0] = '.';
                for (int i = 1; i<h; i++) {
                    ary[0][i] = ary[1][i] = (i<(s/2))?'.':'*';
                }
            }
            else if (s == 4){
                for (int x = 0; x<w; x++) {
                    for (int y = 0; y<h; y++) {
                        ary[x][y] = '*';
                    }
                }
                ary[0][0] = 'c';
                ary[1][0] = '.';
                ary[1][1] = '.';
                ary[0][1] = '.';
            }
            else if (s == 6){
                for (int x = 0; x<w; x++) {
                    for (int y = 0; y<h; y++) {
                        ary[x][y] = '*';
                    }
                }
                ary[0][0] = 'c';
                ary[1][0] = '.';
                ary[1][1] = '.';
                ary[0][1] = '.';
                ary[2][0] = '.';
                ary[2][1] = '.';
            }
            else{
                assert(s>=8);
                assert(w>=3);
                assert(h>=3);
                for (int x = 0; x<w; x++) {
                    for (int y = 0; y<h; y++) {
                        ary[x][y] = '*';
                    }
                }
                ary[0][0] = 'c';
                ary[1][0] = '.';
                ary[1][1] = '.';
                ary[0][1] = '.';
                ary[2][0] = '.';
                ary[2][1] = '.';
                s-=6;
                int y = 2;
                while (s>1&&y<h) {
                    if (y<h) {
                        ary[0][y] = '.';
                        ary[1][y] = '.';
                        s-=2;
                        y++;
                    }
                }
//                if (s == 1) {
//                    ary[2][2] = '.';//done
//                    s--;
//                }
                int x = 3;
                while (s>1&&x<w) {
                    if (x<w) {
                        ary[x][0] = '.';
                        ary[x][1] = '.';
                        s-=2;
                        x++;
                    }
                }
                x = 2;
                y = 2;
                while (s>0) {
                    ary[x][y] = '.';
                    s--;
                    x++;
                    if (x>=w) {
                        x = 2;
                        y++;
                    }
                }
            }
            print_b(ary, w, h,rotate);
        }
        
        
        if(i+1!=n)
            cout<<endl;
    }
    return 0;
}
