#include <cstdio>
#include <cstdlib>
FILE * fin = fopen("A-large.in", "r");
FILE * fout = fopen("a.out", "w");

void work(int r){
     fprintf (fout, "Case #%d: ", r);
     char S[1000];
     fscanf (fin, "%s", &S);
     char tmp[1000];
     tmp[0] = S[0];
     int count = 1;
     while (S[count]){
           if (S[count] >= tmp[0]){
              for (int i = count; i > 0; i --){
                  tmp[i] = tmp[i - 1];
              }
              tmp[0] = S[count];
           }
           else{
                tmp[count] = S[count];
                }
           count ++;
     }
     for (int i = 0; i < count; i ++){
         fprintf (fout, "%c", tmp[i]);
     }
     fprintf (fout, "\n");
     return;
     }

int main(){
    int T;
    fscanf (fin, "%d", &T);
    for (int i = 0; i < T; i++) work(i + 1);
    return 0;
}