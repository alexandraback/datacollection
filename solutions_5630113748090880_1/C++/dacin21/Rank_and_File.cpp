#include <bits/stdc++.h>

using namespace std;

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin.tie(0);
  int T;
  cin >> T;
  for(int cas=0;cas<T;++cas){
    cout << "Case #"<<cas+1<<": ";
    int N;
    cin >> N;
    vector<vector<int> > data(N);
    vector<char> cnt(2510, 0);
    int tmp;
    for(int i=0;i<2*N-1;++i){
      for(int j=0;j<N;++j){
        cin >> tmp;
        cnt[tmp]^=1;
      }
    }
    for(int i=0;i<(int)cnt.size();++i){
      if(cnt[i]!=0) cout << i << ' ';
    }
    cout << "\n";


  }

}
