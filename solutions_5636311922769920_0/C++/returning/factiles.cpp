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
#define foreach(i, n) for (ull i = 0; i < (ull)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void cal(ll K, ll C, ll S){
	//the 1st choice can cover C places. The 2nd can cover remaining C places,....
	ll k=1;
	unordered_map<ll, ll> mapping;
	for(int i=0; i<C; i++){
		mapping.insert(make_pair(i, k));
		k = k*(ull)K;
	}
	ll covered=0;
	while(covered<K){
		//get K^(C-1)*covered + K^(C-2)*(covered+1) + .....+ K^(0)*(covered+C-1)
		//or K^(C-1)*covered + K^(C-2)*(covered+1) + 
		ll result = 0;
		ll i = C-1;
		while(covered<K && i>=(ll)0){
			result += mapping[i]*covered;
			i--;
			covered++;
		}
		cout<<result+1<<" ";
	}
}
int main(int argc, char** argv) {
	int T;
	cin>>T;
	foreach(itest, T){
		ll K, C, S;
		cin>>K; cin>>C; cin>>S;
		if(S*C<K)
			cout<<"Case #"<<itest+1<<": IMPOSSIBLE"<<endl;
		else{
			cout<<"Case #"<<itest+1<<": ";
			cal(K,C,S);
			cout<<endl;
		}
	}
	return 0;
}
