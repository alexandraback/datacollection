#include<iostream>
#include<stack>

using namespace std;

bool zero[51][51];
bool nomine[51][51];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int n,m,mine,no;

bool compute(int x, int y, int curnomine) {
  if (curnomine == no) {
    return true;
  }
  int newnomine[8];
  int newnomine_num =0;
  for (int i=0; i<8; ++i) {
    int nx = x+dx[i]; 
    int ny = y+dy[i]; 
    if (nx>=0 && ny>=0 && nx<n && ny<m) {
      if (!nomine[nx][ny]) {
        newnomine[newnomine_num++] = nx*m+ny;
        nomine[nx][ny] = true;
      }
    }
  }
  for(int i=0; i<newnomine_num; ++i) {
    int temp = newnomine[i];
    if (compute(temp/m, temp%m, curnomine+newnomine_num)) {
      return true;  
    }
  }
  for(int i=0; i<newnomine_num; ++i) {
    int temp = newnomine[i];
    nomine[temp/m][temp%m] = false;
  }
  return false;
}

int main() {
  int ca; 
  cin>>ca;
  for(int cas=1; cas<=ca; ++cas) {
    cout<<"Case #"<<cas<<":"<<endl;
    cin>>n>>m>>mine; 
    no = n*m-mine;
    if (no == 1) {
      for(int i=0; i<n; ++i) {
        for(int j=0 ; j<m; ++j) {
          if (!i && !j) {
            cout<<'c';
          } else {
            cout<<'*';
          }
        }
        cout<<endl;
      }
      continue;
    }
    memset(nomine, 0, sizeof(nomine));
    nomine[0][0] = true;
    if (compute(0,0,1)) {
      for(int i=0 ;i<n ;++i) {
        for(int j=0; j<m; ++j) {
          if (!i && !j) cout<<'c';
          else if (nomine[i][j]) cout<<'.';
          else cout<<'*';
        }
        cout<<endl;
      }
    } else {
      cout<<"Impossible"<<endl;
    }
  }
}
