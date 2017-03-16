#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <inttypes.h>
using namespace std;
int main()
{
  int T;
  long E,N,R;
  long v[10000];
  long begin[10000];
  long temp;
  long answer;
  long i,j,k,zero,energy;
  cin >> T;
  for(i=0;i<T;i++){
	cin >> E;
	cin >> R;
	cin >> N;
	zero=0;
	for(j=0;j<N;j++){
		cin >> temp;
		v[j]=temp;
		begin[j]=0;
	}
	begin[0]=E;
	for(j=1;j<N;j++){
		for(k=j;k<N;k++){
			if(v[j-1] < v[k]){
				begin[j] = max(begin[j],min(E,begin[j-1]+R*(k-j+2))-R*(k+1-j));
			}
		}
	}
	energy=E;
	answer =0;
	for(j=1;j<N;j++){
		answer= answer + v[j-1]*(energy-begin[j]);
		energy = R+begin[j];
		energy = min(energy,E);
	}
	answer = answer + v[N-1]*energy;
	cout << "Case #" << i+1 << ": " << answer << endl;
		
  }
  return 0;
}
