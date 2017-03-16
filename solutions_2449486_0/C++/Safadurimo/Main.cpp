#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned ui;

int matrix[100][100];
bool cols[100];
bool rows[100];
int N,M;

bool isPossible(){
   memset(rows,false,100*sizeof(bool));
    memset(cols,false,100*sizeof(bool));
    for(ui a=1;a<=100;a++){
      for(ui i=0;i<N;i++){
        for(ui j=0;j<M;j++){
          if(!cols[j] && !rows[i] && matrix[i][j] == a){
            int x,y;
            // check if colum is equal
            for(x=0;x<N;x++){
              if (!rows[x] && matrix[x][j]!=a){
                break;
              }
            }
            // check of row is equal
             for(y=0;y<M;y++){
              if (!cols[y] && matrix[i][y]!=a){
                break;
              }
            }
             if(x!=N && y!=M) return false;
             if(x==N) cols[j]=true;
             if(y==M) rows[i]=true;

            }
          }
        }
      }
  return true;
}


int main()
{
  
  int T;
  
  cin >> T;

  for(ui t=1;t<=T;t++){
    
    // read the lace
    cin >> N >> M;
    for(ui i=0;i<N;i++)
      for(ui j=0;j<M;j++)
        cin >> matrix[i][j];

   if(isPossible())
     cout << "Case #" << t << ": " << "YES" << endl;
   else 
    cout << "Case #" << t << ": " << "NO" << endl;
  }
}
