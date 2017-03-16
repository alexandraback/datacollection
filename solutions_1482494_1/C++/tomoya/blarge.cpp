#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;



int main(){
  int tc;
  cin >> tc;
  for(int tid = 1; tid <= tc; tid++){
    int n; cin >> n;

    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
      cin >> a[i] >> b[i];
    }
    vector< int > flg(n,0);
    int ans = 0;
    int stars = 0;
    while(1){
      bool f = false;
      for(int i=0; i<n; i++){
	if( flg[i] <= 1 && b[i] <= stars){
	  ans += 1;
	  stars = stars + (flg[i] == 1 ? 1 : 2);
	  flg[i] = 3;
	  f =  true;
	  break;
	}
      }
      if( f )continue;
      vector< pair<int,int> > tab;
      for(int i=0; i<n; i++){
	if( flg[i] == 0 && a[i] <= stars){
	  tab.push_back(make_pair(b[i],i));
	}
      }
      if( tab.size() == 0 )break;
      sort( tab.begin(), tab.end(), greater< pair<int,int> >() );
      int idx = tab[0].second;
      ans += 1;
      flg[idx] = 1;
      stars += 1;
    }

    printf("Case #%d: ",tid);
    if( stars != n * 2 )printf("Too Bad\n");
    else printf("%d\n",ans);
  }
  return 0;
}
