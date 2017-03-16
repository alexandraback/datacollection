#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXS=1010;
char S[MAXS];
deque<char> deq;

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%s",S);
		deq.clear();
		deq.push_front(S[0]);
		for(int i=1;S[i];i++)
			if(S[i]>=deq[0])
				deq.push_front(S[i]);
			else
				deq.push_back(S[i]);
		printf("Case #%d: ",num_kase);
		for(int i=0;i<SZ(deq);i++)
			putchar(deq[i]);
		puts("");
	}
	return 0;
}
