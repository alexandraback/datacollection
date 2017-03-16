/*
 * totoroXD
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int INF = 1011110000, MOD=1000000000;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
const double EPS = 1e-6;

int n, kase=1;
double num[2][1111];
int anum[2][1111];

bool input(){
	cin>>n;
	for(int k=0; k<2; k++)
		for(int i=0; i<n; i++)
			scanf("%lf",&num[k][i]);
	return 1;
}
void solve(){
	sort(num[0], num[0]+n);
	sort(num[1], num[1]+n);
	vector<double> vv;
	for(int k=0; k<2; k++)
		for(int i=0; i<n; i++)
			vv.push_back(num[k][i]);
	sort(vv.begin(), vv.end());
	map<double,int> mp;
	for(int i=0; i<vv.size(); i++)
		mp[vv[i]] = i;
	for(int k=0; k<2; k++)
		for(int i=0; i<n; i++)
			anum[k][i] = mp[num[k][i]];/*
	for(int k=0; k<2; k++){
		for(int i=0; i<n; i++)
			printf("%d ",anum[k][i]);
		printf("\n");
	}*/
	int resa=0, resb=0;
	for(int i=0,j=0; i<n; i++){
		if(anum[0][i]>anum[1][j]){
			resa++;
			j++;
		}
	}
	for(int i=0,j=0; i<n; i++){
		if(anum[1][i]>anum[0][j]){
			resb++;
			j++;
		}
	}
	printf("Case #%d: %d %d\n",kase++,resa,n-resb);
}
void pre(){
}
int main(){
	pre();
    int zz=1;
    cin>>zz;
    while(zz--){
    	input();
    	solve();
    }
    return 0;
}

/*

4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458

*/

