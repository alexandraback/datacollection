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

vector<pair<int, int> > s;

void rec(int v, pair<int, int> bufs){
	if(v == 0){
		s.push_back(bufs);
		return;
	}
	bufs.first++;
	rec(v-1, bufs);
	bufs.first--;
	bufs.second++;
	rec(v-1, bufs);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<int> bf;
	bf.push_back(1);
	for(int i=0; i<1000; i++){
		bf.push_back(bf[i]+4);
	}
	vector<int> pr;
	pr.push_back(1);
	for(int i=0; i<bf.size()-1; i++){
		pr.push_back(pr[i]+bf[i+1]);
	}
	int t;
	cin>>t;
	for(int p=0; p<t; p++){
		int n,x,y;
		cin>>n>>x>>y;
		double res;
		int maxx=0, maxy=0, minx=0;
		int i;
		for(i=0; i<pr.size(); i++){
			if(pr[i] >= n){
				if(i == 0)
					break;
				maxx=i*2;
				minx=-i*2;
				maxy=maxx;
				n = n-pr[i-1];
				break;
			}
		}
		if(x <= maxx-2 && x >= minx+2 && y <= maxy-2){
			res=1;
		}
		else{
			if(x >= maxx+2 || x <= minx-2 || y >= maxy+2)
				res=0;
			else{
				int bx = abs(x);
				if(bx+y > maxx+2)
					res=0;
				else{
					int kol = bf[i];
					if(n == kol)
						res=1;
					else{
						int mid = (kol-1)/2;
						if(n > mid+y)
							res=1;
						else{
							if(x == 0 && y == maxy)
								res=0;
							else{
								s.clear();
								rec(n,make_pair(0,0));
								int count=0;
								if(x < 0){
									for(int j=0; j<s.size(); j++){
										int l = s[j].first;
										int zx=minx;
										while(l--)
											zx++;
										if(x < zx)
											count++;
									}
								}
								else{
									for(int j=0; j<s.size(); j++){
										int l = s[j].second;
										int zx=maxx;
										while(l--)
											zx--;
										if(x > zx)
											count++;
									}
								}
								res=(double)count/s.size();
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %.7lf\n", p+1, res);
	}
	return 0;
}