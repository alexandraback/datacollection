#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  int tests;
  cin>>tests;
  int index=1;
  while(index<=tests){
    char inp[4][4];
    int complete=1;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        cin>>inp[i][j];
        if(inp[i][j] == '.')
          complete = 0;
      }
    }
    int sums[10] = {0};
    int k=0;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        sums[k] += (int)inp[i][j];
      }
      k++;
    }
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        sums[k] += inp[j][i];
      }
      k++;
    }
    for(int i=0; i<4; i++){
        sums[k] += inp[i][i];
    }
    k++;
    for(int i=0; i<4; i++){
        sums[k] += inp[i][3-i];
    }
    int win=0;

    for(int i=0; i<10; i++){
      if(sums[i] == 348) {
          cout<<"Case #"<<index<<": X won"<<endl;
          win = 1;
          break;
      }
      else if(sums[i] == 321){
          cout<<"Case #"<<index<<": O won"<<endl;
          win = 1;
          break;
      }
      else if (sums[i] == 316) {
          cout<<"Case #"<<index<<": O won"<<endl;
          win = 1;
          break;
      }
      else if (sums[i] == 352) {
          cout<<"Case #"<<index<<": X won"<<endl;
          win = 1;
          break;
      }
    }
    if(!win){
      if(complete)
        cout<<"Case #"<<index<<": Draw"<<endl;
      else
        cout<<"Case #"<<index<<": Game has not completed"<<endl;
    }
    index++;
  }
  return 0;
}
