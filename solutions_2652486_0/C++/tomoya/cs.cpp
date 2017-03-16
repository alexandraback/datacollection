#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

void make_patten(int idx,int n,int m,vector<int> &mtmp,
		 set< vector<int> > &allp){
  if( idx == n ){
    vector<int> tmp = mtmp;
    sort(tmp.begin(),tmp.end());
    allp.insert(tmp); return; 
  }

  for(int i=2; i<=m; i++){
    mtmp[idx] = i;
    make_patten(idx+1,n,m,mtmp,allp);
  }
  return;
}

int main(){
  int T;
  cin >> T;
  for(int test_case=1; test_case<=T; test_case++){
    int r,n,m,k; cin >> r >> n >> m >> k;
    
    vector< vector<int> > tab(r,vector<int>(k));
    for(int i=0; i<r; i++){
      for(int j=0; j<k; j++) cin >> tab[i][j];
    }
    set< vector<int> > allp;
    vector<int> mtmp(n);
    make_patten(0,n,m,mtmp,allp);
    vector< vector<int> > rpatten;
    for(set<vector<int> >::iterator it=allp.begin(); it!=allp.end(); it++){
      vector<int> tmp;
      vector<int> allpt = *it;
      int bn = allpt.size();
      for(int v=0; v<(1<<bn); v++){
	int pu = 1;
	for(int j=0; j<bn; j++){
	  if( (1<<j) & v ){ pu *= allpt[j];}
	}
	tmp.push_back( pu );
      }
      sort(tmp.begin(),tmp.end());
      rpatten.push_back(tmp);
    }

    cout << "Case #" << test_case << ":" << endl;
    for(int i=0; i<r; i++){

      set<vector<int> >::iterator it=allp.begin();
      set<vector<int> >::iterator hit = it;
      for(int j=0; j<(int)rpatten.size(); j++, it++){
	bool flg = true;
	for(int k=0; k<(int)tab[i].size(); k++){
	  if( !binary_search( rpatten[j].begin(), rpatten[j].end(), tab[i][k] ) ){
	    flg = false;
	  }
	}
	if( flg ){ hit = it; break; }
      }
      string ans = "";
      for(int j=0; j<(int)(*hit).size(); j++){
	ans += char('0' + (*hit)[j]);
      }
      cout << ans << endl;
    }
    
  }
  return 0;
}
