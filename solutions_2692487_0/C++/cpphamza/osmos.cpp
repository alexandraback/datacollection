//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<cstring>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big unsigned long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

big A, N;
big arr[1000];

int main(){

//  freopen("/Users/hamza/1.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/A-small-attempt1.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/A-small-attempt1.out", "wt", stdout);
  
	int TT; cin >> TT;
	for(int t = 1 ; t <= TT ; t++){
    cin >> A >> N;
    
    for(int i = 0 ; i < N ; i++)
      cin >> arr[i];
    
    sort(arr, arr+N);
    
//    cout << A << endl;
//    for(int i = 0 ; i < N ; i++)
//      cout << arr[i] << " " ;
//    cout << endl;
    
    big best = N, current = 0;
    for(int i = 0 ; i < N ; i++){
      if(A > arr[i]){
        A += arr[i];
        continue;
      }
      
      //stop here
      best = min(best, current+N-i);
      
      //take it
      if(A == 1)goto done;
      
      while(true){
        current ++;
        if(current > best)
          goto done;
        A += A-1;
        if(A > arr[i])
          break;
      }
      A += arr[i];
    }
    best = min(best, current);
  done:
		cout << "Case #" << t << ": " << best << endl;
	}

	return 0;
}
