#include<cstdio>
#include<algorithm>

using namespace std;

int casos, a, b, k, res;

int main(){
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		res = 0;
		scanf(" %d %d %d", &a, &b, &k);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i&j) < k) res++;
		printf("Case #%d: %d\n", inst, res);
	}
	return 0;
}