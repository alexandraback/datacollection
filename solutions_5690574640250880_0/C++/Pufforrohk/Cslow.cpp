#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;


int num[52][52];
bool vis[52][52];

bool check(string& s,int R,int C,int M){
  for(int i=0;i<R+2;i++)
    for(int j=0;j<C+2;j++){
      num[i][j]=-2;
      vis[i][j]=false;
    }
  for(int i=0;i<R*C;i++){
    if(s[i]=='.')
      num[i/C+1][i%C+1]=0;
    else
      num[i/C+1][i%C+1]=-1;     
  }
  int si=-1,sj=-1;
  for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
      if(num[i][j]>-1){
	int cnt = 0;
	for(int di=i-1;di<=i+1;di++)
	  for(int dj=j-1;dj<=j+1;dj++)
	    if(num[di][dj] == -1)
	      cnt++;
	num[i][j]=cnt;
	if(cnt==0){
	  si=i;
	  sj=j;
	}
      }
  if(si==-1){
    return false;
  }
  /*
  cout<<endl;
  for(int i=1;i<=R;i++){
    for(int j=1;j<=C;j++)
      cout<<num[i][j]<<" ";
    cout<<endl;
  }  
  cout<<si<<" "<<sj<<endl;*/

  queue<pair<int,int> > q;
  q.push(make_pair(si,sj));
  vis[si][sj]=true;
  int cnt = 0;
  while(!q.empty()){
    cnt++;
    auto p = q.front();
    q.pop();
    if(num[p.first][p.second]==0){
      for(int i=-1;i<=1;i++)
	for(int j=-1;j<=1;j++){
	  int vi=p.first+i;
	  int vj=p.second + j;
	  if(num[vi][vj]>=0 && !vis[vi][vj]){
	    vis[vi][vj]=true;
	    q.push(make_pair(vi,vj));
	  }
	}
    }
  }
  //  cout<<cnt<<endl;
  if(cnt == R*C-M){
    s[(si-1)*C+(sj-1)]='c';
    return true;
  }else
    return false;
}

void print(string& s, int R, int C){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout<<s[i*C+j];
    }
    cout<<endl;
  }
}


void solve(){
  int R,C,M;
  cin>>R>>C>>M;
  string s(R*C,'.');
  cout<<endl;
  for(int i=0;i<M;i++)
    s[i]= '*';
  if(M==R*C-1){
    s[M]='c';
    print(s,R,C);
    return;
  }
  do{
    //    cout<<s<<endl;
    if(check(s,R,C,M)){
      print(s,R,C);
      return;
    }
  }while(next_permutation(s.begin(),s.end()));
  cout<<"Impossible"<<endl;
  return;
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
  }
}
