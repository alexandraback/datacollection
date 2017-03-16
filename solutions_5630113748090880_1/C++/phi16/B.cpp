#include<iostream>
#include<queue>

template <class T> void dump(const std::vector<T> &t){
  std::cout << "[";
  for(auto it : t){
    std::cout << it << ",";
  }
  std::cout << "]" << std::flush;
}

int main(){
  int ti;
  std::cin >> ti;
  for(int txi = 1; txi <= ti; txi++){
    int n;
    std::cin >> n;
    std::vector<bool> ib(n*2-1,true);
    std::vector<std::vector<int> > iv(n*2-1,std::vector<int>(n));
    for(int i=0;i<n*2-1;i++){
      for(int j=0;j<n;j++){
        std::cin >> iv[i][j];
      }
    }
    std::vector<std::vector<int> > vs1,vs2;
    std::vector<int> ci;
    int idx = 0;
    for(int i=0;i<n;i++){
      bool b = false,con = false;
      int v1=-1,v2=-1;
      int m = 2501;
      for(int j=0;j<iv.size();j++){
        if(ib[j] && iv[j][i] <= m){
          if(iv[j][i] < m){
            m = iv[j][i];
            b = con = false;
          }
          if(!b){
            v1 = j;
            b = true;
          }else{
            v2 = j;
            con = true;
          }
        }
      }
      if(!con){
        vs1.push_back(iv[v1]);
        vs2.push_back(iv[v1]);
        ci = iv[v1];
        idx = i;
        ib[v1] = false;
      }else{
        vs1.push_back(iv[v1]);
        vs2.push_back(iv[v2]);
        ib[v1] = ib[v2] = false;
      }
    }
    std::cout << "Case #" << txi << ":";
    for(int i=0;i<n;i++){
      if(idx == i){
        std::cout << " " << vs1[i][idx];
      }else if(vs1[i][idx] == ci[i]){
        std::cout << " " << vs2[i][idx];
      }else{
        std::cout << " " << vs1[i][idx];
      }
    }
    std::cout << std::endl;
  } 
  return 0;
}