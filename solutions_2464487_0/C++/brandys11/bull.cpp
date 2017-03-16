#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>

using namespace std;

long long solve(){
	long long _r, _t,res=-1ll;
	cin >> _r >> _t;
	__uint128_t area=0,r=_r,t=_t;
	/*while(area <= t){
		//		area -= r*r; r++;
		//area += r*r; r++;
		area += 2*r+1; r+=2;
		cerr<<(long lo << (long long) (2*r+1) << endl;
		res++;
	}*/
	__uint128_t a1,an,sn;
	long long a = 1ll,b=1023456789ll,s=0; //b = 10;
	while(b-a>1){
		s = (a+b)/2ll;
		a1 =  2*r+1; an=2*(r+2*(s-1))+1; sn = ((a1+an)*(s))/2;
		if(sn > t) b = s;
		else a = s;
				//cout << a <<" "<<s<< " " << b << " " << (long long)sn<< endl;// s++;
	}
	return a;
}
int main(void){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		cout << "Case #" << t <<": "<< solve() << endl;
	}
}