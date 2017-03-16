#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


struct City{
  string zip;
  bool visited;
};



//Global
int T, N, M;
City city[50];
bool graph[50][50];
int retf[50][50];
//Solution
string best;

void travel(int id, string sol) {

  printf("travel(%d), sol=%s\n", id, sol.c_str());

  if( best.compare( sol ) < 0 ) {
    printf("pruned(%d)\n", id);
    return;
  }

  if( sol.size() == N*5 ) {
    printf("solution(%d)\n", id);
    bool valid = true;
    for(int i=0; i<N && valid; i++) {
      for(int j=0; j<N; j++)
	if( retf[i][j] > 0 )
	  valid = false;
    }

    if( valid && best.compare( sol ) > 0 ) {
      printf("newbest(%d)=%s\n", id,sol.c_str());
      best = sol;
    }
  }

  for(int i=0; i<N; i++) {
    if( graph[id][i] ) {
      
      if( !city[i].visited ) {
	printf("son1(%d)=%d\n", id,i);
	retf[id][i]++;

	city[i].visited = true;
	sol += city[i].zip;

	travel(i, sol);
	
	city[i].visited = false;
	sol.erase(sol.end()-5, sol.end());
	retf[id][i]--;
      }
      
      if( retf[i][id] > 0 ) {
	printf("son2(%d)=%d\n", id,i);
	retf[i][id]--;
	travel(i, sol);
	retf[i][id]++;
      }

    }
  }
  
}


int main(int argc, char *argv[]) {

  scanf("%d", &T);

  for(int t=1; t<=T; t++) {

    //Read info
    scanf("%d %d", &N, &M);

    char zip[6];
    for(int i=0; i<N; i++) {
      scanf("%s", zip);
      city[i].zip   = zip;
    }

    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
	graph[i][j] = false;

    int a,b;
    for(int i=0; i<M; i++) {
      scanf("%d %d", &a, &b);
      graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    //Solve
    best = "99999";
    for(int i=1; i<N; i++)
      best += "99999";
    

    for(int i=0; i<N; i++) {
      memset(retf, 0, 50*50*sizeof(int));

      for(int j=0; j<N; j++)
	city[j].visited = false;

      string solution = city[i].zip;
      city[i].visited = true;
      printf("==================\n");
      travel(i, solution);
    }

    printf("Case #%d: %s\n", t, best.c_str());
    printf("\n\n\n");
  }

  return 0;
}
