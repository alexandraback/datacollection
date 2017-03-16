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

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int p=0; p<t; p++){
		int n,m;
		cin>>n>>m;
		vector<vector<pair<int, bool> > > arr(n, vector<pair<int, bool> > (m, make_pair(100, false)));
		set<int> zn;
		int mx=-1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &arr[i][j].first);
				zn.insert(arr[i][j].first);
				mx=max(mx, arr[i][j].first);
			}
		}
		vector<vector<int> > buf(n, vector<int> (m, mx));
		
		bool res=false;
		for(set<int>::reverse_iterator it=zn.rbegin(); it!=zn.rend(); it++){
			int x=*it;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(!arr[i][j].second && arr[i][j].first == x){
						if(buf[i][j] == x)
							arr[i][j].second=true;
						else{
							vector<vector<int> > buf2=buf;
							bool ch1=false, ch2=false;
							for(int k=0; k<n; k++){
								if(!arr[k][j].second)
									buf[k][j]=x;
								else{
									if(arr[k][j].first == x){
										buf[k][j]=x;
									}
									else{
										ch1=true;
										break;
									}
								}
							}
							if(!ch1){
								arr[i][j].second;
								continue;
							}

							buf=buf2;
							for(int k=0; k<m; k++){
								if(!arr[i][k].second)
									buf[i][k]=x;
								else{
									if(arr[i][k].first == x){
										buf[i][k]=x;
									}
									else{
										ch2=true;
										break;
									}
								}
							}
							if(!ch2){
								arr[i][j].second;
							}
							if(ch1 && ch2){
								res=true;
								break;
							}
						}
					}
				}
				if(res)
					break;
			}
			if(res)
				break;
		}
		printf("Case #%d: ", p+1);
		if(res)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}