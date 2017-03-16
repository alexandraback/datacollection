#include <bits/stdc++.h>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

typedef pair<int,int> pii;
typedef map<int,int> bstii;
typedef set<int> bsti;

const int M = 2500;

int cnt[M+10];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int k=1; k<=T; k++)
	{
        printf("Case #%d:", k);
        memset(cnt, 0, sizeof(cnt));
        int N; scanf("%d", &N);
        for(int i=1; i<2*N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                int u; scanf("%d", &u);
                cnt[u]++;
            }
        }
        for(int i=1; i<=M; i++)
        {
            if (cnt[i]&1)
            {
                printf(" %d", i);
            }
        }
        printf("\n");
	}
	return 0;
}
