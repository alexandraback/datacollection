#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int N,M;
int maze[100][100];
int ok[100][100];
int maxN[100];
int maxM[100];

int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;++t){
      cout << "Case #"<<t<<": ";
      cin >> N;
      cin >> M;
      fill_n(maxN,100,0);
      fill_n(maxM,100,0);
      for(int i=0;i<N;++i)
        for(int j=0;j<M;++j){
          cin >> maze[i][j];
          if(maze[i][j]>maxN[i])
            maxN[i] = maze[i][j];
          if(maze[i][j]>maxM[j]) 
            maxM[j] = maze[i][j];
        }
      bool found=true;
      for(int i=0;i<N && found;++i){
        for(int j=0;j<M && found;++j){
          if(maze[i][j]<maxM[j] && maze[i][j]<maxN[i])
            found=false;
        }
      }
      if(found)
        cout << "YES"<<endl;
      else
        cout << "NO"<<endl;
  }
  return 0;
}
