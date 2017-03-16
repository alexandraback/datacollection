#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;




int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
int A,B,K;
cin>>A>>B>>K;
long long c=0;
for(int a=0;a<A;++a) for(int b=0;b<B;++b) for(int k=0;k<K;++k){if(!((a&b)^k))c++;}
	cout<<"Case #"<<i+1<<": "<<c <<endl;
	}
	return 0;
}
