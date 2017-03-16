//In the Name of God
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 10000 + 10;
int T , E , R , n , e , ans , a[maxn] , v[maxn] , MAX[maxn];

int main(){
  cin >> T;
  for(int z = 0 ; z < T ; z++){
    memset(a , 0 , sizeof a);
    memset(MAX , 0 , sizeof MAX);
    ans = 0;
    cin >> E >> R >> n;
    e = E;
    for(int i = 0 ; i < n ; i++)
      cin >> v[i];
    for(int i = 0 ; i < n ; i++)
      MAX[i] = i;
    vector <int> v1;
    for(int i = 0 ; i < n ; i++){
      while(v1.size() && v[v1.back()] < v[i]){
	MAX[v1.back()] = i;
	v1.pop_back();
      }
      v1.push_back(i);
    }
    for(int i = 0 ; i < n ; i++){
      if(i == MAX[i]){
	a[i] += e;
	e = 0;
      }
      else{
	a[i] += min((MAX[i] - i) * R - (E - e) , e);
	e -= min((MAX[i] - i) * R - (E - e) , e);
      }
      e += R;
      if(e > E)
	e = E;
    }
    for(int i = 0 ; i < n ; i++)
      ans += v[i] * a[i];
    cout << "Case #" << z + 1 << ": " << ans << endl;
  }
  return 0;
}
