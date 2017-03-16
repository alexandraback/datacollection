#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int R, C, M;

struct xy {
    int x;
    int y;
};
    vector<xy> neigh(8);


bool valid(int i1, int j1) {
    if(i1>=0 && j1>=0 && i1 < R && j1 < C) return true;
    return false;
}

bool recur(vector<vector<char> > &board, int i, int j,int p) {



    if(p == R*C - M) return true;

    vector<int> use;
    int i1, j1;
    for(int k = 0; k < 8; k++) {
        i1 = i + neigh[k].x; 
        j1 = j + neigh[k].y;
        if(valid(i1,j1) &&  board[i1][j1] == '*')   {
            use.push_back(k);
            board[i1][j1] = '.'; 
            p++;
        }
    }
    if(p == R*C - M) return true;
    if(p <  R*C - M) {
        for(int t = 0; t < use.size(); t++) {
            int k = use[t];
            i1 = i + neigh[k].x; 
            j1 = j + neigh[k].y;
            if(recur(board, i1, j1, p)) return true;
        }
    }

    for(int t = 0; t < use.size(); t++) {
        int k = use[t];
        i1 = i + neigh[k].x; 
        j1 = j + neigh[k].y;
        board[i1][j1] = '*'; 
    }
    return false;

}



int main() {
    int T, N;
    neigh[0].x = -1;
    neigh[0].y = -1;
    neigh[1].x = -1;
    neigh[1].y =  0;
    neigh[2].x = -1;
    neigh[2].y =  1;
    neigh[3].x =  0;
    neigh[3].y =  1;
    neigh[4].x =  1;
    neigh[4].y =  1;
    neigh[5].x =  1;
    neigh[5].y =  0;
    neigh[6].x =  1;
    neigh[6].y = -1;
    neigh[7].x =  0;
    neigh[7].y = -1;

    string s;
    istringstream iss;
    string filename("C-small-attempt1.in");
    ifstream in(filename, ifstream::in);      
    if(!in){				              // ensure existence of file
        exit(-1);
    }
    getline(in, s);
    iss.str(s);
    iss >> T;	   


	for (int test = 1; test <= T; test++) {
        int ans = 0;
        getline(in, s);
        iss.clear();
        iss.str(s);
        iss >> R >> C >> M;	

        vector<vector<char> > board(R, vector<char>(C, '*'));
        int found = 0;
        if( R*C > M) {
        for(int i = 0; i < R; i++) {
            for(int j = i; j < C; j++) {
                board[i][j] = 'c';
                if(recur(board, i, j, 1)) {
                    found = 1;
                    break;
                }
                board[i][j] = '*';
            }
            if(found) break;
        }
        }



        printf("Case #%d:\n", test);
        if(!found) 
            printf("Impossible\n");
        else {
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    cout << board[i][j];
                }
                cout << endl;
            }
        }

    }
}
