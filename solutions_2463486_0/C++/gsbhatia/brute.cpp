#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque> 
#include<ext/numeric>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<tr1/unordered_map>
#include<tr1/unordered_set>
#include<utility>
#include<vector>
using namespace std;

#define ForEach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it) 
typedef long long int i64;


bool f(i64 x){
	char C[1<<4]; int M=0;
	do{
		C[M++]=x%10; x/=10;
	}while(x);
	bool ok=1; int i=0,j=M-1;
	while(i<j&&ok) ok&=C[i++]==C[j--];
	return ok;
}

int g(const vector<i64>&V, i64 x){
	return upper_bound(V.begin(),V.end(),x)-V.begin();
}

int main(){
	vector<i64> V; V.reserve(1<<10);
	for (i64 i=1;i<10123456;++i){
		if (f(i)){
			i64 j=i*i;
			if (f(j)) V.push_back(j);
		}
	}
	int ncases; cin>>ncases;
	for (int kase=1;kase<=ncases;++kase){
		i64 A,B; cin>>A>>B;
		cout<<"Case #"<<kase<<": "<<g(V,B)-g(V,A-1)<<endl;
	}
	return 0;
}