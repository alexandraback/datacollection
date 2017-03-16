#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void decomp(int x,int &S) {

}

int main() {
	int T,N;
	cin>>T;
	for (int loop = 1; loop<=T; ++loop) {
		cin>>N;
        printf("Case #%d: ",loop);
        if (N==0) {
            printf("INSOMNIA\n");
            continue;
        }
        int S = 0,X = N;
		for (;; X += N) {
            int x = X;
            while (x>0) {
                S |= 1<<(x%10);
                x /= 10;
            }
            if (S==(1<<10)-1) break;
		}
        printf("%d\n",X);
	}
	return 0;
}
