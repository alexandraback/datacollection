//
//  main.cpp
//  22
//
//  Created by Nikifor Zhao on 14-5-11.
//  Copyright (c) 2014年 Han Zhao. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("B-large.in");
ofstream fout("out.txt");
char c[200][200], l[200], meet[30];
long long ca[30], al[200], mark[30], mark2[100];
long long n;
long long ans;
void dfs(int color){
    mark[color] = 1;
    for (int i = 0; i < n; i++){
        int has = 0;
        for (int j = 0; j < l[i]; j++){
            if (c[i][j] - 97 == color) has = 1;
        }
        if (has == 0) continue;
        for (int j = 0; j < l[i]; j++){
            if (mark[c[i][j] - 97] == 0) dfs(c[i][j] - 97);
        }
    }
}

int dfs2(int at, int from, int step){
    mark2[at] = from;
    if (c[at][0] != c[from][0]) step = 1;
    int color = c[at][l[at]-1] - 97;
    for (int i = 0; i < n; i++){
        if (mark2[i] != from && c[i][0] - 97 == color){
            if (c[i][l[i]-1] == c[from][0] && step == 1) return 1;
            else return dfs2(i, from, step);
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{

    int t;
    fin >> t;
    for (int ni = 1; ni <= t; ni ++){
        
        long long parts = 0;
        fin >> n;
        for (int i = 0; i < n; i++) { fin >> c[i]; l[i] = strlen(c[i]); al[i] = 0; mark2[i] = -1;}
        for (int i = 0; i < 30; i++) {ca[i] = 0; mark[i] = 0; meet[i] = 0;}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l[i]; j++) meet[c[i][j] - 97] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l[i]; j++) {
                int tj = j;
                while (c[i][tj] == c[i][tj+1]) tj++;
                for (tj = tj + 1; tj < l[i]; tj ++){
                    if (c[i][tj] == c[i][j]){
                        fout << "Case #" << ni << ": 0" << endl;
                        goto nxt;
                    }
                }
            }
            int p = 0, q = l[i] - 1;
            while (p < q && c[i][p] == c[i][p+1]) p++;
            while (p < q && c[i][q] == c[i][q-1]) q--;
            if (p == q) {
                ca[c[i][p] - 97] ++;
                al[i] = 1;
            }else if(p == q - 1){
                
            }else{
                for (int tp = p + 1; tp < q; tp ++){
                    for (int j = 0; j < n; j++) {
                        if (j == i) continue;
                        for (int k = 0; k < l[j]; k++) {
                            if (c[i][tp] == c[j][k]) {
                                fout << "Case #" << ni << ": 0" << endl;
                                goto nxt;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (al[i] == 1) continue;
            ca[c[i][0]] = 0;
            ca[c[i][l[i]-1]] = 0;
            for (int j = 0; j < n; j++) {
                if (i == j || al[j] == 1) continue;
                if (c[j][0] == c[i][0] || c[j][l[j]-1] == c[i][l[i]-1]) {
                    fout << "Case #" << ni << ": 0" << endl;
                    goto nxt;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (dfs2(i, i, 0) == 1){
                fout << "Case #" << ni << ": 0" << endl;
                goto nxt;
            }
        }
        
        for (int k = 0; k < 26; k ++){
            if (mark[k] == 1 || meet[k] == 0) continue;
            parts ++;
            dfs(k);
        }
        ans = 1;
        for (int i = 1; i <= parts; i++) {
            ans = (ans * i) % 1000000007;
        }
        for (int i = 0; i < 30; i++) {
            if (ca[i] != 0) {
                for (int j = 1; j <= ca[i]; j++) {
                    ans = (ans * j) % 1000000007;
                }
            }
        }
        
        
        fout << "Case #" << ni << ": " << ans << endl;
    nxt: ni = ni;
    }
    return 0;
}

