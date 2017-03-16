#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

vector<double> a,b;
bool f[1100];
int N;

int resA(){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int la=0,ra=N-1;
	int lb=0,rb=N-1;
	int cnt=0;
	for (;la<=ra;){
		if (a[la]<b[lb]){
			la++;rb--;
		}
		else if (a[ra]<b[rb]){
			la++;rb--;
		}
		else if (a[la]>b[lb]){
			la++;lb++;cnt++;
		}
		else {
			cnt+=a[ra]>b[lb];
			ra--;lb++;
		}
	}
	return cnt;
}

int resB(){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int cnt=0;
	memset(f,false,sizeof(f));
	for (int i=0;i<N;i++){
		int z=-1;
		for (int j=0;j<N;j++) if (!f[j]){
			if (z==-1) z=j;
			if (b[z]<a[i]&&b[j]>a[i]) z=j;
		}
		cnt+=a[i]>b[z];
		f[z]=true;
	}
	return cnt;
}

int main(int argc,char** argv){
	int T;
	cin>>T;
	for (int r=1;r<=T;r++){
		scanf("%d",&N);
		a.clear();
		for (int i=0;i<N;i++){
			double t;
			scanf("%lf",&t);a.PB(t);
		}
		b.clear();
		for (int i=0;i<N;i++){
			double t;
			scanf("%lf",&t);b.PB(t);
		}
		printf("Case #%d: %d %d\n",r,resA(),resB());
	}
	return 0;
}