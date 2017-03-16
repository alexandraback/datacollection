#include <climits>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>

using namespace std;

int dist(vector<int> & a, vector<int> & b){
  int res=0;
  for(int i = 0; i < 2; i++){
    res +=(a[i]-b[i])*(a[i]-b[i]);
  }
  return res;
}

int sign(int x){
  if(x<0) return -1;
  if(x>0) return 1;
  return 0;
}

int gcd(int a, int b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

int det3(const vector<vector<int> > & m){
  int res,p;
  res=0;
  for(int j = 0; j < 3; j++){
    p=1;
    for(int i = 0; i < 3; i++){
      p *= m[i][(j+i)%3];
    }
    res+=p;
    p=1;
    for(int i = 0; i < 3; i++){
      p *= m[i][(j+3-i)%3];
    }
    res-=p;
  }
  return res;
}

void run(int case_index) {
  
  int H,W,D; cin >> H >> W >> D;
  vector<int> source(2,0);
  vector<vector<int> > a(H,vector<int>(W));
  for(int i = 0; i < H; i++){
    string l; cin >> l;
    for(int j = 0; j < W; j++) if(l[j]=='X'){
      source[0]=i, source[1]=j;
    }
    for(int j = 0; j < W; j++){
      a[i][j] = l[j]=='#';
    }
  }
  int nimages = 0;
  vector<int> dir(2,-1);
  map<pair<int,int>,int> done;
  for(int tx = -D; tx <= D; tx++){
    for(int ty = -D; ty <= D; ty++){
      if(not(tx==0 and ty==0)){
        vector<int>target=source;
        target[0]+=tx;
        target[1]+=ty;
        int g=gcd(abs(tx),abs(ty));
        if(done[make_pair(tx/g,ty/g)]){
          continue;
        }
        if(dist(source,target)<=D*D){
          for(int k = 0; k < 2; k++) 
            dir[k] = sign(target[k]-source[k]);
          vector<int> x=source;
          vector<vector<int> > moves;
          while(x!=target){
            vector<int> move(2,0);
            vector<vector<int> > m(3,vector<int>(3));
            m[0][0] = source[0];
            m[0][1] = source[1];
            m[0][2] = 1;
            m[1][0] = target[0];
            m[1][1] = target[1];
            m[1][2] = 1;
            m[2][0] = 2*x[0]+dir[0];
            m[2][1] = 2*x[1]+dir[1];
            m[2][2] = 2;
            int d=det3(m);

            for(int k = 0; k < 2; k++){
              m[2][k] = 2*x[k]+dir[k];
              m[2][1-k] = 2*x[1-k]-dir[1-k];
              int dk=det3(m);
              if(d*dk<=0)
                move[k]=dir[k];
            }
            moves.push_back(move);
            for(int i = 0; i < 2; i++){
              x[i]+=move[i];
            }
          }
          // Compute the trajectory
          x=source;
          vector<int> mirror(2,1);
          bool aborted=false;
          vector<vector<int> >::iterator it;
          for(it=moves.begin(); it!=moves.end(); it++){
            vector<int> move=*it;
            vector<int> xx = x;
            for(int k = 0; k < 2; k++){
              xx[k]+=move[k]*mirror[k];
            }
            
            if(a[xx[0]][xx[1]]){
              if(move[0]!=0 and move[1]!=0 and
                a[x[0]][xx[1]]==0 and a[xx[0]][x[1]]==0){
                  aborted=true;
                  break;
              }
              else{
                if(move[0]!=0 and a[xx[0]][x[1]]==1){
                  mirror[0]*=-1;
                  xx[0]=x[0];
                }
                if(move[1]!=0 and a[x[0]][xx[1]]==1){
                  mirror[1]*=-1;
                  xx[1]=x[1];
                }
              }
            }
            x=xx;
          }
          if(not aborted){
            nimages += x==source;
            if(x==source){
              done[make_pair(tx/g,ty/g)]=true;
            }
          }
        }
      }
    }
  }
  int res=nimages;
  cout << "Case #" << case_index << ": " << res;
  cout << endl;
}

int main(int argc, char* argv[]) {
  int n; 
  cin >> n;
  for(int i = 1; i <= n; i++){
    cerr << i << " ";
    run(i);
  }
  cerr << endl;
  return 0;
}
