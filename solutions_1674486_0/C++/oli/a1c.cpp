#include <stdio.h>

FILE *fin = fopen ("A-small-attempt1.in","r");
FILE *fout = fopen ("a.out","w");

int n;

int her[1001][10];
int mi[1001];

int refs[1001];

bool mark[1001];

bool diamond (int clas) {
  mark [clas] = true;
  
  for (int i = 0; i < mi[clas]; i++) {
    int goTo = her[clas][i];
    
    if (mark[goTo]) return true;
    
    if (diamond (goTo)) return true;
  }
  
  return false;
}

int main () {
  int t;
  fscanf (fin,"%d",&t);        
        
  for (int i = 1; i <= t; i++) {                    
    fscanf (fin,"%d",&n);
    
    for (int j = 1; j <= n; j++) refs[j] = 0;
    
    for (int j = 1; j <= n; j++) {
      fscanf (fin,"%d",&mi[j]);      

      mark[j] = false;    
      
      for (int k = 0; k < mi[j]; k++) {
        fscanf (fin,"%d",&her[j][k]);
        
        refs[her[j][k]]++;
      }
    }        
    
    bool answer = false;    
    
    for (int j = 1; j <= n; j++) {
      if (refs[j] == 0) {                
        if (diamond (j)) {
          answer = true;
          break;          
        }
        
        for (int k = 1; k <= n; k++) mark[k] = false;
      }
    }
    
    if (answer)
      fprintf (fout,"Case #%d: Yes\n",i);    
    else
      fprintf (fout,"Case #%d: No\n",i);    
  }  
  
  fclose (fin);
  fclose (fout);    
  
  return 0;
}
