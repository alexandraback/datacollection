#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <string>
#include <string.h>
#include <map>
#include <locale>
#include <math.h>
#include <time.h>
#include <list> 
 
#define frup(FRUP_I,FROM,TO) for(long FRUP_I=FROM;FRUP_I<=TO;FRUP_I++)
#define frdn(FRDN_I,FROM,TO) for(long FRDN_I=FROM;FRDN_I<TO;FRDN_I++)
#define foreach(it,arr) for(__typeof((arr).begin()) it = (arr).begin(); it!= (arr).end(); it++)
 
#define pub(VALUE) push_back(VALUE)
#define pob() pop_back()
#define mp(FST,SEC) make_pair(FST,SEC)
#define len(STR) STR.length()
 
#define refresh(ARRAY,TARGET,VALUE) frdn(int DEFINED_I,0,TARGET)ARRAY[DEFINED_I]=VALUE
#define watch(VALUE) {cout<<#VALUE;printf("=");cout<<VALUE;printf("\n");}
#define stop exit(0)

#define F first
#define S second

using namespace std;

typedef pair<int,int>ii;
typedef pair<long long,long long>lii;
typedef pair<char,int>ci;
typedef long long ll;

const int INF = int(1e9);
const double EPS  = 1e-8;
const long long INF64 = (long long)(1e18)+1,md = 1000000007ll;

int n,m,t;
char a[10][10];
int c[500];
bool fail,f,s;

bool checkx(int x,int y,int dx, int dy){
 if(x+dx*3<0||x+dx*3>=4)return false;
 if(y+dy*3<0||y+dy*3>=4)return false;
c['T']=c['X']=c['O']=c['.']=0; 
c[a[x][y]]++;
   frdn(i,0,3){
               x+=dx; y+=dy;
                c[a[x][y]]++;
               }
  if(c['T']==1&&c['X']==3)return 1;
  if(c['X']==4)return 1;
 return 0;               
}

bool checky(int x,int y,int dx, int dy){
 if(x+dx*3<0||x+dx*3>=4)return false;
 if(y+dy*3<0||y+dy*3>=4)return false;
c['T']=c['X']=c['O']=c['.']=0; 
c[a[x][y]]++;
   frdn(i,0,3){
               x+=dx; y+=dy;
                c[a[x][y]]++;
               }
  if(c['T']==1&&c['O']==3)return 1;
  if(c['O']==4)return 1;
 return 0;               
}

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
     scanf("%d\n",&t);
      frdn(cases,0,t){
                   if(cases)scanf("\n");
                      fail=0;
                       frdn(i,0,4){
                        frdn(j,0,4){
                                    scanf("%c",&a[i][j]);
                                     if(a[i][j]=='.')fail=1;
                                    }
                                    scanf("\n");
                           }
                     printf("Case #%d: ",cases+1);     
                       f=s=0;           
                        frdn(i,0,4)
                         frdn(j,0,4){
                                     if(!f){
                                       if(checkx(i,j,0,1))f=1;
                                        if(checkx(i,j,1,0))f=1;
                                        if(checkx(i,j,1,1))f=1;
                                       if(checkx(i,j,1,-1))f=1; 
                                       }
                                     if(!s){
                                       if(checky(i,j,0,1))s=1;
                                        if(checky(i,j,1,0))s=1;
                                        if(checky(i,j,1,1))s=1;
                                       if(checky(i,j,1,-1))s=1; 
                                       }
                                     } 
                        if(!f&&!s){
                                    if(fail){
                                         printf("Game has not completed\n");
                                         continue;
                                  }  
                                   printf("Draw\n");
                                   continue;
                                   }        
                       if(f) printf("X won\n");
                          else printf("O won\n");         
                      }
 return 0;
}       
