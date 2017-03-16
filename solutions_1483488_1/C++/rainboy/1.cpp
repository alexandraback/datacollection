#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
map < int , int > Map;
int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int T;
	scanf("%d\n", &T);
	for (int tt=1;tt<=T;tt++){
		int A,B;
		scanf("%d %d\n", &A, &B);
		int ret=0;
		int t=1;
		for (int i=A;i<=B;i++){
			int x=10,k=i;
			while (t<k) t*=10;
			Map.clear();
			while (x<k){
				int y;
				y=(k%x)*(t/x)+k/x;
				Map[y]++;
				if (y>k && y<=B && Map[y]==1){
					ret++;
				}
				x*=10;
			}
		}
		printf("Case #%d: %d\n", tt, ret);
	}
	return 0;
}
