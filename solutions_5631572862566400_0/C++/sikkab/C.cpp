#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair


typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;
class graphal
{
  public:
    int n;
    bool *vis;
    //2 1->bidirectional, 2->reverse edges
    vector <int> *ed, *rd;
    graphal(const int &n){
      this->n=n;
      ed = new vector<int>[n];
      rd = new vector<int>[n];
      vis = new bool[n+1];
      memset(vis,false,sizeof(bool)*(n+1));
    }
    ~graphal(){ delete[] ed;delete[] rd; }
    void add(int a, int b){ ed[a].push_back(b);rd[b].push_back(a); }
    int dfs(int ix=0, int bg=0, bool rev=false){
      //cout<<"ix rev: "<<ix<<" "<<rev<<endl;
      if(vis[ix] && rev==false && ix==bg)return 0;
      if(vis[ix] && rev==false && ix!=bg)return -1;
      vis[ix]=true;
      int res=1;
      if(!rev){
        for(auto i:ed[ix]){
          if(ed[i][0]==ix){
            res=dfs(i,bg,true)+1;
          }else{
            int t=dfs(i,bg,false);
            if(t==-1)res=-1;
            else res=t+1;
          }
        }
      }else{
        bool added=false;
        for(auto i:rd[ix])
          if(!vis[i]){
            added=true;
            res=max(res,dfs(i,bg,true)+1); 
          }
        if(!added){
          int tret=0;
          for(auto i=0;i<n;i++)
            if(!vis[i] && ed[ed[i][0]][0]==i){
              vis[i]=true;
              tret = max(tret,dfs(ed[i][0],ed[i][0],true)+1);
            }
          res+=tret;
        }
      }
      vis[ix]=false;
      return res;
    }
};
void doit() {
  int n,res=0;
  scanf("%d", &n);
  graphal g(n);
  for(auto i=0;i<n;i++){
    int t;
    scanf("%d", &t);
    g.add(i,t-1);
  }
  for(auto i=0;i<n;i++){
    //cout<<"start: "<<i<<endl;

    res=max(res,g.dfs(i,i));
    //cout<<"end  : "<<i<<" "<<res<<endl;
  }
  cout<<res;
}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d: ",i);
    doit();
    cout<<endl;
  }
  return 0;
}
