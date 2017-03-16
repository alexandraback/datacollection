#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;


const int MAXN = 128;
const int MAXM = 128;

int T;
int N, M;
int a[MAXN][MAXM];
int ra[MAXM][MAXN];
int rebuild[MAXN][MAXM];

void rebuild_reset(){
  for (int i = 0; i < N; i++){
    fill_n(rebuild[i], M, 100);
  }
}

void cut_line(int l, int height){
  //cout<<"cut line "<< l<< ","<< height << endl;
  for (int r = 0; r < M; r++){
    rebuild[l][r] = min(rebuild[l][r], height);
  }
}

void cut_row(int r, int height){
  //cout<<"cut row "<< r<< "," << height << endl;
  for (int l = 0; l < N; l++){
    rebuild[l][r] = min(rebuild[l][r], height);
  }
}

void rebuild_output(){
  for (int l = 0; l < N; l++){
    for (int r = 0; r < M; r++){
      printf("%d ", rebuild[l][r]);
    }
    printf("\n");
  }
}

bool rebuild_check_equal(){
  for (int l = 0; l < N; l++){
    for (int r = 0; r < M; r++){
      if (rebuild[l][r] != a[l][r])
        return false;
    }
  }
  return true;
}

void read(){
  scanf("%d %d", &N, &M);
  for (int l = 0; l < N; l++){
    for (int r = 0; r < M; r++){
      scanf("%d", &a[l][r]);
    }
  }
}

void proc(){
  for (int l = 0; l < N; l++){
    for (int r = 0; r < M; r++){
      ra[r][l] = a[l][r];
    }
  }

  for (int l = 0; l < N; l++){
    int line_max = *max_element(a[l], a[l] + M);
    cut_line(l, line_max);
  }

  for (int r = 0; r < M; r++){
    int row_max = *max_element(ra[r], ra[r] + N);
    cut_row(r, row_max);
  }
}

int main(){
  scanf("%d", &T);
  for (int i = 1; i <= T; i++){
    read();
    rebuild_reset();
    proc();
    printf("Case #%d: %s\n", i, rebuild_check_equal()?"YES":"NO");
  }
}

