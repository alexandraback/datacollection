#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int main() {


  int T = 0;
  scanf("%d", &T);
  int i = 1;
  while (T-- > 0) {
    std::vector<long long> tasks;
    long long E,R,N;
    scanf("%lld %lld %lld", &E, &R, &N);
    long long initialE = E;
    while(N-- > 0) {
      long long task;
      scanf("%lld", &task);
      tasks.push_back(task);
    }
    
    long long res = 0;
  
    for (int j = 0; j < tasks.size()-1; j++) {
      
      /*     if (tasks[j]<tasks[j+1]) {
	int e = E+R - initialE;
	if (e<0) e = 0;
	printf("JESTEM QL w %d pozycji pobieram %d... %d\n", j, tasks[j]*e, E);
	res+=tasks[j]*e;
      }
      else*/ {
	bool bigger = false;
	int k = j+1;
	for (; k < tasks.size(); k++) {
	  if (tasks[k] > tasks[j]) { bigger = true; break; }
	}
	if (bigger) {
	  int e = E;

	  e  = E+R*(k-j) -  initialE;

	  if (e<0) e = 0;
	  if (e>E) e = E;

	  res+=tasks[j]*e;
	  E = E+R-e;
	  //printf("w %d [%d] pozycji pobieram %d... %d\n", j, tasks[j], e, E);
	  
	} else { 
	  
	  res+=tasks[j]*E; 
	  //printf("biore max %d [%d] pozycji pobieram %d ... %d\n", j, tasks[j], E , E);
	  E = R;
	}
      }

    }
    res += tasks[tasks.size()-1]*E;
    printf("Case #%d: %lld\n", i, res);
    i++;
  }


}
