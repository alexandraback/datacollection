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
double maxt = 2e18;

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

		long long ans = 0;
		long long now_w = r, now_t = t;
		
		long long st = -1, en = 2000000000;
		while(st+1<en){
			long long k = st+(en-st)/2;
			long long max_r = r+2*k+1;
			double tot_r = (double(r)+max_r)*(max_r-r+1)/2;
			long long tot = (r+max_r)*(max_r-r+1)/2;
			//cout<<"tot_r = "<<tot_r<<endl;
			if(k == -1){
				break;
			}
			else{
				if(tot_r<=maxt && tot<=t){
					if(ans < k+1)
					   ans = k+1;
					st = k;
				}
				else
					en = k;
			}


		}

		/*
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
		*/

		cout<<ans<<endl;


	}
	

	return 0;
};

