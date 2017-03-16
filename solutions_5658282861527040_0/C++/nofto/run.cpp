#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int log2int(uint64_t val){
    int ret = -1;
    while(val!=0){
        val >>= 1;
        ret++;
    }
    return ret;
}
uint64_t pow2(int n){
	uint64_t res=1;
	for(int i=0;i<n;i++) res*=2;
	return res;
}

uint64_t lessThanAbit(uint64_t A,int k){
	int a=log2int(A-1);
	if(k>a) return 0;
	if(k==a) return A-pow2(a);
	return pow2(a-1)+lessThanAbit(A-pow2(a),k);
}

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{
		int A,B,K;
		cin >> A;
		cin >> B;
		cin >> K;
		int res=0;
		for(int i=0;i<A;i++) for(int j=0;j<B;j++) if((i&j)<K) res++;
		cout << "Case #" << t << ": " << res << "\n"; 
	}
  return 0;
}
