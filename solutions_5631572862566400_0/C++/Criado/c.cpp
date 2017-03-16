#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;

int bff[1000];
int mark[1000];
int finalbff[1000];
vector<vi> reverses;

int dfs(int boy) {
  if(reverses[boy].empty()) return 1;
  int best=0;

  for(int i=0; i<reverses[boy].size(); i++)
    if(reverses[boy][i]!=bff[boy]) {
      best=max(dfs(reverses[boy][i]), best);
    }
  return best+1;
}

int main() {
  int t, n;
  int len;
  cin>>t;
  for(int cas=1; cas<=t; cas++) {
    cout<<"Case #"<<cas<<": ";
    cin>>n;
    reverses=vector<vi>(n);

    for(int i=0; i<n; i++) { cin>>bff[i]; bff[i]--; reverses[bff[i]].push_back(i);}

    len=0;
    memset(mark, -1, n*sizeof(int));
    for(int i=0; i<n; i++) {
      if(i==bff[bff[i]]) { mark[i]=0;}
    }

    for(int i=0; i<n; i++)
      if(mark[i]==0) len+=dfs(i);
    
    for(int i=0; i<n; i++) {
      memset(mark, -1, n*sizeof(int));
      int curmark=0, j=i;

      for(; mark[j]==-1; j=bff[j]) {
        mark[j]=curmark;
        curmark++;
      }
      if(curmark-mark[j]>len) len=curmark-mark[j];
    }
   
    cout<<len<<endl;

  }
  return 0;
}
