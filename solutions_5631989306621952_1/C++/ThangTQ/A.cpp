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

char s[2020], st[2020];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++)
	{
        printf("Case #%d: ", t);
        scanf("%s", &s);
        int N = strlen(s);
        int l = N, r = N;
        st[N] = s[0];
        for(int i=1; i<N; i++)
        {
            if (s[i] >= st[l])
            {
                st[--l] = s[i];
            } else
            {
                st[++r] = s[i];
            }
        }
        for(int i=l; i<=r; i++)
        {
            printf("%c", st[i]);
        }
        printf("\n");
	}
	return 0;
}
