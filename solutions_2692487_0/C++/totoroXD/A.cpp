#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;
int n, a[111], s, cnt=0;

bool check(int k){
	bool ok=0;
	for(int r=n; max(n-k,0)<=r && !ok; r--){
		int d = k-(n-r), aa=s;
		//printf("d=%d\n",d);
		for(int i=0; i<r; i++){
			while(0<=d){
				//printf("aa=%d, a[%d]=%d\n",aa,i,a[i]);
				if(a[i]<aa){
					aa+= a[i];
					break;
				}
				else{
					d--;
					aa = aa*2-1;
				}
				//printf("aa=%d, d = %d\n",aa,d);
			}
			if(d<0)break;
		}
		if(0<=d)ok=1;
	}
	//printf("%d\n",ok);
	return ok;
}
void input(){
	cin>>s>>n;
	for(int i=0; i<n; i++)cin>>a[i];
}
void solve(){
	sort(a,a+n);
	//check(0);
	int lb=-1, ub=100;
	while(1<ub-lb){
		int md = (lb+ub)/2;
		if(check(md)){
			ub = md; // ub is answer
		}
		else lb = md;
	}
	printf("Case #%d: %d\n",++cnt,ub);
}
int main ()
{
	freopen("A-small-attempt0.in", "r",stdin);
	freopen("A-small-attempt0.out","w", stdout);
	int zz;
	cin>>zz;
	while(zz--){
		input();
		solve();
	}
	return 0;
}

/*
4
2 2
2 1
1 4
1 1 1 1
2 4
2 1 1 6
10 4
25 20 9 100
*/
