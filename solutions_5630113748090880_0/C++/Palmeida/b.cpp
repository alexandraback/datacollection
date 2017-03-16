#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){
  int aux;
  int T, N;
  map<int,int> m;

  cin >> T;
  for( int i=0; i<T; i++ ){
    cout << "Case #" << i+1 << ": ";
    cin >> N;
    m.clear();
    for( int j=0; j<(2*N-1); j++ ){
      for( int k=0; k<N; k++ ){
	cin >> aux;
	m[aux]++;
      }
    }

    for( map<int,int>::iterator it=m.begin(); it != m.end(); it++ ){
      if( it->second % 2 != 0 )	cout << it->first << " ";
    }
    cout << endl;
  }
  return 0;
}
