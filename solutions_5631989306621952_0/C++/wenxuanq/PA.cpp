#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main () {
  FILE *filein;
  FILE *fileout;
  filein = fopen ("A_in.txt", "r");
  fileout = fopen ("A_out.txt", "w");
  int T;
  fscanf(filein, "%d", &T);
  for (int i = 0; i < T; i++){
    char *word = (char *)malloc(sizeof(char) * 1001);
    vector<char> sol = vector<char>();
    fscanf(filein, "%s", word);
    int j = 1;
    char cur = word[j];
    sol.push_back(word[0]);
    vector<char>::iterator it = sol.begin();
    while (cur != '\0'){
        if(cur < sol[0]){
            sol.push_back(cur);
        }else{
            it = sol.begin();
            sol.insert(it,cur);
        }
        j++;
        cur = word[j];
    }
    fprintf(fileout, "%s%d%s", "Case #", i + 1, ": ");
    for (int j = 0; j < sol.size(); j++){
        fprintf(fileout, "%c", sol[j]);
    }
    fprintf(fileout, "\n");
   // fprintf(stdout, "%s\n", word);

    free(word);
  }
  return 0;
}

