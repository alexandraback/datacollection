#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <fstream>

using namespace std;
ifstream fin("A-large.in");
ofstream fout("A.out");

const int N = 1001;
int map[N][N];
int mark = 0;
int cnt = 1;
int v[N];
int n , m;

void dfs(int t) {
     int i , j;
     if(v[t]) {mark = 1; return;}
     v[t] = 1;
     for(i = 1 ; i <= n ; i++) {
           if(map[t][i]) {dfs(i);}
     }
} 

int main() {
    int i , j , t;
    fin >> t;
    while(t--){
               fin >> n;
               int u;
               memset(map , 0 , sizeof(map));
               for(i = 1 ; i <= n ; i++) {
                     fin >> m;
                     for(j = 0 ; j < m ; j++) {
                           fin >> u;
                           map[i][u] = 1;
                     }
               }/*
               for(i = 1 ; i <= n ; i++) {
                     for(j = 1 ; j <= n ; j++)
                           cout << map[i][j] << ' ' ;
                     cout << endl;
               }*/
               bool g = false;
               for(i = 1 ; i <= n ; i++) {
                     bool f = true;
                     for(j = 1 ; j <= n ; j++)
                           if(map[j][i]) f = false;
                     //cout << f << endl;
                     if(f) {
                           mark = 0;
                           memset(v , 0 , sizeof(v));
                           dfs(i);
                           if(mark) {fout <<"Case #" << cnt++ << ": Yes" << endl;break;}
                     }
               }
               if(!mark) {
                      fout <<"Case #" << cnt++ << ": No" << endl;
               }
    }
    //system("pause");
    return 0;
}