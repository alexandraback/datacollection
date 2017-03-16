#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int n;
double a[1050], b[1050];
void solve(){
  cin >> n;
  for(int i = 0;i < n;i++)cin >> a[i];
  for(int i = 0;i < n;i++)cin >> b[i];
  int res = 0;
  set<double> ken;
  for(int i = 0;i < n;i++)ken.insert(a[i]);
  for(int i = 0;i < n;i++){
    set<double>::iterator it = ken.upper_bound(b[i]);
    if(it == ken.end()){
      res++;
      ken.erase(ken.begin());
    }
    else{
      ken.erase(it);
    }
  }
  cout << n - res << " ";
  for(int i = 0;i < n;i++)ken.insert(b[i]);
  res = 0;
  for(int i = 0;i < n;i++){
    set<double>::iterator it = ken.upper_bound(a[i]);
    if(it == ken.end()){
      res++;
      ken.erase(ken.begin());
    }
    else{
      ken.erase(it);
    }
  }
  cout << res << endl;
}

int main(){
  int t;
  cin >> t;
  for(int i = 1;i <= t;i++){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
