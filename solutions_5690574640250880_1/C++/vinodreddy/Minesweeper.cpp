#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define itr iterator
#define get(t) int t;cin >> t;
#define fi first
#define se second
#define mp make_pair
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end(); it++)
#define all(x) x.begin(),x.end()


typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<double> vd;

inline void sfr (int *a)
{
    char c = 0;
    while(c<33)
    c = fgetc(stdin);
    *a = 0;
    while(c>33)
    {
               *a = *a*10 + c - '0';
               c = fgetc(stdin);
    }
}

inline void sfp(int a){
     char c[1000];
     sprintf(c,"%d",a);
     puts(c);
}

int P[3000];

void fill(){
     f(i,2,3000){
                 if(P[i] == 0){
                         for(int j = 2*i;j < 3000;j += i){
                                 P[j] = i;
                         }
                 } 
     }
     
}


int main(){
    ofstream out;
    out.open("output.txt");
    ifstream in;
    in.open("input.txt");
    fill();
    int t;
    in >> t;
    f(ct,1,t+1){
                int r,c,k,m;
                in >> r >> c >> m;
                int A[r][c];
                k = r*c-m;
                out << "Case #" << ct << ": " << endl;
                if(k == 1){
                     out << "c";
                     f(i,0,c-1)out << "*";
                     out << endl;
                     f(i,0,r-1){
                                f(j,0,c)out << "*";
                                out << endl;
                     }
                }
                else if(min(r,c) == 1){
                            if(r == 1){
                                 out << "c";
                                 f(i,0,c-1){
                                            if(i < k-1)out << ".";
                                            else out << "*";
                                 }
                                 out << endl;
                            }
                            else if(c == 1){
                                 out << "c" << endl;
                                 f(i,0,r-1){
                                            if(i < k-1)out << "." << endl;
                                            else out << "*" << endl;
                                 }
                            }
                }
                else if((r == 2 || c == 2) && k%2 == 1){
                     out << "Impossible" << endl;
                }
                else if(k < 9 && P[k] == 0){
                     out << "Impossible" << endl;
                     continue;
                } 
                else if(k >= 2*r){
                     int cnt = 0;
                     int chk = 0;
                     f(i,0,c)f(j,0,r){
                                      if(cnt < k){
                                             if(chk == 0){
                                                    A[j][i] = -1;
                                                    chk = 1;
                                             }
                                             else A[j][i] = 0;
                                      }
                                      else A[j][i] = 1;
                                      cnt++;
                     }
                     if(k%r == 1){
                            int c1 = (k-1)/r;
                            if(c1 == 2){
                                  A[0][0] = 1;
                                  A[0][1] = 1;
                                  A[0][c1] = 1;
                                  A[r-1][0] = -1;
                                  A[r-1][c1] = A[r-2][c1] = A[r-3][c1] = 0;
                            }
                            else{
                                 A[0][c1] = A[0][c1-1] = 1;
                                 A[r-1][c1] = A[r-2][c1] = 0;
                            }
                     }
                     f(i,0,r){
                              f(j,0,c){
                                       if(A[i][j] == -1)out << "c";
                                       if(A[i][j] == 0)out << ".";
                                       if(A[i][j] == 1)out << "*";
                              }
                              out << endl;
                     } 
                }
                else if(k >= 2*c){
                     
                     int cnt = 0;
                     int chk = 0;
                     f(i,0,r)f(j,0,c){
                                      if(cnt < k){
                                             if(chk == 0){
                                                    A[i][j] = -1;
                                                    chk = 1;
                                             }
                                             else A[i][j] = 0;
                                      }
                                      else A[i][j] = 1;
                                      cnt++;
                     }
                     if(k%c == 1){
                            int r1 = (k-1)/c;
                            if(r1 == 2){
                                  A[0][0] = 1;
                                  A[1][0] = 1;
                                  A[r1][0] = 1;
                                  A[0][c-1] = -1;
                                  A[r1][c-1] = A[r1][c-2] = A[r1][c-3] = 0;
                            }
                            else{
                                 A[r1][0] = A[r1-1][0] = 1;
                                 A[r1][c-1] = A[r1][c-2] = 0;
                            }
                     }
                     f(i,0,r){
                              f(j,0,c){
                                       if(A[i][j] == -1)out << "c";
                                       if(A[i][j] == 0)out << ".";
                                       if(A[i][j] == 1)out << "*";
                              }
                              out << endl;
                     } 
                }
                else if(P[k]){
                     int r1 = P[k];
                     int c1 = k/P[k];
                     int chk = 0;
                     f(i,0,r){
                              f(j,0,c){
                                       if(i < r1 && j < c1){
                                            if(chk == 0){
                                                   out << "c";
                                                   chk = 1;
                                            }
                                            else{
                                                 out << ".";
                                            }
                                       }
                                       else out << "*";
                              }
                              out << endl;
                     }
                }
                else{
                     int r1 = (k-3)/2;
                     f(i,0,r){
                              f(j,0,c){
                                      if((i < 2 && j < r1)||(i == 2 && j < 3)){
                                            out << ".";
                                      } 
                                      else out << "*";
                              }
                              out << endl;
                     }
                }
    }
    in.close();
    out.close();
    get(wait);
}

