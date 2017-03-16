#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
const double eps = 1e-12;
const double dinf = 99999999999.99;
const int N = 100;

bool check(int r, int c, int n){
    vector<string> maps, tmps;
    maps.resize(r);
    for(int i = 0; i < r; ++ i)
        maps[i] = string(c, '*');
    int saf = r*c - n;
    bool win = false;
    if(saf == 0)
        return win;
    if(saf == 1){
        maps[0][0] = '.';
        win = true;
    }else if(min(r,c) == 1){
        for(int i = 0; saf && i < r; i ++){
            for(int j = 0; saf && j < c; j ++){
                maps[i][j] = '.';
                saf --;
            }
        }
        win = true;
    }else{
        for(int x = 2, y, z; !win && x <= r; x ++){
            y = saf/x;
            z = saf%x;
            if(y <= 1 || y + (z != 0) > c)
                continue;
            if(z == 1){
                if(x <= 2 || y <= 2) continue;
                for(int i = 0; i < x; ++ i){
                    for(int j = 0; j <= y; ++ j){
                        maps[i][j] = '.';
                    }
                }
                for(int i = 1; i < x - z; ++ i)
                    maps[x - i][y] = '*';
                maps[x - 1][y - 1] = '*';
                win = true;
            }else{
                for(int i = 0; i < x; ++ i){
                    for(int j = 0; j <= y; ++ j){
                        maps[i][j] = '.';
                    }
                }
                for(int i = 1; i <= x - z; ++ i)
                    maps[x - i][y] = '*';
                win = true;
            }
        }
        for(int  y = 2, x, z; !win && y <= c; ++ y){
            x = saf/y;
            z = saf%y;
            if(x <= 1 || x + (z!=0) > r)
                continue;
            if(z == 1){
                if(x <= 2 || y <= 2) continue;
                for(int i = 0; i <= x; ++ i){
                    for(int j = 0; j < y; ++ j){
                        maps[i][j] = '.';
                    }
                }
                for(int i = 1; i < y - z; ++ i)
                    maps[x][y - i] = '*';
                maps[x - 1][y - 1] = '*';
                win = true;
            }
            else{
                for(int i = 0; i <= x; ++ i){
                    for(int j = 0; j < y; ++ j){
                        maps[i][j] = '.';
                    }
                }
                for(int i = 1; i < y - z; ++ i)
                    maps[x][y - i] = '*';
                win = true;
            }
        }
    }
    maps[0][0] = 'c';
    if(win){
        for(int i = 0; i < r; i ++)
            cout<<maps[i]<<endl;
    }
    return win;
}

int main(){
 //   freopen("C2.in","r",stdin);
 //   freopen("C.txt","w",stdout);
    int T;
    cin>>T;
    int cas = 1;
    while(T--){
        int r,c,n, cntsaf = 0;
        cin>>r>>c>>n;
        cout<<"Case #"<<cas<<":"<<endl;
        cas++;
        vector<vector<bool> > maps(N, vector<bool>(0));
        if(!check(r,c,n))
            cout<<"Impossible"<<endl;
    }
    return 0;
}
