#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>

bool possible = false;

void dfs(int basenode, int currentnode, std::vector<int> children[], int * ancestors) {
  //printf("dfs %d from %d\n", currentnode, basenode);
  if(ancestors[currentnode] == basenode) {
    possible = true;
    return;
  }
  ancestors[currentnode] = basenode;
  for(int i=0; i<children[currentnode].size(); i++) {
    if(!possible) dfs(basenode, children[currentnode][i], children, ancestors);
  }
}


int main() {
  int tests, classes, num, tmp;
  scanf("%d", &tests);
  for(int c=0; c<tests; c++) {
    scanf("%d", &classes);
    std::vector<int> children[classes];
    int ancestor[classes];
    for(int i=0; i<classes; i++) {
      scanf("%d", &num);
      for(int l=0; l<num; l++) {
        scanf("%d", &tmp);
        children[tmp-1].push_back(i);
      }
    }

    possible = false;
    for(int i=0; i<classes; i++) ancestor[i]=-1;
    for(int i=0; i<classes; i++) {
      if(!possible) dfs(i, i, children, ancestor);
    }


    if(possible) printf("Case #%d: Yes\n", c+1);
    else printf("Case #%d: No\n", c+1);
  }
}
