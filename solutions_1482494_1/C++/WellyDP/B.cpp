#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>


using namespace std;

bool cmp1(pair <int, ii > a, pair<int, ii > b) {
	return a.second.first<b.second.first;
}

bool cmp2(pair <int, ii > a, pair<int, ii > b) {
	return a.second.second>b.second.second;
}

int flag[1005];

int main() {
	int ntc,n,a,b;
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d",&n);
		vector <pair <int, ii > > vec1,vec2;
		memset(flag,0,sizeof(flag));
		int point=0;
		int res=0;
		for (int i=0;i<n;i++) {
			scanf("%d %d",&a,&b);
			if (a==0 && b==0) {
				point+=2; flag[i]=2; res++;	
			}
				//vec1.push_back(make_pair(i,make_pair(a,b)));	
				vec2.push_back(make_pair(i,make_pair(a,b)));	
			
		}
		//sort(vec1.begin(),vec1.end(),cmp1);
		sort(vec2.begin(),vec2.end(),cmp2);
		for (int i=0;i<n*2;i++) {
			bool ada=false;
			for (int j=0;j<n;j++) {
				//printf(">> %d %d<=%d %d\n",i,vec2[j].second.second, point,flag[vec2[j].first]);
				if (flag[vec2[j].first]==2) continue;
				if (vec2[j].second.second<=point) {
					if (flag[vec2[j].first]==1) {point++; flag[vec2[j].first]=2;}
					else {point+=2; flag[vec2[j].first]=2;}
					ada=true;	
					res++; break;
				}	
			}
			if (!ada) {
				for (int j=0;j<n;j++) {
					if (flag[vec2[j].first]>=1) continue;
					if (vec2[j].second.first<=point) {
						flag[vec2[j].first]=1; point++;
						ada=true;
						res++;	break;
					}	
				}	
			}
			if (!ada) {break;}
		}
		
		if (point==n*2) printf("Case #%d: %d\n",tc,res);
		else printf("Case #%d: Too Bad\n",tc);
	
	}
    return 0;
}
