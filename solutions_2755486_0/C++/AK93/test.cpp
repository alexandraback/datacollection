#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		int res=0;
		int n;
		cin>>n;
		vector<pair<int, pair<int, pair<int, int> > > > arr;
		arr.reserve(10000);
		for(int i=0; i<n; i++){
			int d, m, w, e, s, dd, dp, ds;
			cin>>d>>m>>w>>e>>s>>dd>>dp>>ds;
			for(int j=0; j<m; j++){
				arr.push_back(make_pair(d, make_pair(s, make_pair(w,e))));
				d+=dd;
				w+=dp;
				e+=dp;
				s+=ds;
			}
		}
		sort(arr.begin(), arr.end());
		vector<pair<int ,int> > mp(2001);
		int count=-1000;
		for(int i=0; i<2001; i++){
			mp[i].first=count++;
			mp[i].second=0;
		}
		int k=1000;
		for(int i=0; i<arr.size(); i++){
			int d, s, w, e;
			d=arr[i].first;
			s=arr[i].second.first;
			w=arr[i].second.second.first+k;
			e=arr[i].second.second.second+k;
			bool ch=true;
			for(int j=w; j<e; j++){
				if(mp[j].second < s){
					ch=false;
				}
			}
			if(!ch){
				for(int j=w; j<e; j++){
					if(mp[j].second < s){
						if(i != arr.size()-1){
							if(s == arr[i+1].second.first){
								mp[j].second = s-1;
							}
							else
								mp[j].second = s;
						}
					}
				}
				res++;
			}
		}
		printf("Case #%d: %d\n", t+1, res);
		
	}
	return 0;
}
