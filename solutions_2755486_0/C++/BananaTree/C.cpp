#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int di, ni, wi, ei;
	int si, delta_di, delta_pi, delta_si;
};
Node node[20];

int main(){		
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int t, n;
	int wall[1000005];
	int middle[1000005];
	cin>>t;
	for(int j=1; j<=t; j++){
		int res = 0;
		int days = 0;
		int offset = 500000;
		memset(wall, 0, sizeof(wall));
		memset(middle, 0, sizeof(middle));
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>node[i].di>>node[i].ni>>node[i].wi>>node[i].ei
			>>node[i].si>>node[i].delta_di>>node[i].delta_pi>>node[i].delta_si;
			days = max(days, node[i].di+node[i].ni*node[i].delta_di);
		}
		vector<pair<int, int> > v;		
		vector<int> height;
		for(int i=0; i<=days; i++){
			v.clear();
			height.clear();
			for(int cur=0; cur<n; cur++){
				if(node[cur].ni<=0 || node[cur].di>i)
					continue;
				if((i-node[cur].di)%(node[cur].delta_di)!=0)
					continue;
				int start = node[cur].wi;
				int end = node[cur].ei;
				bool okay = false;
				for(int k=start; k<=end; k++){
					if(wall[offset+k]<node[cur].si){
						okay=true;
						v.push_back(make_pair(start, end));
						//cout<<"start: "<<start<<" end: "<<end<<endl;
						height.push_back(node[cur].si);
						break;
					}
					if(k!=end && middle[offset+k]<node[cur].si){
						okay = true;
						v.push_back(make_pair(start, end));
						//cout<<"start: "<<start<<" end: "<<end<<endl;
						height.push_back(node[cur].si);
						break;
					}
				}
				node[cur].ni--;
				node[cur].si += node[cur].delta_si;
				node[cur].wi += node[cur].delta_pi;
				node[cur].ei += node[cur].delta_pi;
				if(okay==true)
					res++;			
			}
			int len = v.size();
			for(int k=0; k<len; k++){
				int start = v[k].first;
				int end = v[k].second;
				for(int ii=start; ii<=end; ii++){
					wall[ii+offset] = max(wall[ii+offset], height[k]);
					if(ii != end)
						middle[ii+offset] = max(middle[ii+offset], height[k]);
				}
			}
		}
		cout<<"Case #"<<j<<": "<<res<<endl;
	}
	return 0;
}
