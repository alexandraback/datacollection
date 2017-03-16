#include<iostream>
#include<fstream>
using namespace std;

int state[105][105],maxX[110],maxY[110];


int main() {
          int T,n,m;
          //ifstream in("B-large.in");
          //ofstream out("B-large.out");

          cin >> T;
          for(int tc=1; tc<=T; tc++){
                    cin >> n >> m;
                    for(int x=0; x<n; x++)
                              for(int y=0; y<m; y++) {
                                        cin >> state[x][y];
                              }

                    for(int x=0; x<n; x++){
                              maxX[x]=0;
                    }
                    for(int y=0; y<m; y++){
                              maxY[y]=0;
                    }

                    for(int x=0; x<n; x++)
                              for(int y=0; y<m; y++){
                                        if (state[x][y]>maxX[x]) maxX[x]=state[x][y];
                              }
                    for(int y=0; y<m; y++)
                              for(int x=0; x<n; x++){
                                        if (state[x][y]>maxY[y]) maxY[y]=state[x][y];
                              }

                    bool result = true;
                    for(int x=0; x<n; x++)
                              if (result) {
                              for(int y=0; y<m; y++){
                                        if (state[x][y]!=maxX[x] && state[x][y]!=maxY[y]) {
                                                  result = false;
                                                  break;
                                        }
                              }
                              }

                    cout << "Case #" << tc << ": ";
                    if (result) cout << "YES" << endl;
                              else cout << "NO" << endl;
          }
          return 0;
}
