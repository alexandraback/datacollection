#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <complex> 
#include <string>
#include <vector> 
#include <list>
#include <deque> 
#include <stack> 
#include <queue> 
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm> 
#include <numeric> 
#include <typeinfo> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <climits> 
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int t;
ll a,n;
vector<ll> s;
int main(void){
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		s.clear();
		scanf("%lld%lld",&a,&n);
		for(int i=0;i<n;i++){
			ll aa;
			scanf("%lld",&aa);
			s.push_back(aa);
		}
		sort(s.begin(),s.end());
		ll res=n;
		for(int i=n;i>=0;i--){
			ll cnt=n-i;
			ll my=a;
			bool f=true;
			for(int j=0;j<i;j++){
				if(!f)break;
				if(my>s[j])my+=s[j];
				else{
					if(my==1){
						f=false;
						break;
					}else{
						while(my<=s[j]){
							cnt++;
							my+=my-1;
						}
						my+=s[j];
					}
				}
			}
			if(f)res=min(res,cnt);
		}
		printf("Case #%d: %lld\n",test,res);
	}
	return 0;
}