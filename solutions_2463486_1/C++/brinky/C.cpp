#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<long long> pre;

int t[101];
char buf[100];

int main(){
	t[0] = 1;
	for(int i=1; i<=100; ++i)
		t[i] = t[i-1] * 10;
	for(int k=1; k<=9; ++k){
		int l = (k+1)/2;
		for(int p=t[l-1]; p<t[l]; ++p){
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "%d", p);
			for(int i=0; i<l; ++i)
				buf[k-1-i] = buf[i];
			long long pal = atoll(buf);
			pal *= pal;
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "%lld", pal);
			int s = strlen(buf);
			for(int i=0; i<s; ++i)
				if(buf[i] != buf[s-1-i])
					goto next;
			pre.push_back(pal);
next:
		;
		}
	}
	int tc, tcn;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		printf("Case #%d: ", tc+1);
		long long a, o;
		scanf("%lld %lld", &a, &o);
		long long d = upper_bound(pre.begin(), pre.end(), o) - lower_bound(pre.begin(), pre.end(), a);
		printf("%lld\n", d);
	}
}
