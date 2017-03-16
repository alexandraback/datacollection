#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int testnum = 1; testnum <= T; testnum++)
    {
	int N, S, P;
	scanf("%d%d%d", &N, &S, &P);

	int ans = 0;
	for(int i = 0; i < N; i++)
	{
	    int v;
	    scanf("%d", &v);

	    if(v >= P * 3 - 2)
		ans++;
	    else if(v && v >= P * 3 - 4)
		ans += (S-- > 0);
	}

	if(P == 0)
	    ans = N;

        printf("Case #%d: %d\n", testnum, ans);
    }
    return 0;
}
