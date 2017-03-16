#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


#define REPN(n) for (int i=1;i<=(n);i++)
#define REP(n,j) for (int j=1;j<=(n);j++)


int c[1001][20];
int ileM[1001];
int visited[1001];
int checked[1001];
bool found=false;

int level=0;

int go(int i) {
    if (found) return 1;
    level++;
//    for (int a=0;a<level;a++) cout << "\t";
//    cout << "Odwiedzam: " << i << endl; 
//    if (checked[i]) {
//      cout << "Bylem tu" << endl;
//    }

    if (checked[i]) { found=true; return 1; }
    else { 
      checked[i] = 1;
      visited[i] = 1;
    }
//    cout << "L: " << level << endl;
//      cout << "Ile: " << ileM[i] << endl;

    REP(ileM[i],a) {
      go(c[i][a]);  
    }
    level--;
}

int main(void) {
  int T;
  int M;
  int N;
  cin >> T;
  REPN(T) {
    found=false;
    cin >> N;
    REP(N,j) {
      visited[j]=0;
      checked[j]=0;
      cin >> M;
      ileM[j]=M;
      REP(M,k) 
        cin >> c[j][k];
    }
    REP(N,j) {        
        REPN(N) checked[i]=0;      
        if (ileM[j] > 1) 
          go(j);      
        
    }
    cout << "Case #" << (i) << ": ";     
    if (found) cout << "Yes";
    else cout << "No";
    cout << endl;
    
  }  

}

    
