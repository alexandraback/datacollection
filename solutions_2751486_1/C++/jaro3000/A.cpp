#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<complex>
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)
// #define dprintf(...)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}

#define N 1000004
char buffer[N];
int next[N];
LL cnt[N];

void main2(int C) 
{
	int n,k;
	scanf("%s %d", buffer, &k);
	n=strlen(buffer);
	int first=n;
	for(int i=n-1; i>=0; --i)
	{
		if(buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i]
				== 'o' || buffer[i] == 'u')
		{
			first = i;
		}
		next[i]=first;
		cnt[i]=0;
	};
	cnt[n]=0;

	for(int i=n-1; i>=0; --i)
	{
		if(next[i] == i)
		{
			cnt[i] = cnt[i+1];
		} else {
			if(next[i] - i >= k){
				cnt[i] = n - i - k + 1;
			}else cnt[i] = cnt[i+1];
		};
	}
	LL cc = 0;
	for(int i=0; i<n; ++i)
		cc+=cnt[i];
	printf("Case #%d: %lld\n", C, cc);
};

int main() {
	int T;
	scanf("%d", &T);
	for(int C=1; C<=T; ++C) main2(C);

	return 0;
}

