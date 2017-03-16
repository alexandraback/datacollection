#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  int tests;
  cin>>tests;
  int index=1;
  while(index <= tests){
    int N,M;
    cin>>N>>M;
    int **field;
    field = new int*[N];
    for(int i=0; i<N; ++i)
      field[i] = new int[M];
    int *rowmax = new int[N];
    int *colmax = new int[M];

    for(int i=0; i<N; i++){
      rowmax[i]=0;
      for(int j=0; j<M; j++){
        cin>>field[i][j];
        if(field[i][j] >= rowmax[i])
          rowmax[i] = field[i][j];
      }
    }
    for(int i=0; i<M; i++){
      colmax[i]=0;
      for(int j=0; j<N; j++){
        if(field[j][i] >= colmax[i])
          colmax[i] = field[j][i];
      }
    }
    int invalid = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        int x = field[i][j];
        if(x < rowmax[i] && x < colmax[j]){
          invalid = 1;
          break;
        }
      }
      if(invalid)
        break;
    }
    if(invalid)
      cout<<"Case #"<<index<<": NO"<<endl;
    else
      cout<<"Case #"<<index<<": YES"<<endl;
    index++;
  }
  return 0;
}
