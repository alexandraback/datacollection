//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int SIZE = 60;
int R, C;
char grid[SIZE][SIZE];

void mineFill(int R2, int R1, int C2, int C1, int m) {
    
    for(int r = R2 ; r >= R1 ; r--)
        for(int c = C2 ; c >= C1 ; c--){
            if(m){
                grid[r][c] = '*';
                m--;
            }
        }
}

void print() {
    for(int i = 0 ; i < R ; i++) {
        for(int j = 0 ; j < C ; j++)
            cout << grid[i][j];
        cout << endl;
    }
}


int table[SIZE][SIZE][SIZE*SIZE];
int choice[SIZE][SIZE][SIZE*SIZE];
int get(int RR, int CC, int M){
    
    if(table[RR][CC][M] != -1)
        return table[RR][CC][M];
    
    if(RR*CC-2*RR-2*CC+4 >= M){
        choice[RR][CC][M] = 0;
        return table[RR][CC][M] = 1;
    }
    
    int res = 0, cho = -1;
    
    if (CC > 2 && M >= RR) {
        if(get(RR, CC-1, M-RR)){
            res = 1;
            cho = 2;
        }
    }
    
    //take a row
    if(RR > 2 && M >= CC){
        if(get(RR-1, CC, M-CC)){
            res = 1;
            cho = 1;
        }
    }
    
    choice[RR][CC][M] = cho;
    return table[RR][CC][M] = res;
}

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/C-small-attempt1.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/C-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out.large", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        int M;
        cin >> R >> C >> M;
        cerr << t << ": " << R << " " << C << " " << M << endl;
        cout << "Case #" << t << ":" << endl;
        
        for(int i = 0 ; i < R ; i++)
            for(int j = 0 ; j < C ; j++)
                grid[i][j] = '.';
        grid[0][0] = 'c';
        
        //no mine/all mine or single row/col
        if(M == R*C-1 || !M || R == 1 || C == 1){
            mineFill(R-1, 0, C-1, 0, M);
            print();
            continue;
        }
        
        if(R*C-M < 4){
            cout << "Impossible" << endl;
            continue;
        }
        
        memset(table, -1, sizeof table);
        memset(choice, -1, sizeof choice);
        if(!get(R, C, M)){
            cout << "Impossible" << endl;
        } else {
            int RR = R, CC = C;
            while(M) {
                int cho = choice[RR][CC][M];
                switch(cho){
                    case 0:
                        mineFill(RR-1, 2, CC-1, 2, M);
                        M = 0;
                        break;
                    case 1:
                        mineFill(RR-1, RR-1, CC-1, 0, CC);
                        RR--;
                        M -= CC;
                        break;
                    case 2:
                        mineFill(RR-1, 0, CC-1, CC-1, RR);
                        CC--;
                        M -= RR;
                        break;
                    default:
                        cerr << "ERROR" ;
                        return 0;
                }
            }
            print();
        }
    }
    
    return 0;
}

