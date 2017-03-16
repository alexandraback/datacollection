#include <cstdio>

using namespace std;

int N;
int t,r;

char testc() {
	int a = 1;
	scanf("%d %d",&r,&t);
	t -= (r+1)*(r+1)-r*r;
	while(t>0) {
		r+=2;
		t -= (r+1)*(r+1)-r*r;
		if(t>=0) a++;
	}
	return a;
}

int main() {
	scanf("%d\n",&N);
	for(int n=0;n<N;n++) {
		char a = testc();
		printf("Case #%d: %d\n",n+1,a);
	}

}