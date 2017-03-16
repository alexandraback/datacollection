#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;

#define maxn 110
#define datat int
#define ansdatat int

int n;

void init_deal(){
}

int main(){
	
	int tttt;
	scanf("%d", &tttt);
	for(int ttt = 1;ttt<=tttt;ttt++){
		printf("Case #%d: ",ttt);
		long long r, t;
		cin>>r>>t;
		//cout<<r<<" "<<t<<endl;

		int ans = 0;
		long long now_w = r, now_t = t;
		while(now_t>0){
			long long tmp = (now_w+1)*(now_w+1)-now_w*now_w;
			if(now_t >= tmp){
			   now_t-=tmp;
			   ans++;
			   now_w+=2;
			}
			else
				break;
		}

		cout<<ans<<endl;


	}
	

	return 0;
};

