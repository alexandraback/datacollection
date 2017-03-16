#include<iostream>
#include<vector>
#include "poly.h"
using namespace std;
vector<vector<vector<string> > > poly;
vector<vector<string> > p;

vector<vector<int> > moves = {{-1,0},{1,0},{0,-1},{0,1}};

void print(vector<vector<bool> > board) {
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) cout<<board[i][j] ?'#' : '.';
        cout<<endl;
    }
    cout<<"--\n";
}

void print(vector<string> board) {
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) cout<<board[i][j];
        cout<<endl;
    }
    cout<<"--\n";
}

int fill(vector<vector<bool>>& board, int x, int y) {
    if(board[x][y]) return 0;
    board[x][y]=true;
    int ans = 1;
    for(int i=0;i<4;i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if(nx>=0 && ny >= 0 && nx < board.size() && ny < board[0].size()) ans += fill(board,nx,ny);
    }
    return ans;
}

bool impossible(vector<string>& piece, int x, int y, int w, int h, int modulo) {
    int pw = piece.size();
    int ph = piece[0].size();
    if(pw+x > w || ph + y > h) return true;
    vector<vector<bool> > board(w, vector<bool>(h,0));
    for(int i=0;i<pw;i++) for(int j=0;j<ph;j++) if(piece[i][j]=='#') board[i+x][j+y]=true;
    for(int i=0;i<w;i++) {
        for(int j=0;j<h;j++) {
            if(fill(board,i,j) % modulo != 0) return true;
        }
    }
    return false;
    
}

int f() {
    int x,r,c;
    cin>>x>>r>>c;
    
    if(x>=7) return 0;
    p = poly[x];

    for(int i=0;i<p.size();i++) {
        bool impos = true;
        for(int X=0;X<r;X++) {
            for(int Y=0;Y<c;Y++)
                if(!impossible(p[i],X,Y,r,c,x) || !impossible(p[i],X,Y,c,r,x)) impos = false;
        }
        if(impos) return 0;
        
    }
    return 1;
    

}


int main() {
    poly = polys();
    string s[] = {"RICHARD","GABRIEL"};
    int t=0;
    cin>>t;
    for(int i=1;i<=t;i++) cout<<"Case #"<<i<<": "<<s[f()]<<endl;

}
