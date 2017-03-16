#include <iostream>
#include <queue>

using namespace std;

bool data[1010][1010];

bool visited[1010];

queue<int> q;

int main(){
  
  int T, N, M, tmp;
  
  bool diamond;
  
  
  scanf("%d", &T);
  for(int tt=0; tt<T; tt++){
    
    diamond = false;
    
    scanf("%d", &N);
    
    //cout << N << endl;
    for(int i=0; i<N; i++){
      visited[i] = false;
      for(int j=0; j<N; j++){
        data[i][j] = false;
        //clean data!
      }
    }
    
    while(!q.empty()) q.pop();


    for(int i=0; i<N; i++){
      scanf("%d", &M);
      for(int j=0; j<M; j++){
        scanf("%d", &tmp);
        data[i][tmp-1] = true;
      }      
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          if(data[i][j]){
            
            if(visited[j]) {
              diamond = true;
              break;
            }
            
            visited[j] = true;
            q.push(j);
          }
        }
        if(diamond) break;
        
        while(!q.empty()){
          tmp = q.front();
          q.pop();
          for(int j=0; j<N; j++){
            if(data[tmp][j]){
              
              if(visited[j]) {
                diamond = true;
                break;
              }
              
              visited[j] = true;
              q.push(j);
            }

          }
        }
      
      for(int j=0; j<N; j++){
        visited[j] = false;
      }
    }
    
    if(diamond){
      printf("Case #%d: Yes\n", tt+1);
    } else {
      printf("Case #%d: No\n", tt+1);
    }
    
    /*for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(data[i][j]){
          cout << "X";
        } else {
          cout << "0";
        }
        //clean data!
      }
      cout << endl;
    }
    cout << endl;
      */
        
    
  }
  
  
  return 0;
}