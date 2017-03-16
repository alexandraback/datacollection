#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

int main(){
	int t, a[110][110], b[110][110], n, m;
	cin >> t;
	for(int tc=1;tc<=t;tc++){
		cin >> n >> m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> a[i][j];
				b[i][j]=a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			int x=0;
			for(int j=0;j<m;j++)x=max(x,b[i][j]);
			for(int j=0;j<m;j++)b[i][j]=x;
		}
		for(int j=0;j<m;j++){
			int x=0;
			for(int i=0;i<n;i++)x=max(x,a[i][j]);
			for(int i=0;i<n;i++)b[i][j]=min(x,b[i][j]);
		}
		bool ret=true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]!=b[i][j]){
					ret=false;
					break;
				}
			}
			if(!ret)break;
		}
		printf("Case #%d: ",tc);
		if(ret)puts("YES");
		else puts("NO");
	}
	return 0;
}

