#include <cstdio>
#include <cstring>
#include <cstring>
#include <map>
using namespace std;
int T, A, B, ans;
map<int, bool> hsh;
int length(int x){
	int ret= 0;
	while(x){
		x/= 10;
		++ ret;
	}
	return ret;
}
int main(){
	scanf("%d", &T);
	for(int t= 1;t<= T;++ t){
		ans= 0;
		scanf("%d%d", &A, &B);
		for(int i= A;i<= B;++ i){
			int len= length(i), mul= 1;
			for(int j= 1;j< len;++ j)
				mul*= 10;
			hsh.clear();
			for(int j= 1, s= i;j< len;++ j){
				s= ((s%10)*mul) + s/10;
				if(i<s && s<=B && !hsh[s]){
//					printf("%d %d\n", s, i);
					hsh[s]= 1;
					++ ans;
				}
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
