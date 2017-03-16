#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	freopen("B-small-attempt0.in.txt","r",stdin);
	freopen("B-small-attempt0.out.txt","w",stdout);
	int T,pid=1;
	for (cin>>T;T--;) {
		printf("Case #%d: ",pid++);
        int A, B, K;
        scanf("%d %d %d",&A,&B,&K);
        int cnt=0;
        for (int i = 0; i < A;++i) {
            for (int j=0;j<B;++j){
                unsigned int tmp=i&j;
                if (tmp < K) cnt++;
            }
        }
        printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}