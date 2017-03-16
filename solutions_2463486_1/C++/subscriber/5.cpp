#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

string h[46228];

int main(){
	freopen("base.txt","r",stdin);	
	for (int i=0;i<46228;i++)cin >> h[i];
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		string A,B;
		cin >> A >> B;
		int ans=0;
		for (int i=0;i<46228;i++){
			if (h[i].size()<A.size()||h[i].size()==A.size()&&h[i]<A)continue;
			if (h[i].size()>B.size()||h[i].size()==B.size()&&h[i]>B)continue;
			ans++;
		}
		cout << "Case #" << E << ": " << ans << endl;
	}
	return 0;
}

