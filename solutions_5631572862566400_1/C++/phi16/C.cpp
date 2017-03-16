#include<iostream>
#include<queue>

template <class T> void dump(const std::vector<T> &t){
  std::cout << "[";
  for(auto it : t){
    std::cout << it << ",";
  }
  std::cout << "]" << std::flush;
}

int retrive(int x,int b,const std::vector<std::vector<int> > &g){
  int mx = 0;
  for(int i=0;i<g[x].size();i++){
    if(g[x][i]!=b){
      int c = retrive(g[x][i],-1,g);
      if(mx < c)mx = c;
    }
  }
  return mx+1;
}

int main(){
  int ti;
  std::cin >> ti;
  for(int txi = 1; txi <= ti; txi++){
    int n;
    std::cin >> n;
    std::vector<bool> b(n);
    std::vector<int> f(n);
    std::vector<std::vector<int> > g(n);
    for(int i=0;i<n;i++){
      std::cin >> f[i], f[i]--, b[i] = false;
      g[f[i]].push_back(i);
    }
    std::vector<std::vector<int> > cycles;
    int mc = 0;
    for(int i=0;i<n;i++){
      std::vector<int> br(n,0);
      std::vector<int> cs;
      if(b[i]==false){
        int j = i;
        int cnt = 0;
        while(br[j]==0 && b[j]!=true){
          br[j] = ++cnt;
          cs.push_back(j);
          j = f[j];
        }
        if(b[j]==true)continue;
        cs = std::vector<int>(cs.begin()+br[j]-1,cs.end());
        for(int i=0;i<cs.size();i++){
          b[cs[i]] = true;
        }
        if(cs.size()>=3){
          if(mc<=cs.size())mc = cs.size();
        }else cycles.push_back(cs);
      }
    }
    int mr = 0;
    for(int i=0;i<cycles.size();i++){
      int d1 = retrive(cycles[i][0],cycles[i][1],g);
      int d2 = retrive(cycles[i][1],cycles[i][0],g);
      mr += d1+d2;
    }
    std::cout << "Case #" << txi << ": " << (mc<mr?mr:mc);
    std::cout << std::endl;
  } 
  return 0;
}