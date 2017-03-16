#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


vector<pair<int,int> > a,b;

bool ac1[1010],ac2[1010];

int N;

bool comp1(int ct1,int stars) {
  if(ct1 == N)
    return false;
  return (a[ct1].first <= stars);
}

int comp() {
  int stars=0,ct1=0,compt1=0;
  for(int i=0;i<N;i++) {
    while(stars < b[i].first) {
      while(ct1<N && ac2[a[ct1].second])
        ct1++;
      if(comp1(ct1,stars)) {
        ac1[a[ct1].second]=true;
        ct1++;
        compt1++;
        stars++;
      }
      else
        return -1;
    }
    ac2[b[i].second]=true;
    if(ac1[b[i].second])
      stars++;
    else
      stars+=2;
  }
  return N+compt1;
}
        
      
  

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
    cin >> N;
    a.clear();
    b.clear();
    int ai,bi;
    for(int i=0;i<N;i++) {
      cin >> ai >> bi;
      a.push_back(make_pair(ai,i));
      b.push_back(make_pair(bi,i));
      ac1[i]=ac2[i]=false;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //for(int i=0;i<N;i++)
    //  cout << a[i].second << ' ' << b[i].second << endl;
    

    int v=comp();
        
    if(v>0)
    		cout << "Case #" << c << ": " <<  v << endl;
    else
       cout << "Case #" << c << ": Too Bad" << endl;
	}
	return 0;
}
