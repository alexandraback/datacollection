#include<cstdio>
#include<cstring>

bool rows[100];
bool columns[100];
int a[101];
int lawn[100][100];
int n, m;

bool checkrow(int row, int v){
  for(int i = 0; i<m; i++)
    if(lawn[row][i] > 0 && lawn[row][i] != v)
      return false;
  return true;
}
bool checkcol(int col, int v){
  for(int i = 0; i<n; i++)
    if(lawn[i][col] > 0 && lawn[i][col] != v)
      return false;
  return true;
}

int main(){
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++){
    memset(rows, 0, sizeof(rows));
    memset(columns, 0, sizeof(columns));
    memset(a, 0, sizeof(a));
    memset(lawn, 0, sizeof(lawn));
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++){
        scanf("%d", &(lawn[i][j]));
        a[lawn[i][j]]++;
      }
    bool flag=true;
    for(int i = 1; i<=100; i++){
      if(!flag) break;
      while(a[i] > 0){
        int tmp = a[i];
        for(int j = 0; j < m; j++)
          if(!columns[j] && checkcol(j, i)){
            columns[j] = true;
            for(int k = 0; k < n; k++)
              if(lawn[k][j] == i){
                //printf("row %d col %d i %d\n", k, j, i);
                lawn[k][j] = -1;
                a[i] --;
              }
          }
        for(int j = 0; j < n; j++)
          if(!rows[j] && checkrow(j, i)){
            rows[j] = true;
            for(int k = 0; k < m; k++)
              if(lawn[j][k] == i){
                //printf("row %d col %d i %d\n", j, k, i);
                lawn[j][k] = -1;
                a[i] --;
              }
          }
        //printf("v%d %d %d\n", i, tmp, a[i]);
        if(tmp == a[i]){
          flag =false;
          break;
        }
      }
    }
    if(flag)
      printf("Case #%d: YES\n", t);
    else
      printf("Case #%d: NO\n", t);
  }
  return 0;
}
