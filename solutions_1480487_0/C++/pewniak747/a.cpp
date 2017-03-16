#include <cstdio>
#include <algorithm>

int main() {
  int tests, cont;
  scanf("%d", &tests);
  for(int c=0; c<tests; c++) {
    scanf("%d", &cont);
    int judges[cont];
    int judges_sort[cont];
    int sum=0;
    for(int i=0;i<cont;i++) {
      scanf("%d", &judges[i]);
      sum += judges[i];
    }
    for(int i=0;i<cont;i++) judges_sort[i] = judges[i];
    std::sort(judges_sort, judges_sort+cont);
    double sol = judges_sort[0];
    int pts = 0;
    int i;
    for(i=0; i<cont; i++) {
      int added = (judges_sort[i] - sol)*(i);
      //printf("sol: %.6f added: %d pts: %d\n", sol, added, pts);
      if(pts + added < sum) {
        pts += added;
        sol = judges_sort[i];
      }
      else {
        sol += double(sum-pts)/(i);
        pts = sum;
        break;
      }
    }
    //printf("sol: %.6f i: %d  pts: %d\n", sol, i, pts);
    if(pts < sum) sol += double(sum-pts)/(i);
    //printf("sol: %.6f\n", sol);

    printf("Case #%d: ", c+1);
    double summ = 0;
    for(int i=0; i<cont; i++) {
      double sol2 = (sol-judges[i])/sum;
      if(sol2 < 0) sol2=0;
      summ += sol2;
      printf("%.6f ", sol2*100);
    }
    //printf("%.6f ", summ);
    printf("\n");
  }
}
