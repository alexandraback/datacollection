#include <iostream>
#include <stdlib.h>

using namespace std;

static int cmp_int(const void *p1, const void *p2)
{   
  /* The actual arguments to this function are "pointers to
     pointers to char", but strcmp(3) arguments are "pointers
     to char", hence the following cast plus dereference */

  if ((*((int *)p1))==(*((int *)p2)))
    return 0;
  if ((*((int *)p1))>(*((int *)p2)))
    return 1;
  else
    return -1;
}

//W is already sorted.
int test_how_many_to_add(int A,int W[],int N){
  int add = 0;

  int cur_index = 0;
  while(cur_index < N){
    while (W[cur_index]<A && cur_index < N){
      A = A + W[cur_index];
      cur_index ++;
    }

    while(W[cur_index]>=A && cur_index < N){
      A = A*2 -1;
      add ++;

      if(A==1){
	return 100;
      }
    }
  }
  return add;
}


int main(){

	int i_cases;
	int N_cases;

	cin>>N_cases;

	int W[128];

	for(i_cases=0;i_cases<N_cases;i_cases++){

	  int A, N;

	  cin>>A>>N;

	  for (int i=0;i<N;i++){
	    cin>>W[i];
	  }
	  
	  qsort(W,N,sizeof(int),cmp_int);
	/*
	  for (int i=0;i<N;i++){
	    cout<<W[i]<<" ";
	  }
	  cout<<endl;
*/
	  int minimum = N;

	  int to_delete = 0;
	  for (; to_delete < N; to_delete++ ){
	    int to_add = test_how_many_to_add(A,W,N-to_delete);
	    if(to_add+to_delete < minimum){
	      minimum = to_add + to_delete;
	    }
	  }

	  cout<<"Case #"<<i_cases+1<<": "<<minimum<<endl;

	}
	return 0;

}
