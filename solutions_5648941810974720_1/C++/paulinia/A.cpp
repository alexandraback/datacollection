#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<math.h>
//structures
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<deque>
#include<string>
#include<complex>
#include<sstream>
#include<cctype>
#include<iomanip>
#include<bitset>

using namespace std;

#define REP(i,n)	for(int i=1;i<=n;i++)
#define FOR(i,n)	for(int i=0;i<n;i++)
#define FOB(i,n)	for(int i=n;i>=1;i--)
#define druha(x) ((x)*(x))
#define MP(x,y)	make_pair((x),(y))
#define infinity 2000000999
#define ii pair<int, int>
#define lli long long int
#define lili pair<lli, lli>
#ifdef EBUG
#define DBG	if(1)
#else
#define DBG	if(0)
#endif

int getn()
{
  int h;
  scanf("%d",&h);
  return h;
}

template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>&par) {
  cout << "[" << par.first<<" ; "<<par.second<<"]";
  return out;
}

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  FOR(i, v.size()){
    if(i) cout<<" ";
    cout<<v[i];
  }
  cout<<endl;
  return out;
}

int main(){
  string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  int poradie[] = {0, 2, 6, 8, 3, 7, 5, 4, 1, 9};
  char pismeno[] = {'Z', 'O', 'W', 'H', 'F', 'V', 'X', 'S', 'G', 'I'};
  
  int t = getn();
  FOR(l, t){
    vector<int> kolko(10, 0);
    string s;
    cin >> s;
    map<char, int> vyskyty;
    for(char c : s){
      vyskyty[c] ++;
    }
    
    FOR(i, 10){
      DBG{
        cout << "Bef: " << nums[poradie[i]] << " : " << endl;
        for(auto vec : vyskyty){
          cout << vec << endl;
        }
      }
      int pocet = vyskyty[pismeno[poradie[i]]];
      DBG cout << "pocet = " << pocet << endl;
      kolko[poradie[i]] = pocet;
      for(char c : nums[poradie[i]]){
        vyskyty[c] -= pocet;
      }
    }
    
    cout << "Case #" << l + 1 << ": ";
    
    FOR(i, 10){
      FOR(j, kolko[i]){
        cout << i;
      }
    }
    cout << endl;
    
  }
}
