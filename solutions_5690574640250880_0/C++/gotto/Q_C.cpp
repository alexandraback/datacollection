#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int T;
int R,C,M,m;
char f[55][55];

void hoge(){    
  for(int i = 0; i < 55; i++)
    for(int j = 0; j < 55; j++)
      f[i][j] = '.';

  m = M;

  int l;
  for(l = 0; l < C-2; l++){
    if(m >= R){
      m-=R;
      for(int j = 0; j < R; j++) f[l][j] = '*';
    }else{
      break;
    }
  }
   
  if(l == C-1){
    for(int j = 0; j < m; j++) f[l][j] = '*';
    m = 0;
  }else if(l == C-2){
    int j;
    for(j = 0; m > 1; j++){
      m -= 2;
      f[l][j] = f[l+1][j] =  '*';
    }
    if(m){
      if(j < R-3){
	if(l==0 || R-j<5){
	  puts("Impossible");
	  return;
	}else{
	  f[l][j] = f[l+1][j] = f[l][j+1] = f[l+1][j+1] =  '*';
	  f[l-1][R-1] = f[l-1][R-2] = f[l-1][R-3] = '.';
	  m = 0;
	}
      }else{
	puts("Impossible");
	return;
      }
    }
  }else{
    if(m && m == R-1){
      if(R == 2 || l == C-3){
	puts("Impossible");
	return;
      }else if(l == R-3){
	if(C < 4){
	  puts("Impossible");
	  return;
	}else{
	  m -= R-1;
	  for(int j = 0; j < R-3; j++) f[l][j] = '*';
	  f[l+1][0] = f[l+2][0] = '*';
	}
      }else{
	m -= R-1;
	for(int j = 0; j < R-2; j++) f[l][j] = '*';
	f[l+1][0] = '*';
      }
    }else{
      for(int j = 0; j < m; j++) f[l][j] = '*';
      m = 0;
    }
  }
  f[C-1][R-1] = 'c';

  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      printf("%c",f[j][i]);
    }
    puts("");
  }
}

int main(void){
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){

    for(int i = 0; i < 55; i++)
      for(int j = 0; j < 55; j++)
	f[i][j] = '.';

    scanf("%d %d %d",&R,&C,&M);
    m = M;

    if(R*C-M == 1){
      printf("Case #%d:\n",t);
      for(int i = 0; i < R; i++){
	for(int j = 0; j < C; j++){
	  printf("%c",i+j==R+C-2?'c':'*');
	}
	puts("");
      }
      continue;
    }

    if(R*C - 1 - ((R-1)?1:0) - ((C-1)?1:0) - (((R-1)&&(C-1))?1:0) < M){
      printf("Case #%d:\nImpossible\n",t);
      continue;
    }

    printf("Case #%d:\n",t);
    int l;
    for(l = 0; l < R-2; l++){
      if(m >= C){
	m-=C;
	for(int j = 0; j < C; j++) f[l][j] = '*';
      }else{
	break;
      }
    }

    if(l == R-1){
      for(int j = 0; j < m; j++) f[l][j] = '*';
      m = 0;
    }else if(l == R-2){
      int j;
      for(j = 0; m > 1; j++){
	m -= 2;
	f[l][j] = f[l+1][j] =  '*';
      }
      if(m){
	if(j < C-3){
	  if(l==0 || C-j<5){
	    hoge();
	    continue;
	  }else{
	    f[l][j] = f[l+1][j] = f[l][j+1] = f[l+1][j+1] =  '*';
	    f[l-1][C-1] = f[l-1][C-2] = f[l-1][C-3] = '.';
	    m = 0;
	  }
	}else{
	  hoge();
	  continue;
	}
      }
    }else{
      if(m && m == C-1){
	if(C == 2){
	  hoge();
	  continue;
	}else if(l == R-3){
	  if(C < 4){
	    hoge();
	    continue;
	  }else{
	    m -= C-1;
	    for(int j = 0; j < C-3; j++) f[l][j] = '*';
	    f[l+1][0] = f[l+2][0] = '*';
	  }
	}else{
	  m -= C-1;
	  for(int j = 0; j < C-2; j++) f[l][j] = '*';
	  f[l+1][0] = '*';
	}
      }else{
	for(int j = 0; j < m; j++) f[l][j] = '*';
	m = 0;
      }
    }
    f[R-1][C-1] = 'c';

    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
	printf("%c",f[i][j]);
      }
      puts("");
    }
  }
}
