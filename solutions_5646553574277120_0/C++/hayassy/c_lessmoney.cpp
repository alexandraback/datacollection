#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int C,D,V;
    cin >> C >> D >> V; cin.ignore();
    int *cs = new int[V];
    for(int j=0; j<D; j++){
      cin >> cs[j];
    } cin.ignore();

    bool *ms = new bool[V];
    for(int j=0; j<V; j++){
      ms[j] = false;
    }
    for(int j=0; j<D; j++){
      for(int k=V-1; k>=0; k--){
        if(ms[k]==true && k+cs[j]<V){
          ms[k+cs[j]] = true;
        }
      }
      ms[cs[j]-1] = true;
    }

    int ans=0;
    while(true){
      bool end=true;
      for(int k=0; k<V; k++){
        if(ms[k]==false){
          end=false; break;
        }
      }
      if(end) break;

      //
      vector<vector<int> > hoge;
      for(int j=0; j<V; j++){
        if(ms[j]) continue;
        vector<int> tmp;
        tmp.push_back(j+1);
        for(int k=0; k<j; k++){
          if(ms[k])
            tmp.push_back(j-k);
        }
        vector<int> tmp2;
        for(size_t t=0; t<tmp.size(); t++){
          bool flg=true;
          for(int l=0; l<D; l++){
            if(cs[l]==tmp[t]){
              flg=false; break;
            }
          }
          if(flg) tmp2.push_back(tmp[t]);
        }
        hoge.push_back(tmp2);
      }

      //
      int maxv=1, maxc=0;
      for(int j=0; j<V; j++){
        int count = 0;
        for(size_t k=0; k<hoge.size(); k++){
          for(size_t l=0; l<hoge[k].size(); l++){
            if(hoge[k][l]==j+1){
              count++; break;
            }
          }
        }
        if(maxc < count){
          maxv = j+1;
          maxc = count;
        }
      }
      //
      cs[D] = maxv; D++;
      for(int j=V-1; j>=0; j--){
        if(ms[j] && j+maxv<V)
          ms[j+maxv] = true;
      }
      ms[maxv-1] = true;
      ans++;
    }

    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;
}
