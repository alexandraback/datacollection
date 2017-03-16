
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
#include <cstring>
using namespace std;

typedef long double LD;

int C, R;

int dd[] = {-1, 0, 1};

int visited[101];

int map(int x, int y){
    return C*y + x;
}

bool bounds(int x, int y){
    if(x >= 0 && y >= 0 && x < C && y < R) return true;
    return false;
}

void buildOtherMask(int mask, int x, int y, int &otherMask) {
    bool dont = false;
    if(visited[map(x,y)]) return;
    visited[map(x,y)] = true;
    //cout << "x: " << x << " y: " << y << endl;
    if((mask&(1<<map(x,y))) == 0) otherMask = otherMask|(1<<map(x, y));
    //cout << r << " " << c << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //if(bounds(x+dd[i], y+dd[j])) cout << "pos: " << (1<<(map(x+dd[i], y+dd[j]))) << " and: " << ((1<<(map(x+dd[i], y+dd[j])))&mask) << endl;
            if(bounds(x+dd[i], y+dd[j]) && ((1<<(map(x+dd[i], y+dd[j])))&mask) != 0) dont = true;
            
        }
    }
    if(dont){
       return; 
    }else{
        //cout << "get here " << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(bounds(x+dd[i], y+dd[j])) buildOtherMask(mask, x+dd[i], y+dd[j], otherMask);
               
            }
        }
    }
}

bool check(int mask, int x, int y){
    //cout << "trying mask: " << mask << endl;
    int other = 0;
    for(int i = 0; i < 26; i++) visited[i] = false;
    if(mask&(1<<map(x,y))) return false;
    buildOtherMask(mask, x, y, other);
    //cout << other << endl;
    if((other|mask) == ((1<<(R*C)) - 1)){
        //cout << "found: " << other << " mask: " << mask << endl; 
        return true;
        
    }
    return false;
}   



void print(int mask, int x, int y, int casenum){
    //cout << mask << " x: " << x << " y: " << y <<endl;
    cout << "Case #" << casenum << ": " << endl;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            
            if((mask&(1<<map(j,i))) != 0){
                cout << '*';
            }else if(i == y && j == x){
                cout << 'c';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
}

int N;
int main(){

    int TC,c,d,a,b;

    scanf("%d",&TC);
    int casenum =1 ;
    
    while(TC--){
        int M;
        cin >> R >> C >> M;
        
        int mask = 0;
        for(mask = 0; mask < 1<<(R*C); mask++){
            int count = 0;
            for(int k = 0; k < R*C; k++){
                if(mask&(1<<k)){
                    count++;
                }
            }
            if(count != M)continue;
            //cout << mask << endl;
            for(int i = 0; i < C; i++){
                for(int j = 0; j < R; j++){
                    if(check(mask, i, j)){
                        print(mask, i, j, casenum++);
                        goto penis;
                    }
                }
            }
        
        }
        cout << "Case #" << casenum++ << ":" << endl <<  "Impossible" << endl;
        penis: continue;
    }      
    
}
