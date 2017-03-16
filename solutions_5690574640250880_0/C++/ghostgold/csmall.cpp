
#include<cstdio>
#include<cstdlib>
#include<cstring>
void work();
int main()
{
  int T;
  scanf("%d", &T);
  for(int i = 1; i <=T; i++){
    printf("Case #%d: ",i);
    work();
  }
}


int r,c,m;
bool find;
int board[10][10];
int color[10][10];
int number[10][10];
int tot;
int dx[10]={1,1,0,-1,-1,-1,0,1};
int dy[10]={0,1,1,1,0,-1,-1,-1};

bool on(int x,int y){
  return (x >=0 && x < r && y >=0 && y < c);
}

//void click(int x,int y);
/*void reveal(int x,int y ){
  if(on(x,y)&& board[x][y] == 0){
    if(number[x][y]==0)
      click(x,y);
    else {
      tot++;
      color[x][y] =1;
    }
  }
  }*/
  
void click(int x, int y){
  if(!on(x,y))
    return;
  if(color[x][y])
    return;
  tot++;
  color[x][y]=1;
  if(number[x][y]==0)
    for(int i = 0; i < 8;i++)
      click(x+dx[i],y+dy[i]);
}

int check(){
  memset(number,0,sizeof(number));
  for(int p = 0; p < r*c;p++)if(board[p/c][p%c]==0){
    for(int i =0; i < 8; i++){
      int x = p/c + dx[i];
      int y = p%c + dy[i];
      if(on(x,y))
	number[p/c][p%c]+=board[x][y];
    }
  }
  
  for (int p = 0; p < r*c; p++){
    memset(color, 0, sizeof(color));
    tot = 0;
    if(board[p/c][p%c]==0){
      click(p/c,p%c);
    }
    if(tot == r*c-m)
      return p;
  }
  return -1;
}
void search(int pos, int mine){
  if(r*c - pos <mine)
    return;
  if(find)
    return;
  if(pos == r*c){
    int t = check();
    if(t >= 0){
      find = true;
      for(int i = 0; i < r; i++){
	for(int j = 0; j < c; j++){
	  if(c*i + j == t)
	    printf("c");
	  else{
	    printf("%c", board[i][j]==0? '.':'*');
	  } 
	    
	}
	printf("\n");
      }
    }
    return;
  }
  search(pos+1,mine);
  board[pos /c][pos %c] = 1;
  search(pos+1, mine-1);
  board[pos/c][pos %c] = 0;
}

void work()
{
  find = false;
  scanf("%d%d%d",&r,&c,&m);
  printf("\n");
  search(0,m);

  if(find)
    return;
  printf("Impossible\n");
}
