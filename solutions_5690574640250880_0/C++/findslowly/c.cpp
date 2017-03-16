#include <iostream> 
#include <fstream> 

using namespace std ; 
ifstream fin("C-small-attempt0.in"); 
ofstream fout("A-small-attempt0.out"); 

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0} ; 
const int dy[8] = {1, 0, -1, 1, 1 , 0, -1, -1} ; 

int map[50][50] ;
bool visited[50][50] ; 
int r,c,m ; 

int neighbor(int x, int y) {
    int newx, newy, sum ; 
    sum = 0 ; 
    for (int i = 0 ; i < 8; ++i) {
        newx = x + dx[i] ; 
        newy = y + dy[i] ; 
        if (newx < r && newx > -1 && newy < c && newy > -1 && map[newx][newy] == 1)  
            ++sum ; 
    }
    return sum ; 
}

void sweep(int x, int y) {
    if (x > r-1 || x < 0 || y > c-1 || y < 0)
        return ; 
    if (map[x][y] == 1) 
        return ; 
    if (visited[x][y]) 
        return ; 

    visited[x][y] = true ; 
    if (neighbor(x,y) == 0) 
        for (int i = 0; i < 8; ++i) 
            sweep(x+dx[i],y+dy[i]) ; 
}

bool allvisited() {
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 
            if (map[i][j] == 0 && !visited[i][j]) 
                return false ; 
    return true ; 
}

bool check() {
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 
            if (map[i][j] == 0 ) {
                map[i][j] = 2 ; 
                for (int p = 0; p < r; ++p)
                    for (int q = 0; q < c; ++q) 
                        visited[p][q] = false ; 
                sweep(i,j) ; 
                if (allvisited()) 
                    return true ; 
                else 
                    map[i][j] = 0 ; 
            }
    return false ; 
}

bool search(int x, int y, int mine) {
    if (mine == m) { 
        if (check()) 
            return true ; 
        else 
            return false ;
    } 

    if (y == c) {
        y = 0 ; 
        x = x+1; 
    }
    if (x == r) 
        return false ; 

    map[x][y] = 1 ; 
    if (search(x,y+1,mine+1)) 
        return true ; 
    else {
        map[x][y] = 0 ; 
        return search(x,y+1,mine) ; 
    }
}

int main() {
    int T ; 
    fin >> T ; 
    for (int num = 1; num < T+1; ++num) {
        fin >> r >> c >> m ; 
        fout << "Case #" << num << ":" << endl ; 

        for (int i = 0; i < r; ++i) 
            for (int j = 0; j < c; ++j) 
                map[i][j] = 0 ; 

        if (search(0,0,0)) {
            for (int i = 0; i < r; ++i) { 
                for (int j = 0; j < c; ++j) { 
                    if (map[i][j] == 0) 
                        fout << "." ; 
                    if (map[i][j] == 1) 
                        fout << "*" ; 
                    if (map[i][j] == 2) 
                        fout << "c" ; 
                } 
                fout << endl ; 
            }
        }
        else 
            fout << "Impossible" << endl ; 


    }
    return 0 ; 
}
