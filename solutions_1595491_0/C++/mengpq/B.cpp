#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=127;
const int INF=0x7FFFFFFF;
const double eps=1e-10;
const double pi=acos(-1.0);

int N,S,p,ca;
int point[MAXN];
int f[MAXN][MAXN];

void init(){
	cin>>N>>S>>p;
	for (int i=1; i<=N; i++) cin>>point[i];
}

int getP1(int value){
	if (value%3==0) return value/3;
	if (value>=1 && (value-1)%3==0){
		return (value-1)/3+1;
	}
	if (value>=2 && (value-2)%3==0){
		return (value-2)/3+1;
	}
	return -1;
}

int getP2(int value){
	if (value>=2 && (value-2)%3==0){
		return (value-2)/3+2;
	}
	if (value>=3 && (value-3)%3==0){
		return (value-3)/3+2;
	}
	if (value>=4 && (value-4)%3==0){
		return (value-4)/3+2;
	}
	return -1;
}

void solve(){
	memset(f,0,sizeof(f));
	for (int j=0; j<=S; j++)
		for (int i=1; i<=N; i++){
			if (getP1(point[i])!=-1)
				f[i][j]=max(f[i][j],f[i-1][j]+(int)(getP1(point[i])>=p));
			if (j>0 && getP2(point[i])!=-1)
				f[i][j]=max(f[i][j],f[i-1][j-1]+(int)(getP2(point[i])>=p));
		}
	cout<<f[N][S]<<endl;
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>ca;
	for (int i=0; i<ca; i++){
		cout<<"Case #"<<i+1<<": ";
		init();
		solve();
	}
	return 0;
}



