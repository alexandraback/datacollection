#include <iostream>
#include <queue>  
#include <vector>   
#include <set>
#include <utility>
#include <math.h>       /* atan */
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define foreach(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;

int main(int argc, char** argv) {
	int T;
	cin>>T;
	foreach(itest, T){
		int N;
		cin>>N;
		unordered_map<int, int> status;
		int number;
		for(int i=0; i<2*N-1; i++){
			for(int j=0; j<N; j++){
				cin>>number;
				status[number] ++; 
			}
		}
		vector<int> result;
		for(auto it= status.begin(); it!=status.end(); it++){
			if(it->second%2 == 1){
				result.push_back(it->first);
			}
		}
		if(result.size() != N) cout<<"impossible"<<endl;
		sort(result.begin(), result.end());
		cout<<"Case #"<<itest+1<<": ";
		for(int i=0; i<N; i++)
			cout<<result[i]<<" ";
		cout<<endl;
	}
	return 0;
}
