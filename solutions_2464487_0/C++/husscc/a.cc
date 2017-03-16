#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>

typedef long long ll;

using namespace std;

int T;
ll r, t;

int main(){
	cin>>T;
	for(int i = 1; i <= T; i++){
		cin>>r>>t;
		ll cnt = 0, radix = r+1;
		while(1){
			t -= (radix*radix - (radix-1)*(radix-1));
			//cout<<t<<endl;
			if(t >= 0){
				cnt++; radix+=2;
			}else{
				break;
			}
		}
		printf("Case #%d: %ld\n", i, cnt);
	}
}