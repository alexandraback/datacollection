//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
//============================================================================

#include <bits/stdc++.h>

#define ll long long

#define TEST int t;scan(t);while(t--)
#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define loop(i,l,r,x) for (int i=l;i<=r;i+=x)
#define printl(n) printf("%d\n",n)
#define print(n) printf("%d ",n)
#define pb push_back

#define INF 1000000000
#define M 1000000007
#define MAX 500001
#define LIM 10

using namespace std;

int n;
string a[20],b[20],c[20];
int mn;

int solve(int m[]){

	map<string,int> mp;
	int cn=0;
	for (int i=0;i<n;i++){
		if (m[i]==0) mp[c[i]] = 0;
		else{
			cn++;
			mp[c[i]] = 1;
		}
	}

	for (int i=0;i<n;i++){
		if (mp[c[i]]==0) continue;
		int f=0;

		for (int j=0;j<n;j++){
			if (mp[c[j]]==1) continue;
			for (int k=0;k<n;k++){
				if (mp[c[k]]==1) continue;
				string xx = a[j]+" "+b[k];

				if (xx==c[i]){
					f=1;
					break;
				}
			}
			if (f==1) break;
		}

		if (f==0) return 0;

	}
	mn = max(mn,cn);

	return 0;
}

int func(int i,int m[]){
	if (i==n){
		solve(m);
		return 0;
	}
	func(i+1,m);
	m[i] = 1;
	func(i+1,m);
	m[i]=0;
	return 0;
}

int init(){
	int cs=1;
	TEST{
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			c[i] = a[i]+" "+b[i];
		}
		mn=0;
		int m[100];
		set(m,0);
		func(0,m);
		cout << "Case #" << cs++ << ": " ;
		cout << mn;
		cout << endl;
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	init();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}

