#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main () {
  FILE *filein;
  FILE *fileout;
  filein = fopen ("C_in.txt", "r");
  fileout = fopen ("C_out.txt", "w");
  int T;
  fscanf(filein, "%d", &T);
  for (int i = 0; i < T; i++){
    int N;
    fscanf(filein, "%d", &N);
    int *adj = (int *) malloc(sizeof(int) * (N + 1));
    int *found = (int *) malloc (sizeof (int) * (N + 1));
    int *src = (int *) malloc (sizeof (int) * (N + 1));
    adj[0] = 0;
    for (int j = 0; j < N; j++){
        int cur;
        fscanf(filein, "%d", &cur);
        adj[j + 1] = cur;
    }
    int ans = 0;
    for (int j = 1; j < N + 1; j++){
        int finish = 0;
        int cur_size = 1;
        int pos = j;
        for(int k = 0; k < N + 1; k++){
            found[k] = 0;
            src[k] = 0;
        }
        found[j] = 1;
        src[j] = j;
        while(!finish){
            finish = 1;
            if(!found[adj[pos]]){
                found[adj[pos]] = 1;
                src[adj[pos]] = pos;
                pos = adj[pos];
                cur_size += 1;
                finish = 0;
            }
        }
        if(adj[pos] != j && src[pos] != adj[pos]){
            cur_size = 0;
        }
        if(src[pos] == adj[pos]){
            finish = 0;
            int comp = 2;
            found[pos] = comp;
           // fprintf(stdout, "%d %d\n", i+1, pos);
            while(!finish){
                finish = 1;
                for (int k = 1; k < N + 1; k++){
                    if(!found[k]&& (found[adj[k]] == comp)){
                        found[k] = comp + 1;
                        //fprintf(stdout, "%d %d\n", i+1, k);
                        finish = 0;
                    }
                }
                if (!finish){
                    comp++;
                }
            }
           cur_size += comp - 2;
        }
        if(cur_size > ans){
            ans = cur_size;
        }
    }
     fprintf(fileout, "%s%d%s%d\n", "Case #", i + 1, ": ", ans);
  }
  return 0;
}



