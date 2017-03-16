#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int mxn = 1010;

vector <int> polje[mxn];
int mem[mxn][mxn][2];

int diamond(int a, int b, bool pocetak){
  if(!pocetak && a == b) return 1;

  int &ref = mem[a][b][pocetak];
  if(ref != -1) return ref;

  if(pocetak){
    for(int i = 0; i < (int)polje[a].size(); i++){
      for(int j = 0; j < (int)polje[b].size(); j++){
	if(polje[a][i] == polje[b][j]) continue;
	
	if(diamond(polje[a][i], polje[b][j], 0)) return ref = 1;
      }
    }
    return ref = 0;
  }

  for(int i = 0; i < (int)polje[a].size(); i++){
    if(diamond(polje[a][i], b, 0)) return ref = 1;
  }
  for(int i = 0; i < (int)polje[b].size(); i++){
    if(diamond(a, polje[b][i], 0)) return ref = 1;
  }

  return ref = 0;
}

void solve(){
  memset(mem, -1, sizeof(mem));

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int k;
    scanf("%d", &k);
    polje[i].clear();

    for(int j = 0; j < k; j++){
      int x;
      scanf("%d", &x); x--;

      polje[i].push_back(x);
    }
  }

  for(int i = 0; i < n; i++){
    if(diamond(i,i,1)){
      printf( "Yes\n" );
      return;
    }
  }
  printf( "No\n" );
}

int main(){
  int t;
  scanf( "%d", &t );

  for(int i = 0; i < t; i++){
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
