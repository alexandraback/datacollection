#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;

bool back(int sum1, int sum2, int n, set<int> & a1, set<int> & a2, vector<int> & arr, set<pair<int,int> > & vis)
{

  if ((sum1 == sum2) && (sum1 != 0)) {
    bool f = true;
    for (set<int>::iterator it = a1.begin(); it!= a1.end(); it++) {
      if (!f) {
        cout << " ";
      } else {
        f = false;
      }
      cout << *it;
    }
    cout << endl;
    f = true;
    for (set<int>::iterator it = a2.begin(); it!= a2.end(); it++) {
      if (!f) {
        cout << " ";
      } else {
        f = false;
      }
      cout << *it;
    }
    cout << endl;
    return true;
  }


  if (n > arr.size()) {
    return false;
  }

  if (vis.find(pair<int,int>(n,sum1-sum2)) != vis.end()) {
    return false;
  }

  a1.insert(arr[n]);
  if (back(sum1+arr[n],sum2,n+1,a1,a2,arr,vis)) {
    return true;
  }
  a1.erase(arr[n]);
  a2.insert(arr[n]);
  if (back(sum1,sum2+arr[n],n+1,a1,a2,arr,vis)) {
    return true;
  }
  a2.erase(arr[n]);

  if (back(sum1,sum2,n+1,a1,a2,arr,vis)) {
    return true;
  }

  vis.insert(pair<int,int>(n,sum1-sum2));

  return false;

}

int main()
{

  int nc;
  cin >> nc;
  for (int c=1;c<=nc;c++) {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
      cin >> arr[i];
    }
    set<int> a1;
    set<int> a2;
    cout << "Case #" << c << ":" << endl;

    set<pair<int,int> > visited;

    if (!back(0,0,0,a1,a2,arr,visited)) {
      cout << "Impossible" << endl;
    }

  }

  return 0;
}
