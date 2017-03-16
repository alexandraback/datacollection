#include <stdio.h>

int arr[110][110];
int trial[110][110];
int W, H;
int row[110], col[110];
int icase;

void Check(){
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(trial[i][j] != arr[i][j]){
        printf("Case #%d: NO\n", icase+1);
        return;
      }
    }
  }
  
  printf("Case #%d: YES\n", icase+1);
}

int main(){
  int jcase;
  int mval;
  
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(icase=0; icase<jcase; icase++){
    scanf("%d %d", &H, &W);
    
    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++) scanf("%d", &arr[i][j]);
    }
    
    for(int i=0; i<H; i++){
      mval = -1;
      for(int j=0; j<W; j++){
        if(arr[i][j] > mval) mval = arr[i][j];
      }
      row[i] = mval;
    }
    
    for(int i=0; i<W; i++){
      mval = -1;
      for(int j=0; j<H; j++){
        if(arr[j][i] > mval) mval = arr[j][i];
      }
      col[i] = mval;
    }
    
    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++) trial[i][j] = 2000;
    }
    
    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
        if(trial[i][j] > row[i]) trial[i][j] = row[i]; 
      }
    }
    
    for(int i=0; i<W; i++){
      for(int j=0; j<H; j++){
        if(trial[j][i] > col[i]) trial[j][i] = col[i]; 
      }
    }
    
    Check();
  }
  return 0;
}
