#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#define pb push_back
#define INF (1 << 28)
#define ll long long 
#define EPS (1e-9)
#define mp(x,y) make_pair(x,y)
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 0; i <= n; i++)



using namespace std;

int main(){
	int T;
	cin >> T;
	for(int Case = 1; Case <= T; Case++){
		int n;
		int a[1000], b[1000], rest[1000];
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			rest[i] = 2;
		}
		int star = 0;
		int step = 0;
		
		int high, pos;
		bool flag;
		while(star != n * 2){
			flag = true;
			for(int i = 0; i < n; i++){
				if(rest[i] && b[i] <= star){
					star += rest[i];
					rest[i] = 0;
					step++;
					flag = false;
				}
			}
			if(!flag)continue;
			int high = 0, pos = -1;
			for(int i = 0; i < n; i++){
				if(rest[i] == 2 && a[i] <= star){
					if(high < b[i]){
						high = b[i];
						pos = i;
					}
				}
			}
			
			if(pos != -1){
				star += 1;
				rest[pos] = 1;
				step++;
				flag = false;
			}
			if(flag)break;
		}
		cout << "Case #" << Case << ": ";
		if(flag)cout << "Too Bad" << endl;
		else cout << step << endl;
	}	
	return 0;
}

