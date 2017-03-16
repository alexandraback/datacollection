#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a, _b = b; i <= _b; i++)
using namespace std;
int main(){
	int T, t = 0; scanf("%d",&T);
	while (T--){
		t++; printf("Case #%d: ",t);
		int a, b, c, k; scanf("%d%d%d%d",&a,&b,&c,&k);
		cout <<a * b * min(c, k)<<endl;
		rep(i,0,a - 1)
			rep(j,0,b - 1)
				rep(t,0,min(c, k) - 1)
					cout <<i + 1<<' '<<j + 1<<' '<<(i + j + t) % c + 1<<endl;
	}
}