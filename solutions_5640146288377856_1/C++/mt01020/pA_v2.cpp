#include<cstdio>
using namespace std;

int main(){
    int T;
    int R, C, W;
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	scanf(" %d %d %d ", &R, &C, &W);
	int res = W + (C / W - 1);
	if(C % W != 0)	++res;
	res += ((C/W)*(R-1));
	printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
